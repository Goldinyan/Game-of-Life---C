#include <stdio.h>
#include <stdbool.h>


#include "draw.h"
#include "state.h"
#include "setup.h"

int main(void) {
  world_state_t world_state;

  if (!setup(&world_state)) {
    printf("Error: Could not allocate grids.\n");
    return 1;
  }

 
    

  run(&world_state);
}
