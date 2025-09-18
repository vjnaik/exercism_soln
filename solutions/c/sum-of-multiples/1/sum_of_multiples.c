#include "sum_of_multiples.h"

uint sum(const uint *fac, const size_t num_fac, const uint lim){
    uint add = 0;
    bool *muples = calloc(lim, sizeof(bool));

    for(size_t i = 0; i < num_fac; i++) {
        if(fac[i] == 0) continue;
        if(fac[i] >= lim) continue;
        for(uint j = fac[i]; j < lim; j += fac[i]) {
            if(*(muples + j) == false) {
                add += j;
                *(muples + j) = true;
            }
        }
    }
    free(muples);
    return add;
}