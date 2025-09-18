#include "isogram.h"

bool is_isogram(const char phrase[]){
    int array[26] = {0};
    if(phrase == NULL) return false;
    if(phrase[0] == '\0') return true;
    for(int i = 0; phrase[i] != '\0'; i++){
        if(isupper(phrase[i]) == true)
            array[phrase[i] - 'A']++;
        else if(islower(phrase[i]) == true)
            array[phrase[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(array[i] > 1) return false;
    }
    return true;
}