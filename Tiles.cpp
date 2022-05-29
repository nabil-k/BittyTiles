#include "Tiles.h"
#include "Common.h"
#include <stdlib.h>     /* srand, rand */
#include "Game.h"

NoteKey keyToPlay = NO_KEY;

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 6,
  NEO_MATRIX_TOP  + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), 
  matrix.Color(0, 255, 0), 
  matrix.Color(0, 0, 255) 
};

int midiNoteToNoteKey(int midiNote){
  int octave  = (midiNote - 21) % 12;

  return octave % 3;
}


int Tiles(int state){
    static int timeDisplacement;
    static int prevMelodyNoteIndex;
    static int prevLastHitNoteY;
    static int prevLastHitNoteX;

    //Read thing
    switch(state){ // State transitions
      case TILES_INIT:{
        if(gameState == GAME_PLAY){
          state = TILES_PLAY;
        }
         //State Transition
        break;
      }
      case TILES_PLAY:{
        if(gameState == GAME_END){
          state = TILES_END;
        }
         //State Transition
        break;
      }
      case TILES_END: {
        if(gameState == GAME_INIT){
          state = TILES_INIT;
        }
        break;
      }
    }
    switch(state){ // State Action
      case TILES_INIT:{
         //State Action
        prevMelodyNoteIndex = melodyNoteIndex;
        prevLastHitNoteY = 0;
        prevLastHitNoteX = 0;
        matrix.fillScreen(matrix.Color(255, 0, 255));
        break;
      }

      case TILES_PLAY:{
        //State Action
        int totalTime = 0;
        int pos = melodyNoteIndex;
        bool adjustment = false;

        if(pos >= melodyLength){
          break;
        }

        // Clearing screen
        matrix.fillScreen(matrix.Color(255, 255, 255));
        
        if(prevMelodyNoteIndex == melodyNoteIndex){
          timeDisplacement += 50;
        }
        else{

          timeDisplacement = 0;
        }

        if(prevLastHitNoteY != 0){
          matrix.fillRect(prevLastHitNoteX, prevLastHitNoteY, 2, 1, colors[prevLastHitNoteX / 3]);
          prevLastHitNoteX, prevLastHitNoteY = 0;
        }        

        // Serial.print(timeDisplacement);
        // Serial.print(" index: ");
        // Serial.println(pos);

        keyToPlay = NO_KEY;

        while(pos < melodyLength && totalTime <= 650) {
          totalTime += melodyTimes[pos];
          
          if(totalTime > 650){
            break;
          }

          NoteKey key = (NoteKey)midiNoteToNoteKey(melodyNotes[pos]);
          unsigned int rectY = 7 - ((totalTime - timeDisplacement) / 50);
          unsigned int rectX = key * 3;
          
          if(rectY == 6){
            prevLastHitNoteY = 7;
            prevLastHitNoteX = rectX;
            keyToPlay = key;
          }

          matrix.fillRect(rectX, rectY, 2, 2, colors[key]);

          pos++;
        }
        

        prevMelodyNoteIndex = melodyNoteIndex;

        break;
      }

      case TILES_END:{
        matrix.fillScreen(matrix.Color(0, 0, 255));
        break;
      }
    }

    matrix.show();
    return state;
}