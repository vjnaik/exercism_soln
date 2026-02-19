#include "scrabble_score.h"

const unsigned int values[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1,
                                 8, 5, 1, 3, 1, 1, 3, 10, 1,
                                 1, 1, 1, 4, 4, 8, 4, 10};

unsigned int score(const char *word){
    unsigned int result = 0;
    char *temp = (char *)word;

    while (*temp != '\0') {
        result += values[(size_t)(tolower(*temp) - 'a')];
        temp++;
    }
    
    return result;
}