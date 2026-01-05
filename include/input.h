#ifndef INPUT_H
#define INPUT_H

#include "state.h"
#include <stdbool.h>

void handle_input(grid_t *g, bool *coords_choosen, bool *did_quit,
                  struct Vector *pointer);
void enable_raw_mode(void);
int kbhit(void);

#endif // !INPUT_H
