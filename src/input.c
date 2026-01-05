#include <stdbool.h>
#include <stdio.h>
// MOVEMENT
#include <termios.h>
#include <unistd.h>

#include "input.h"
#include "update.h"

void enable_raw_mode(void) {
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

int kbhit(void) {
  struct timeval tv = {0L, 0L};
  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(0, &fds);
  return select(1, &fds, NULL, NULL, &tv);
}

void handle_input(grid_t *g, bool *coords_choosen, bool *did_quit,
                  struct Vector *p) {
  if (!kbhit())
    return;

  int width = g->width;
  int height = g->height;

  char c = getchar();

  if (c == 'q') {
    *did_quit = true;
  }

  if (!*coords_choosen) {
    switch (c) {
    case 'w':
      if (p->y > 0)
        p->y--;
      break;

    case 's':
      if (p->y < height - 1)
        p->y++;
      break;

    case 'a':
      if (p->x > 0)
        p->x--;
      break;

    case 'd':
      if (p->x < width - 1)
        p->x++;
      break;

    case 'g': // cell toggeln
      grid_set(g, p->x, p->y, !grid_get(g, p->x, p->y));
      break;

    case 'f':
      *coords_choosen = true;
      break;
    }
  }
}
