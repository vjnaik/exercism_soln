#include "rotational_cipher.h"

char rotate_helper(char chr, int val){
    char res;
    if (chr >= 'a' && chr <= 'z'){
        res = (chr - 'a' + val) % 26 + 'a';
    } else if (chr >= 'A' && chr <= 'Z'){
        res = (chr - 'A' + val) % 26 + 'A';
    } else {
        res = chr;
    }
    return res;
}

char *rotate(const char *text, int shift_key){
    char *temp = calloc(1, sizeof(char) * (strlen(text) + 1));
    if (temp == NULL){
        return NULL;
    }
    for (int i = 0; *(text + i) != '\0'; i++){
        *(temp + i) = rotate_helper(*(text + i), shift_key);
    }
    return temp;
}