#ifndef TILES
#define TILES

#include "MelodyPlayer.h"

enum NoteKey{A, B, C, NO_KEY};
extern NoteKey keyToPlay;
enum tiles_states { TILES_INIT, TILES_PLAY, TILES_END};
int Tiles(int state);

#endif