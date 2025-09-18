#include "darts.h"
#include <math.h>

unsigned int score(coordinate_t loc){
    float distance = hypot(loc.a, loc.b);
    //Never use direct equality on floats SMH!!
    return distance < 1.01 ? 10 : distance < 5.01 ? 5 : distance < 10.01 ? 1 : 0; 
}