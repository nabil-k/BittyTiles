#include "Keys.h"

unsigned char buttons[3] = {2,3,7};
unsigned char button_state[3] = {0, 0, 0};

int Keys(int state){
    // Switch States
    switch(state){
        case KEY_INIT:{
            for(unsigned char i = 0; i < 3; i++){
                button_state[i] = !digitalRead(buttons[i]);
                
            }
            break;
        }
    }

    return state;
}