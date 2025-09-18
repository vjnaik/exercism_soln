#ifndef ROTATIONAL_CIPHER_H
#define ROTATIONAL_CIPHER_H

#include <stdlib.h>
#include <string.h>

char rotate_helper(char chr, int val);
char *rotate(const char *text, int shift_key);

#endif
