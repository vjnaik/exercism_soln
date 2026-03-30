#include "kindergarten_garden.h"

plants_t plants(const char *diagram, const char *student) {
    char *top = calloc(25, sizeof *top);
    char *bot = calloc(25, sizeof *bot);
    if (!top || !bot) {
        exit(1);
    }
    
    size_t split = strcspn(diagram, "\n");
    strncpy(top, diagram, split);
    strcpy(bot, diagram + split + 1);

    unsigned int off = (*student - 'A') * 2;
    char plants[4] = {*(top + off), *(top + off + 1), *(bot + off), *(bot + off + 1)};

    plants_t plant;
    for (size_t i = 0; i < 4; i++) {
        switch (plants[i]) {
            case 'V': plant.plants[i] = VIOLETS; break;
            case 'R': plant.plants[i] = RADISHES; break;
            case 'G': plant.plants[i] = GRASS; break;
            default: plant.plants[i] = CLOVER;
        }
    }
    
    free(top);
    free(bot);
    
    return plant;
}