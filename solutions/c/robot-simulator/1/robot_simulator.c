#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_status_t* status = malloc(sizeof(robot_status_t)*1);
    if(status == NULL){
        fprintf(stderr, "Couldn't allocate storage for status\n");
        exit(1);
    }
    robot_position_t* pos = malloc(sizeof(robot_position_t)*1);
    if(pos == NULL){
        fprintf(stderr, "Couldn't allocate storage for pos\n");
        exit(1);
    }
    pos->x = x;
    pos->y = y;
    status->position = *pos;
    status->direction = direction;
    return *status;
}

void robot_move(robot_status_t *robot, const char *commands){
    for(size_t i = 0; commands[i] != '\0'; i++){
        switch(commands[i]){
            case 'R':
                robot->direction = (robot->direction + 1) % 4;
                break;
            case 'L':
                robot->direction = (robot->direction - 1) % 4;
                break;
            case 'A':
                if(robot->direction == DIRECTION_NORTH)
                    robot->position.y++;
                else if(robot->direction == DIRECTION_SOUTH)
                    robot->position.y--;
                else if(robot->direction == DIRECTION_EAST)
                    robot->position.x++;
                else
                    robot->position.x--;
                break;
            default:
                fprintf(stderr, "Invalid Command received %c\n", commands[i]);
                exit(1);
        }
    }
}