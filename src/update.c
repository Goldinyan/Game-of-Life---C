#include "state.h"
#include <stdio.h>


#include "update.h"

unsigned char grid_get(const grid_t *g, int x, int y) {
  if (x < 0 || x >= g->width || y < 0 || y >= g->height)
    return 0; // Rand = tot 
  return g->cells[y * g->width + x];
}

void grid_set(grid_t *g, int x, int y, unsigned char value) {
  g->cells[y * g->width + x] = value;
}

int count_neighbors(const grid_t *g, int x, int y) {
  int sum = 0;

  // 3 x 3 Grid
  for (int dy = -1; dy <= 1; dy++) {
    for (int dx = -1; dx <= 1; dx++) {
      if (dx == 0 && dy == 0) // self
        continue;
      sum += grid_get(g, x + dx, y + dy);
    }
  }
  return sum;
}

void world_step(world_state_t *w) {
  grid_t *cur = &w->current;
  grid_t *next = &w->next;

  for (int y = 0; y < cur->height; y++) {
    for (int x = 0; x < cur->width; x++) {
      int neighbors = count_neighbors(cur, x, y);
      unsigned char alive = grid_get(cur, x, y);
      unsigned char new_value = 0;

      if (alive) {
        if (neighbors == 2 || neighbors == 3)
          new_value = 1;
      } else {
        if (neighbors == 3)
          new_value = 1;
      }

      grid_set(next, x, y, new_value);
    }
  }

  // Buffer tauschen
  grid_t tmp = *cur;
  *cur = *next;
  *next = tmp;
}
