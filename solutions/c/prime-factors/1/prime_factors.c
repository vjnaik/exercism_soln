#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]){
    size_t count = 0;
    uint32_t fac = 2;
    
    while (n > 1) {
        if (n % fac == 0) {
            factors[count++] = fac;
            n /= fac;
            fac = 2;
            continue;
        }
        if (fac == n) {
            factors[count++] = fac;
            break;
        }
        fac++;
    }
    
    return count;
}