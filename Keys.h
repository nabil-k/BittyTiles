#ifndef KEY
#define KEY

#include <Arduino.h>
extern unsigned char buttons[];
extern unsigned char button_state[];
enum Keys_States { KEY_INIT };
int Keys(int state);

#endif