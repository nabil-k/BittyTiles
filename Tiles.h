#ifndef TILES
#define TILES

const unsigned char melodyBuzzer = 13;
const unsigned char backgroundBuzzer = 12;
enum melody_player_states { TILES_INIT, TILES_PLAY};
int Tiles(int state);

#endif