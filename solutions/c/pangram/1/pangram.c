#include "pangram.h"

bool is_pangram(const char *sentence){
    int alpha[26] = {0};
    
    if(sentence == NULL) return false;
    
    if(strlen(sentence) < 26) return false;

    for(size_t i = 0; i < strlen(sentence); i++){
        int diff = tolower(sentence[i]) - 'a';
        if(diff >= 0 && diff < 26)
            alpha[diff]++;
    }
    for(int i = 0; i < 26; i++){
        if(alpha[i] == 0)
            return false;
    }
    return true;
}