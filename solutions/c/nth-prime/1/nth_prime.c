#include "nth_prime.h"

const uint32_t MAX_VALUE = 1000000;

uint32_t nth(uint32_t n) {
    if (n == 0) return 0;  // There is no zeroth prime

    size_t array_size = 1;
    uint32_t result = 2, *prime_array = malloc(sizeof(uint32_t) * n);
    if (prime_array == NULL) return -1; // Can't allocate array
    
    *prime_array = result;
    
    if (n == 1) return result; // Return first prime
    
    for (uint32_t i = 3; i < MAX_VALUE; i++) {
        uint8_t isComp = 0;
        size_t index = 0;
        while (index < array_size) {
            if (i % *(prime_array + index) == 0) {
                isComp = 1;
                break;
            }
            index++;
        }
        if (isComp == 0) {
            *(prime_array + array_size) = i;
            array_size++;
            if (array_size == n) break;
        }
    }
    result = *(prime_array + array_size - 1);
    
    free(prime_array);
    prime_array = NULL;
    
    return result;
}