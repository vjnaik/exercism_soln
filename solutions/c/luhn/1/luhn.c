#include "luhn.h"

bool luhn(const char *num) {
    size_t len = strlen(num);
    char *temp = malloc(sizeof(char)*(len + 1));
    if (!temp) return false;       // Check for malloc failure

    int x = 0;
    for (size_t i = 0; i < len; i++) {
        if (isdigit(num[i])) {
            temp[x++] = num[i];
        } else if(!isspace(num[i])) {
            return false;
        }
    }
    temp[x] = '\0'; // Null-terminate
    
    if(x < 2) return false; // Should have more than one digit
    
    int sum = 0;
    bool alternate = false;

    for (int i = x - 1; i >= 0; i--) {
        int digit = temp[i] - '0';
        if (alternate) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }
        sum += digit;
        alternate = !alternate;
    }

    free(temp);
    return (sum % 10 == 0);
}
