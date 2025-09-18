#include "perfect_numbers.h"
#include <stdio.h>

kind classify_number(int num){
    int aliquot = 1;
    if(num <= 0) return -1;
    for(int j = 2; j <= num/2; j++)
        if(num % j == 0)
            aliquot += j;
    if(aliquot == 1) return DEFICIENT_NUMBER;
    return (num == aliquot) ? PERFECT_NUMBER :
           (num > aliquot) ? DEFICIENT_NUMBER :
                             ABUNDANT_NUMBER;
}