#include "zebra_puzzle.h"

/* names of the nationalities */
const char* natName[5] = {
    "Englishman",
    "Spaniard",
    "Ukrainian",
    "Norwegian",
    "Japanese"
};
/* pos[cat][item] = house index 0..4, or -1 if unassigned */
static int pos[CAT][N];
/* used[cat] bitmask of houses already taken in that category */
static int used[CAT];

static int abs_i(int x) { return x < 0 ? -x : x; }

static inline int P(int cat, int item) { return pos[cat][item]; }

static int eq_ok(int a, int b) {
    if (a == -1 || b == -1) return 1;
    return a == b;
}
static int nextto_ok(int a, int b) {
    if (a == -1 || b == -1) return 1;
    return abs_i(a - b) == 1;
}

// right == left + 1
static int right_of_ok(int right, int left) {
    if (right != -1 && left != -1) return right == left + 1;
    if (right != -1) return right != 0;      /* can't be first */
    if (left  != -1) return left  != N - 1;  /* can't be last  */
    return 1;
}

static int constraints_ok(void) {
    if (!eq_ok(P(C_NAT, ENGLISHMAN), P(C_COL, RED))) return 0; /*2*/
    if (!eq_ok(P(C_NAT, SPANIARD),   P(C_PET, DOG))) return 0; /*3*/
    if (!eq_ok(P(C_DRINK, COFFEE),   P(C_COL, GREEN))) return 0; /*4*/
    if (!eq_ok(P(C_NAT, UKRAINIAN),  P(C_DRINK, TEA))) return 0; /*5*/
    if (!right_of_ok(P(C_COL, GREEN), P(C_COL, IVORY))) return 0; /*6*/
    if (!eq_ok(P(C_HOB, DANCE), P(C_PET, SNAIL))) return 0; /*7*/
    if (!eq_ok(P(C_HOB, PAINT),    P(C_COL, YELLOW))) return 0; /*8*/

    { /* 9: Milk in middle (house 2) */
        int m = P(C_DRINK, MILK);
        if (m != -1 && m != 2) return 0;
    }
    { /* 10: Norwegian in first (house 0) */
        int n = P(C_NAT, NORWEGIAN);
        if (n != -1 && n != 0) return 0;
    }

    if (!nextto_ok(P(C_HOB, READ), P(C_PET, FOX))) return 0;   /* 11 */
    if (!nextto_ok(P(C_HOB, PAINT), P(C_PET, HORSE))) return 0; /* 12 */
    if (!eq_ok(P(C_HOB, FOOTBALL), P(C_DRINK, ORANGE_JUICE))) return 0; /* 13 */
    if (!eq_ok(P(C_NAT, JAPANESE), P(C_HOB, CHESS))) return 0;  /* 14 */
    if (!nextto_ok(P(C_NAT, NORWEGIAN), P(C_COL, BLUE))) return 0;  /* 15 */
    return 1;
}

static void invert_cat(int cat, int atHouse[N]) {
    for (int item = 0; item < N; item++) {
        int h = pos[cat][item];
        atHouse[h] = item;
    }
}

/* Count how many houses are feasible for a variable right now */
static int count_domain(const Var *v) {
    int cat = v->cat, item = v->item;
    if (pos[cat][item] != -1) return 0; /* already assigned */

    int count = 0;
    for (int h = 0; h < N; h++) {
        if (used[cat] & (1 << h)) continue;

        /* enforce absolute clues early */
        if (cat == C_NAT && item == NORWEGIAN && h != 0) continue;
        if (cat == C_DRINK && item == MILK && h != 2) continue;

        pos[cat][item] = h;
        used[cat] |= (1 << h);

        if (constraints_ok()) count++;

        used[cat] &= ~(1 << h);
        pos[cat][item] = -1;
    }
    return count;
}

/* Forward-check: every unassigned variable has at least one feasible value */
static int forward_check(const Var vars[], int varCount) {
    for (int i = 0; i < varCount; i++) {
        int cat = vars[i].cat, item = vars[i].item;
        if (pos[cat][item] != -1) continue;
        if (count_domain(&vars[i]) == 0) return 0;
    }
    return 1;
}

/* Select unassigned variable with MRV (smallest domain > 0) */
static int select_mrv(const Var vars[], int varCount) {
    int best = -1;
    int bestDom = 999;

    for (int i = 0; i < varCount; i++) {
        int cat = vars[i].cat, item = vars[i].item;
        if (pos[cat][item] != -1) continue;

        int dom = count_domain(&vars[i]);
        if (dom == 0) return -2; /* dead end right now */
        if (dom < bestDom) {
            bestDom = dom;
            best = i;
            if (bestDom == 1) break; /* can't do better */
        }
    }
    return best; /* -1 means everything assigned */
}

static long long nodes = 0;

/* MRV backtracking */
static int solve_mrv(const Var vars[], int varCount) {
    nodes++;

    if (!constraints_ok()) return 0;

    int pick = select_mrv(vars, varCount);
    if (pick == -1) return 1;   /* all assigned */
    if (pick == -2) return 0;   /* some var has 0 domain */

    int cat = vars[pick].cat, item = vars[pick].item;

    for (int h = 0; h < N; h++) {
        if (used[cat] & (1 << h)) continue;

        if (cat == C_NAT && item == NORWEGIAN && h != 0) continue;
        if (cat == C_DRINK && item == MILK && h != 2) continue;

        pos[cat][item] = h;
        used[cat] |= (1 << h);

        if (constraints_ok() && forward_check(vars, varCount)) {
            if (solve_mrv(vars, varCount)) return 1;
        }

        used[cat] &= ~(1 << h);
        pos[cat][item] = -1;
    }
    return 0;
}

solution_t solve_puzzle(void) {
    solution_t solved;
    solved.drinks_water = NULL;
    solved.owns_zebra = NULL;
    /* Init */
    for (int c = 0; c < CAT; c++) {
        used[c] = 0;
        for (int i = 0; i < N; i++) pos[c][i] = -1;
    }

    /* Pre-assign absolute clues */
    pos[C_NAT][NORWEGIAN] = 0; used[C_NAT] |= (1 << 0);
    pos[C_DRINK][MILK]    = 2; used[C_DRINK] |= (1 << 2);

    /* All variables (25). Preassigned ones are fine; solver will skip them. */
    Var vars[CAT * N];
    int k = 0;
    for (int item = 0; item < N; item++) vars[k++] = (Var){C_NAT,   item};
    for (int item = 0; item < N; item++) vars[k++] = (Var){C_COL,   item};
    for (int item = 0; item < N; item++) vars[k++] = (Var){C_DRINK, item};
    for (int item = 0; item < N; item++) vars[k++] = (Var){C_HOB, item};
    for (int item = 0; item < N; item++) vars[k++] = (Var){C_PET,   item};

    if (!solve_mrv(vars, k)) return solved;

    int natAt[N], colAt[N], drinkAt[N], hobbyAt[N], petAt[N];
    invert_cat(C_NAT, natAt);
    invert_cat(C_COL, colAt);
    invert_cat(C_DRINK, drinkAt);
    invert_cat(C_HOB, hobbyAt);
    invert_cat(C_PET, petAt);

    int waterHouse = P(C_DRINK, WATER);
    int zebraHouse = P(C_PET, ZEBRA);
    solved.drinks_water = natName[natAt[waterHouse]];
    solved.owns_zebra = natName[natAt[zebraHouse]];
    // strcpy(solved.drinks_water, natName[natAt[waterHouse]]);
    // strcpy(solved.owns_zebra, natName[natAt[zebraHouse]]);
    return solved;
}