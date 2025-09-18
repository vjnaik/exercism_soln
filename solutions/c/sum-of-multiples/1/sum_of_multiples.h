#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

typedef unsigned int uint;

uint sum(const uint *factors, const size_t number_of_factors,
                 const uint limit);

#endif