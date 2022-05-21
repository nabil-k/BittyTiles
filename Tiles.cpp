#include "Tiles.h"

enum NoteKey{A, B, C};

NoteKey midiNoteToNoteKey(int midiNote){
  int octave  = (midiNote - 21) % 12;
  
  if(octave <= 3){
    return A;
  }
  else if(octave <= 7){
    return B;
  }

  return C;
}


int Tiles(int state){

    //Read thing
    switch(state){ // State transitions
      case TILES_INIT:
         //State Transition
        break;
      case TILES_PLAY:
         //State Transition
        break;
    }
    switch(state){ // State Action
      case TILES_INIT:{
         //State Action
        break;
      }

      case TILES_PLAY:{
        //State Action
        
        break;
      }
    }

    return state;
}