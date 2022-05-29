#include "MelodyPlayer.h"
#include "Common.h"
#include "Game.h"
#include <math.h>

int midiToFreq(int midiNote){
  float a = 440;
  return (int)((a / 32) * pow(2, ((float)(midiNote - 9) / 12.0)));
}

int Melody_Player(int state){
    static int prevMelodyNoteTime;
    static int backgroundNoteIndex;
    static int prevBackgroundNoteTime;
    static int tick;
    switch(state){ 
      case MELODY_INIT:{
        if(gameState == GAME_PLAY){
          state = MELODY_PLAY;
        }

        break;   
      }
      case MELODY_PLAY:{
         //State Transition
        if(gameState == GAME_END){
          state = MELODY_INIT;
        }

        break;
      }

    }
    switch(state){ // State Action
      case MELODY_INIT:{
        prevMelodyNoteTime = 0;
        melodyNoteIndex = 0;
        backgroundNoteIndex = 0;
        prevBackgroundNoteTime = 0; 
        break;
      }

      case MELODY_PLAY:{
        //State Action
        
        // Melody
        if(melodyNoteIndex < melodyLength){
            if(prevMelodyNoteTime >= melodyTimes[melodyNoteIndex]){
                prevMelodyNoteTime = 0;
                melodyNoteIndex++;
            }
        }
        
        prevBackgroundNoteTime += 10;
        prevMelodyNoteTime += 10;
        tick++;
        //State Action
        break;
      }
    }

    return state;
}