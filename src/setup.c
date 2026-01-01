#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "setup.h"
#include "state.h"

bool setup(world_state_t *w) {
    int width_buffer;
    int height_buffer;

    do {
        printf("Enter the width (3 - 30): ");
        scanf(" %d", &width_buffer);

        printf("Enter the height (3 - 30): ");
        scanf(" %d", &height_buffer);

    } while (width_buffer < 3 || width_buffer > 30 ||
             height_buffer < 3 || height_buffer > 30);

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
