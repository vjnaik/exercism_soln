#ifndef CLOCK_H
#define CLOCK_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STR_LEN sizeof("##:##")

typedef struct {
   char text[MAX_STR_LEN+1]; // add 1 for NULL
} clock_t;

int _adjust(int hour, int minute, int value);
clock_t _display(clock_t clk, int value);
clock_t clock_create(int hour, int minute);
clock_t clock_add(clock_t clock, int minute_add);
clock_t clock_subtract(clock_t clock, int minute_subtract);
bool clock_is_equal(clock_t a, clock_t b);

#endif
