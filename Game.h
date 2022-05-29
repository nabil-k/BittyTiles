#ifndef GAME
#define GAME

#include <Arduino.h>

enum Game_States { GAME_INIT, GAME_PLAY, GAME_END };
int Game(int state);

#endif