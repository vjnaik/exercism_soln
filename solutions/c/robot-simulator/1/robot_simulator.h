#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

#include <stdlib.h>
#include <stdio.h>

typedef enum {
   DIRECTION_NORTH = 0,
   DIRECTION_EAST = 1,
   DIRECTION_SOUTH = 2,
   DIRECTION_WEST = 3
} robot_direction_t;

typedef struct {
   int x;
   int y;
} robot_position_t;

typedef struct {
   robot_direction_t direction;
   robot_position_t position;
} robot_status_t;

robot_status_t robot_create(robot_direction_t direction, int x, int y);
void robot_move(robot_status_t *robot, const char *commands);

#endif
