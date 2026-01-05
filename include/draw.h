#ifndef DRAW_H
#define DRAW_H

#include "state.h"


void choose_coords(world_state_t *w);
void grid_render(const grid_t *g);
void run(world_state_t *w);


#endif 
