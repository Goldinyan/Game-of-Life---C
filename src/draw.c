#include <stdio.h>
#include <unistd.h> // usleep

#include "draw.h"
#include "state.h"
#include "update.h"

void grid_render(const grid_t *g) {

  for (size_t i = 0; i < 5; i++) { // Buffer for UI
    printf("\n");
  };

  for (int y = 0; y < g->height; y++) {
    for (int x = 0; x < g->width; x++) {
      if(x == 0){
        printf("             "); // Buffer for UI
      }
      putchar(grid_get(g, x, y) ? '#' : '.');
    }
    putchar('\n');
  }
}

void run(world_state_t *w) {
  while (1) {
    grid_render(&w->current);
    world_step(w);
    usleep(100000); // 100 ms
    printf("\033[H\033[J");
  }
}
