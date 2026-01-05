#ifndef STATE_H
#define STATE_H

typedef struct {
  int width;
  int height;
  unsigned char *cells; // 0 -> tot, 1 -> lebend
  // unsigned char, weil klein 1 byte
} grid_t;

typedef struct {
  grid_t current;
  grid_t next;
  struct Vector {
    int x;
    int y;
  } pointer;
} world_state_t;

#endif
