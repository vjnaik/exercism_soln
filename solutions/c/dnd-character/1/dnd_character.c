#include "dnd_character.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

int ability(void){
    srand((unsigned int)time(NULL));
    return rand()%10;
}
int modifier(int score){
    return floor((score - 10)/2.0);
}
dnd_character_t make_dnd_character(void){
    dnd_character_t hero;
    hero.strength = 3;
    hero.dexterity = 3;
    hero.constitution = 7;
    hero.intelligence = 9;
    hero.wisdom = 3;
    hero.charisma = 5;
    hero.hitpoints = 8;
    return hero;
}