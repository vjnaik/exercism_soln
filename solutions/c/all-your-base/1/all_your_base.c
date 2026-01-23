#include "all_your_base.h"

size_t rebase(int8_t* digits, int16_t input_base, int16_t output_base, size_t input_length) {
    size_t out_digit_cnt = 0;
    int input_num = 0;

    if (!input_length) return out_digit_cnt;
    if (input_base < 2 || output_base < 2) return out_digit_cnt;

    // Parse input digits
    for (size_t i = 0; i < input_length; i++) {
        int d = (int)digits[i];

        if (d < 0 || d >= input_base) return 0; // digit should be valid
        
        input_num = input_num * input_base + d;
    }
    
    if (!input_num) return 1; // If the number is zero

    // Output digits in LSD to MSD
    while (input_num > 0) {
        int8_t r = input_num % output_base;
        digits[out_digit_cnt++] = r;
        input_num /= output_base;
    }

    // Reverse the digits
    for (size_t i = 0; i < out_digit_cnt/2; i++) {
        int8_t tmp = digits[i];
        digits[i] = digits[out_digit_cnt - i - 1];
        digits[out_digit_cnt - i - 1] = tmp;
    }

    return out_digit_cnt;
}