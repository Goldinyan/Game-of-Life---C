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
      if (x == 0) {
        printf("             "); // Buffer for UI
      }
      putchar(grid_get(g, x, y) ? '#' : '.');
    }
    putchar('\n');
  }
}


static void print_index(struct Vector v, int x, int y, char c) {
  if (v.x == x && v.y == y) {
    printf("\033[32m%c\033[0m", c); // grün
  } else {
    putchar(c); // normal
  }
}

void choose_coords(world_state_t *w) {
  printf("\033[H\033[J");

  usleep(100000); // 100 ms
  
  for (size_t i = 0; i < 5; i++) { // Buffer for UI
    printf("\n");
  };

  for (int y = 0; y < w->current.height; y++) {
    for (int x = 0; x < w->current.width; x++) {
      if (x == 0) {
        printf("             "); // Buffer for UI
      }
      print_index(w->pointer, x, y, grid_get(&w->current, x, y) ? '#' : '.');
    }
    putchar('\n');
  }
}
