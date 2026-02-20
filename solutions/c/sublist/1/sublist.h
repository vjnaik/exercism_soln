#ifndef SUBLIST_H
#define SUBLIST_H

#include <string.h>
#include <stddef.h>

typedef enum { EQUAL, UNEQUAL, SUBLIST, SUPERLIST } comparison_result_t;

static inline void _get_min_max(size_t a, size_t b, size_t *min, size_t *max) {
    if (a > b) { *min = b; *max = a; }
    else { *min = a; *max = b; }
}

comparison_result_t check_lists(int *a_list, int *b_list,
                                size_t a_count,
                                size_t b_count);

#endif