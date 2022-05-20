#include "MelodyPlayer.h"


int Melody_Player(int state){
    static int noteIndex;
    static int prevNoteTime;
    //Read thing
    switch(state){ // State transitions
      case MELODY_INIT:
         //State Transition
            state = MELODY_PLAY;
            prevNoteTime = 0;
            noteIndex = 0;
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
        
        if(noteIndex < melodyLength){
            if(prevNoteTime >= times[noteIndex]){
                tone(melodyBuzzer, notes[noteIndex]);
                prevNoteTime = 0;
                noteIndex++;
            }   
        }
        else{
            noTone(melodyBuzzer);
        }

        
        prevNoteTime += 10;
        //State Action
        break;
      }
    }

    return state;
}