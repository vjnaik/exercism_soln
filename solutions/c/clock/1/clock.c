#include "clock.h"

int _adjust(int hour, int minute, int value){
    int minutes = (hour * 60 + minute + value) % 1440;
    return minutes + ((minutes < 0) ? 1440 : 0);
}

clock_t _display(clock_t clk, int value){
    sprintf(clk.text, "%02d:%02d", (int)(value/60.0), value % 60);
    return clk;
}

clock_t clock_create(int hour, int minute){
    clock_t temp;
    int value = _adjust(hour, minute, 0);
    return _display(temp, value);
}

clock_t clock_add(clock_t clock, int minute_add){
    int hour = 0, minute = 0, value = 0;
    sscanf(clock.text, "%d:%d", &hour, &minute );
    value = _adjust(hour, minute, minute_add);
    return _display(clock, value);
}

clock_t clock_subtract(clock_t clock, int minute_subtract){
    return clock_add(clock, -1 * minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b){
    return !strcmp(a.text,b.text);
}