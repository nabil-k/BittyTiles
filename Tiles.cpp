#include "Tiles.h"

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
    static int timeDisplacement;
    static int prevMelodyNoteIndex;
    //Read thing
    switch(state){ // State transitions
      case TILES_INIT:
        state = TILES_PLAY;
         //State Transition
        break;
      case TILES_PLAY:
         //State Transition
        break;
    }
    switch(state){ // State Action
      case TILES_INIT:{
         //State Action
         prevMelodyNoteIndex = melodyNoteIndex;
        break;
      }

      case TILES_PLAY:{
        //State Action
        int totalTime = 0;
        int pos = melodyNoteIndex;

        if(pos >= melodyLength){
          break;
        }

        matrix.fillScreen(matrix.Color(0, 0, 0));
        
        if(prevMelodyNoteIndex == melodyNoteIndex){
          timeDisplacement += 100;
        }

        while(pos < melodyLength && totalTime <= 400) {
          totalTime += melodyTimes[pos];
          
          if(totalTime > 400){
            break;
          }

          NoteKey key = midiNoteToNoteKey(melodyNotes[pos]);
          unsigned int rectY = 8 - (melodyTimes[pos] / 100 * 2);
          unsigned int rectX = key * 3;

          matrix.fillRect(rectX, rectY, 2, 2, colors[key]);

          
          totalTime += melodyTimes[pos];
          
          if(prevMelodyNoteIndex != melodyNoteIndex){
            prevMelodyNoteIndex = melodyNoteIndex;
          }

          pos++;
        }
         

        break;
      }
    }

    return state;
}