#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "setup.h"
#include "state.h"

#define MAX 80
#define MIN 10

bool setup(world_state_t *w) {
  int width_buffer;
  int height_buffer;

  do {
    printf("Enter the width (%d - %d): ", MIN, MAX);
    scanf(" %d", &width_buffer);

    printf("Enter the height (%d - %d): ", MIN, MAX);
    scanf(" %d", &height_buffer);

  } while (width_buffer < MIN - 1 || width_buffer > MAX + 1  || height_buffer < MIN - 1 ||
           height_buffer > MAX + 1);

  w->pointer.y = 0;
  w->pointer.x = 0;

  w->current.width = width_buffer;
  w->current.height = height_buffer;
  w->next.width = width_buffer;
  w->next.height = height_buffer;

  w->current.cells = calloc((size_t)width_buffer * (size_t)height_buffer,
                            sizeof(unsigned char));
  w->next.cells = calloc((size_t)width_buffer * (size_t)height_buffer,
                         sizeof(unsigned char));

  return w->next.cells != NULL && w->current.cells;
}
