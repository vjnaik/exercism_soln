#ifndef VARIABLE_LENGTH_QUANTITY_H
#define VARIABLE_LENGTH_QUANTITY_H

#include <stdint.h>
#include <stddef.h>

enum { CLEAR_BIT = 0x7F, SET_BIT = 0x80 };

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output);

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output);

#endif