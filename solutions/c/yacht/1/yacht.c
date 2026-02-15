#include "yacht.h"        

int score(dice_t dice, category_t category) { 
    int face_counts[7] = {0};
    int has_2 = 0, has_3 = 0;
    
    for (int i = 0; i < 5; i++) {
        face_counts[dice.faces[i]]++;
    }

    switch (category) {          
        case ONES:   return face_counts[1] * 1; 
        case TWOS:   return face_counts[2] * 2;
        case THREES: return face_counts[3] * 3;
        case FOURS:  return face_counts[4] * 4;
        case FIVES:  return face_counts[5] * 5;
        case SIXES:  return face_counts[6] * 6;
          
        case FULL_HOUSE:          
            for (int i = 1; i <= 6; i++) {
                if (face_counts[i] == 2) has_2 = 1;
                if (face_counts[i] == 3) has_3 = 1;
            }          
            return (has_2 && has_3) ? (dice.faces[0] + dice.faces[1] + dice.faces[2] + dice.faces[3] + dice.faces[4]) : 0;

        case FOUR_OF_A_KIND:          
            for (int i = 1; i <= 6; i++) {
                if (face_counts[i] >= 4) return i * 4;
            }
            return 0;

        case LITTLE_STRAIGHT:
            return (face_counts[1] && face_counts[2] && face_counts[3] && face_counts[4] && face_counts[5] && !face_counts[6]) ? 30 : 0;

        case BIG_STRAIGHT:
            return (face_counts[2] && face_counts[3] && face_counts[4] && face_counts[5] && face_counts[6] && !face_counts[1]) ? 30 : 0;
   
        case CHOICE:
            return dice.faces[0] + dice.faces[1] + dice.faces[2] + dice.faces[3] + dice.faces[4];

        case YACHT:
            for (int i = 1; i < 5; i++) {
                if (dice.faces[i] != dice.faces[0]) return 0;
            }

            return 50;

        default: return 0;
    }
}