#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t a[]){
    resistor_value_t test;
    test.unit = OHMS;
    test.value = (a[0] * 10 + a[1]) * pow(10,a[2]);
    while(test.value > 1000){
        test.unit++;
        test.value /= 1000;
    }
    return test;
}