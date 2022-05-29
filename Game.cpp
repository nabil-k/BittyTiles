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
    static bool playNote;
    static int tick;
    static bool buttonPressed;
    static NoteKey prevNote;
    static int buttonWatched;
    
    switch(state){
        case GAME_SET:{
            buttonPressed = false;
            playNote = false;
            tick = 0; 
            state =  GAME_INIT;
            prevNote = NO_KEY;
            buttonWatched = -1;
            break;
        }
        case GAME_INIT:{
            for(unsigned char i = 0; i < 3; i++){
                    if(button_state[i] && !buttonPressed){
                        buttonWatched = i;
                        buttonPressed = true;
                    }
                    else if(!button_state[buttonWatched] && buttonPressed){
                        state = GAME_PLAY;
                        buttonWatched = -1;
                        buttonPressed = false;   
                    }
            }
            break;
        }
        case GAME_PLAY:{
            if(melodyNoteIndex >= melodyLength){
                state = GAME_END;
                buttonPressed = false;
            }         
            
            break;
        }
        case GAME_END:{
            if(tick >= 9){
                for(unsigned char i = 0; i < 3; i++){
                    if(button_state[i] && !buttonPressed){
                        buttonWatched = i;
                        buttonPressed = true;
                    }
                    else if(!button_state[buttonWatchedi] && buttonPressed){
                        state = GAME_SET;
                        buttonWatched = -1;
                        buttonPressed = false;   
                    }
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
            int note = midiToFreq(noteToPlay);
            
            if(keyToPlay != NO_KEY){
                if(button_state[keyToPlay]){
                    tone(melodyBuzzer, note);
                }
                else{
                    bool playError = false;
                    for(int key = 0; key < 3; key++){
                        if(key != keyToPlay && button_state[key]){
                            playError = true;
                        }
                    }

                    if(playError){
                        tone(melodyBuzzer, 50);
                    }
                    else{
                        noTone(melodyBuzzer);
                    }
                }
            }
            
            break;
        }
        case GAME_END:{
            tick++;
            break;
        } 
    }

    gameState = (Game_States)state;
    
    return state;
}