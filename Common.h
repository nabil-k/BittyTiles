#ifndef COMMON
#define COMMON

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

extern Adafruit_NeoMatrix matrix;
extern unsigned short int melodyNoteIndex;
extern unsigned short int melodyLength;
extern unsigned char melodyNotes[];
extern unsigned char melodyTimes[];
#endif