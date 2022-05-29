#include "Game.h"
#include "Keys.h"
#include "MelodyPlayer.h"
#include "Tiles.h"
#include "Common.h"
#include <LiquidCrystal.h>

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
    static int score;
    
    switch(state){
        case GAME_SET:{
            buttonPressed = false;
            playNote = false;
            tick = 0; 
            state =  GAME_INIT;
            prevNote = NO_KEY;
            buttonWatched = -1;
            score = 0;
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
                    else if(!button_state[buttonWatched] && buttonPressed){
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
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Press a button");         
            break;
        }
        case GAME_PLAY:{
            int note = midiToFreq(noteToPlay);
            
            if(keyToPlay != NO_KEY){
                if(button_state[keyToPlay]){
                    tone(melodyBuzzer, note);
                    score++;
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
            lcd.clear();
            lcd.setCursor(0, 1);
            lcd.print("Score: ");
            lcd.print(String(score/4));

            break;
        }
        case GAME_END:{
            noTone(melodyBuzzer);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Game Over");
            lcd.setCursor(0, 1);
            lcd.print("Score: ");
            lcd.print(String(score/4));
            tick++;
            break;
        } 
    }

    gameState = (Game_States)state;
    
    return state;
}