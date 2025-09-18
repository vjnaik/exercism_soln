#include "space_age.h"
#include <stdio.h>

float age(planet_t planet, int64_t seconds){
    float period_vs_earth[] = {0.2408467,  //Mercury
                           0.61519726, //Venus
                           1.0,        //Earth
                           1.8808158,  //Mercury
                           11.862615,  //Jupiter
                           29.447498,  //Saturn
                           84.016846,  //Uranus
                           164.79132};  //Neptune
    float earth_years = (float)seconds / (60 * 60 * 24 * 365.25);
    if((int)planet < 0)
        return -1;
    return earth_years / period_vs_earth[(int)planet];
}