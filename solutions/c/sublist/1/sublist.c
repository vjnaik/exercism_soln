#include "sublist.h"

comparison_result_t check_lists(int *a_list, int *b_list,
                                size_t a_count,
                                size_t b_count) {
    unsigned char sublist = a_count <= b_count;
    
    int *smaller = sublist ? a_list : b_list;
    int *greater = sublist ? b_list : a_list;

    size_t min_count, max_count;
    _get_min_max(a_count, b_count, &min_count, &max_count);
    
    for (size_t i = 0; i <= max_count - min_count; i++) {
        if(memcmp(smaller, &greater[i], min_count * sizeof *smaller) == 0){
            if (min_count == max_count) { return EQUAL; }
            if (sublist) { return SUBLIST; }
            return SUPERLIST;
        }
    }
    
    return UNEQUAL;
}