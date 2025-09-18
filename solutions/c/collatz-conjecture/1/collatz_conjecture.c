#include "collatz_conjecture.h"
#include <stdio.h>

int steps(int start){
    int count = 0, temp = start;
    if(start <= 0)
        return ERROR_VALUE;
    while(temp != 1){
        temp = (temp % 2) ? 3 * temp + 1: temp / 2;
        count++;
    }
    return count;
}