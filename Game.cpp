#include "Game.h"
#include "Keys.h"
#include "MelodyPlayer.h"
#include "Tiles.h"
#include "Common.h"

/*

Controls the global game state variable

*/
Game_States gameState = GAME_INIT;

int Game(int state){
    static unsigned char notePlayedLength;
    // Switch States
    switch(state){
        case GAME_INIT:{
            for(unsigned char i = 0; i < 3; i++){
                if(button_state[i]){
                    state = GAME_PLAY;
                }
            }

            notePlayedLength

            break;
        }
        case GAME_PLAY:{
            if(melodyNoteIndex >= melodyLength){
                state = GAME_END;
            }         
            
            break;
        }
        case GAME_END:{
            for(unsigned char i = 0; i < 3; i++){
                if(button_state[i]){
                    state = GAME_INIT;
                }
            }

            break;
        }        
    }

    switch(state){
        case GAME_INIT:{
            
            break;
        }
        case GAME_PLAY:{
            for(unsigned char i = 0; i < 3; i++){
                if(keyToPlay == i){
                    if(button_state[i]){
                        int note = midiToFreq(melodyNotes[melodyNoteIndex]);
                        tone(melodyBuzzer, note);
                    }
                    else{
                        for(unsigned char j = 0; j < 3; j++){
                            if(i != j){
                                if(button_state[j]){
                                    tone(melodyBuzzer, 100);
                                }
                            }

                        }                        
                    }
                    
                }

            }              
            break;
        }
        case GAME_END:{
            
            break;
        } 
    }

    gameState = (Game_States)state;
    
    return state;
}