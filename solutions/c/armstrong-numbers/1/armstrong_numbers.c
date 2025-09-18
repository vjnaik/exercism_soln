#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate){
    int exponent = 0, temp = candidate;
    int digits[10] = {0}, i = 0;
    int armstrong = 0;
    if(temp == 0) return true; // special case
    while(temp){
        digits[i++] = temp % 10;
        temp = temp/10;
        exponent++;
    }
    for(i = 0; i < 10; i++)
        armstrong = armstrong + pow(digits[i], exponent); 
    return armstrong == candidate;
}