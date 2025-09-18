#include "binary.h"
#include <string.h>

int convert(const char *input){
    int value = 0;
    for(size_t i = 0; i < strlen(input); i++)
        if(input[i] != '0' && input[i] != '1')
            return INVALID;
        else
            value = 2 * value + (input[i] - '0');
    return value;
}