#include "grains.h"
#include <limits.h>

uint64_t square(uint8_t index){
    return (index > 0 && index < 65) ? (uint64_t)1 << (index - 1) : 0;
}
uint64_t total(void){
    return ULLONG_MAX ; //:D
}