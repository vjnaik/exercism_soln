#include "triangle.h"

bool check_valid(triangle_t test){
    return (test.a + test.b) > test.c && (test.b + test.c) > test.a && (test.a + test.c) > test.b;
}

bool is_equilateral(triangle_t test){
    return check_valid(test) && test.a == test.c && test.a == test.b; 
}

bool is_isosceles(triangle_t test){
    return check_valid(test) && (test.a == test.c || test.a == test.b || test.b == test.c);
}

bool is_scalene(triangle_t test){
    return (!check_valid(test) || is_equilateral(test) || is_isosceles(test)) ? false : true;
}