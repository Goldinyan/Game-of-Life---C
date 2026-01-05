#include <stdbool.h>
#include <stdio.h>
#include <unistd.h> // usleep

#include "draw.h"
#include "input.h"
#include "setup.h"
#include "state.h"
#include "update.h"

int main(void) {
  world_state_t world_state;
  bool coords_choosen = false;
  bool did_quit = false;


  if (!setup(&world_state)) {
    printf("Error: Could not allocate grids.\n");
    return 1;
  }

  enable_raw_mode(); // Wenn das vor setup, geht scanf nicht mehr durch kein input

  while (!did_quit) {
    handle_input(&world_state.current, &coords_choosen, &did_quit,
                 &world_state.pointer);

    if (!coords_choosen) {
      choose_coords(&world_state);
    } else {
      grid_render(&world_state.current);
      world_step(&world_state);
      usleep(100000);
      printf("\033[H\033[J");
    }
  }
}
