#ifndef GAME
#define GAME

#include <Arduino.h>

enum Game_States { GAME_INIT, GAME_PLAY, GAME_END };
extern Game_States gameState;
int Game(int state);

#endif