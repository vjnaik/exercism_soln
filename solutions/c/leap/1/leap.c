#include "leap.h"

bool leap_year(int year){
    return !(year % 400) || ((year % 100) && !(year % 4)) ? true : false;
}