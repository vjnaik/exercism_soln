#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size){
    input += (time_t)1000000000;
    struct tm* conv = gmtime(&input);
    strftime(output, size, "%Y-%m-%d %H:%M:%S", conv);
}