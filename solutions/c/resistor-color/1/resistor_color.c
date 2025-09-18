#include "resistor_color.h"
#include <stdlib.h>

int color_code(resistor_band_t col){
    return (int)col;
}

const resistor_band_t *colors(void){
    resistor_band_t *list = malloc(sizeof(resistor_band_t)*10);
    for(int i = 0; i < 10; i++){
        *(list + i) = (resistor_band_t)i;
    }
    return list;
}