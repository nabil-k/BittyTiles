#include "MelodyPlayer.h"
#include "Common.h"
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
    //Read thing
    switch(state){ // State transitions
      case MELODY_INIT:
         //State Transition
            state = MELODY_PLAY;
            prevMelodyNoteTime = 0;
            melodyNoteIndex = 0;
            backgroundNoteIndex = 0;
            prevBackgroundNoteTime = 0;
        break;
      case MELODY_PLAY:
         //State Transition
        break;
    }
    switch(state){ // State Action
      case MELODY_INIT:{
         //State Action
        break;
      }

      case MELODY_PLAY:{
        //State Action
        
        // Melody
        if(melodyNoteIndex < melodyLength){
            if(prevMelodyNoteTime >= melodyTimes[melodyNoteIndex]){
                int note = midiToFreq(melodyNotes[melodyNoteIndex]);
                // tone(melodyBuzzer, note);
                prevMelodyNoteTime = 0;
                melodyNoteIndex++;
            }
          

        }
        else{
            noTone(melodyBuzzer);
        }
        
        prevBackgroundNoteTime += 20;
        prevMelodyNoteTime += 20;
        tick++;
        //State Action
        break;
      }
    }

    return state;
}