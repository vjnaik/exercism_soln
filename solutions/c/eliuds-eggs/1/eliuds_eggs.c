#include "eliuds_eggs.h"

unsigned int egg_count(const unsigned int value){
    unsigned int count = 0, val = value;
    while(val){
        count += val % 2;
        val /= 2;
    }
    return count;
}