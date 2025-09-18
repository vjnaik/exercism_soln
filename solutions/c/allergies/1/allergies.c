#include "allergies.h"

bool is_allergic_to(allergen_t ag, int score){
    if(ag == 0) 
        return (1 & score) != 0; // base case
    return ((2 << (ag - 1)) & score) != 0;
}

allergen_list_t get_allergens(int score){
    allergen_list_t* test = malloc(sizeof(allergen_list_t) * 1);
    
    if(test == NULL) 
        exit(1);
    
    test->count = 0;
    for(size_t i = 0; i < ALLERGEN_COUNT; i++)
        test->allergens[i] = false;
    
    if(score > 0){ // populate only for non-zero allergies
        for(int i = 1, x = 0; i < 256; i *= 2){
            if((score & i) != 0){
                test->count++;
                test->allergens[x] = true;
            }
            x++;
        }
    }
    return *test;
}