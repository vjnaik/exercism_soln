#ifndef ZEBRA_PUZZLE_H
#define ZEBRA_PUZZLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define CAT 5

/* Categories */
enum { C_NAT=0, C_COL=1, C_DRINK=2, C_HOB=3, C_PET=4 };

enum Nat   { ENGLISHMAN, SPANIARD, UKRAINIAN, NORWEGIAN, JAPANESE };
enum Color { RED, GREEN, IVORY, YELLOW, BLUE };
enum Drink { COFFEE, TEA, MILK, ORANGE_JUICE, WATER };
enum Hobby { PAINT, DANCE, READ, FOOTBALL, CHESS };
enum Pet   { DOG, SNAIL, FOX, HORSE, ZEBRA };

typedef struct { int cat, item; } Var;

typedef struct {
   const char *drinks_water;
   const char *owns_zebra;
} solution_t;

solution_t solve_puzzle(void);

#endif
