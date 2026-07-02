#include "grade_school.h"

void init_roster(roster_t *roster) {
    roster->count = 0;
}

static bool is_dup(const roster_t *roster, const char *name) {
    for (size_t i = 0; i < roster->count; i++) {
        if (!strcmp(roster->students[i].name, name))
            return true;
    }
    return false;
}

static int comparator(const void * a, const void * b) {
    student_t *c = (student_t *) a;
    student_t *d = (student_t *) b;
    if (c->grade != d->grade) {
        return c->grade - d->grade;
    } else {
        return strcmp(c->name, d->name);
    }
}

bool add_student(roster_t *roster, const char *name, uint8_t grade) {
    if (is_dup(roster, name)) { return false; }

    strcpy(roster->students[roster->count].name, name);
    roster->students[roster->count].grade = grade;
    roster->count++;

    qsort(roster->students, roster->count, sizeof(student_t), comparator);
    return true;
}

roster_t get_grade(const roster_t *roster, uint8_t grade) {
    roster_t grade_roster = {0};
    
    if (roster->count == 0) { return grade_roster; }
    else {
        for (size_t i = 0; i < roster->count; i++) {
            if (roster->students[i].grade == grade) {
                grade_roster.students[grade_roster.count] = roster->students[i];
                grade_roster.count++;
            }
        }
    }
    return grade_roster;
}