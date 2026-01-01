#ifndef UPDATE_H
#define UPDATE_H

#include "state.h"

unsigned char grid_get(const grid_t *g, int x, int y);
void grid_set(grid_t *g, int x, int y, unsigned char value); 
int count_neighbors(const grid_t *g, int x, int y);
void world_step(world_state_t *w);

#endif 
