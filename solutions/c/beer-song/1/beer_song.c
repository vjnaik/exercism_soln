#include "beer_song.h"

void recite(uint8_t start_bottles, uint8_t take_down, char **song){
    for (int bottle = start_bottles; bottle > start_bottles - take_down; bottle--){
        if (bottle>= 2){
            sprintf(*song++,"%d bottles of beer on the wall, %d bottles of beer.", bottle, bottle);
            sprintf(*song++,"Take one down and pass it around, %d %s of beer on the wall.", bottle - 1, (bottle - 1 == 1 ? "bottle": "bottles"));
        } else if (bottle == 1) {
            sprintf(*song++, "1 bottle of beer on the wall, 1 bottle of beer.");
            sprintf(*song++, "Take it down and pass it around, no more bottles of beer on the wall.");
        } else {
            sprintf(*song++, "No more bottles of beer on the wall, no more bottles of beer.");
            sprintf(*song++, "Go to the store and buy some more, 99 bottles of beer on the wall.");
        }
        song++;   
    }
}