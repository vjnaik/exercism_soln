#include "variable_length_quantity.h"

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output) {
    int out_len = 0;
    for (size_t i = 0; i < integers_len; i++) {
        for (int j = 4 * 7; j > 0; j -= 7) {
            if (integers[i] >= ((uint32_t)1 << j)) {
                output[out_len++] = (integers[i] >> j) | SET_BIT;
            }
        }
        output[out_len++] = integers[i] & CLEAR_BIT;
    }
    return out_len;
}

int decode(const uint8_t *bytes, size_t bytes_len, uint32_t *output) {
    int out_len = 0;
    uint32_t integer = 0;
    uint8_t byte = 0;
    for (size_t i = 0; i < bytes_len; i++) {
        byte = bytes[i];
        integer <<= 7;
        integer |= bytes[i] & CLEAR_BIT;
        if (!(bytes[i] & SET_BIT)) {
            output[out_len++] = integer;
            integer = 0;
        }
    }
    if (byte & SET_BIT) { return -1; }
    return out_len;
}