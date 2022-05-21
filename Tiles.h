#ifndef TILES
#define TILES

#include "MelodyPlayer.h"
#include "Matrix.h"

enum NoteKey{A, B, C};

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), 
  matrix.Color(0, 255, 0), 
  matrix.Color(0, 0, 255) 
};


enum tiles_states { TILES_INIT, TILES_PLAY};
int Tiles(int state);

#endif