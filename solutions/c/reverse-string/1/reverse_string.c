#include "reverse_string.h"

char *reverse(const char *value){
    size_t len = strlen(value) ;
    char *output = calloc(len + 1, sizeof(char));
    
    for (size_t i = 0; i < len; i++)
        *(output + i) = *(value + len - 1 - i);
    
    return output;
}