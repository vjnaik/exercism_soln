#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes){
    uint32_t count = 0;
    
    if (limit < 2) return count; // No primes below 2
    
    uint32_t *marked = calloc(limit + 1, sizeof(uint32_t));
    
    if (marked == NULL) return -1; // Error: No memory
    
    for (uint32_t x = 2; x <= limit; x++){
        if (count == max_primes) break; // Max primes reached
        
        if (marked[x]) continue; // Skip marked values
        
        primes[count++] = x; // Non-marked is prime
        
        for (size_t i = x; i <= limit; i += x)
            marked[i] = 1; // Mark all multiples
    }
    
    free(marked);
    
    return count;
}