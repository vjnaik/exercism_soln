#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len){
    return *(scores + scores_len - 1);
}

int32_t personal_best(const int32_t *scores, size_t scores_len){
    int32_t best = *scores;
    for(size_t i = 0; i < scores_len; i++)
        if(*(scores + i) > best) best = *(scores + i);
    return best;
}

int _compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output){
    size_t size = (scores_len > 3) ? 3 : scores_len;
    int32_t* temp = malloc(sizeof(int32_t)*scores_len);
    
    if(temp == NULL) return -1;
    
    for(size_t i = 0; i < scores_len; i++)
        *(temp + i) = *(scores + i);
    
    qsort(temp, scores_len, sizeof(int32_t), _compare);
    
    for(size_t i = 0; i < size; i++)
        *(output + i) = *(temp + i);
    
    free(temp);
    
    return size;
}