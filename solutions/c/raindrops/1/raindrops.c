#include "raindrops.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {BUFFER = 16};

void convert(char result[], int drops){
    char *value = malloc(sizeof(char) * 4);
    if(value == NULL){
        fprintf(stderr, "Unable to allocate storage\n");
        exit(1);
    }
    sprintf(value, "%d", drops);
    strncpy(result,(drops % 105 == 0) ? "PlingPlangPlong" :
                   (drops % 35 == 0)  ? "PlangPlong"      :
                   (drops % 21 == 0)  ? "PlingPlong"      :
                   (drops % 15 == 0)  ? "PlingPlang"      :
                   (drops % 7 == 0)   ? "Plong"           :
                   (drops % 5 == 0)   ? "Plang"           :
                   (drops % 3 == 0)   ? "Pling"           :
                                        value, BUFFER);
    free(value);
    value = NULL;
}