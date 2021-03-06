#include "MelodyPlayer.h"
#include "tasks/Task.h"
#include "Tiles.h"
#include "Common.h"
#include "Keys.h"
#include "Game.h"

#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

// Array of Output Pin variables, set to the pins being used
int rs = 4, en = 5, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int delay_gcd = 10;

int potPin = A1;

void setup() {
    //some set up (Default Arduino Function)
   Serial.begin(9600);

   pinMode(buttons[0], INPUT_PULLUP);
   pinMode(buttons[1], INPUT_PULLUP);
   pinMode(buttons[2], INPUT_PULLUP);


   unsigned char i = 0;

   tasks[i].state = 0;
   tasks[i].period = 20;
   tasks[i].elapsedTime = 0;
   tasks[i].TickFct = &Melody_Player;
   i++;
   tasks[i].state = 0;
   tasks[i].period = 100;
   tasks[i].elapsedTime = 0;
   tasks[i].TickFct = &Tiles;
   i++;
   tasks[i].state = 0;
   tasks[i].period = 20;
   tasks[i].elapsedTime = 0;
   tasks[i].TickFct = &Keys;
   i++;
   tasks[i].state = 0;
   tasks[i].period = 20;
   tasks[i].elapsedTime = 0;
   tasks[i].TickFct = &Game;


   delay_gcd = 10; // GCD
   lcd.begin(16,2);

   matrix.begin();
   matrix.setTextWrap(false);
   matrix.setBrightness(1);


   lcd.print("Initializing Game...");
}


void loop() {
  // put your main code here, to run repeatedly:
  unsigned char i;
  int gameSpeed = map(analogRead(potPin), 0, 1023, 1, 4);
  
  tasks[0].period = 20 / gameSpeed;
  tasks[1].period = 100 / gameSpeed;

  for (i = 0; i < tasksNum; ++i) {
     if ( (millis() - tasks[i].elapsedTime) >= tasks[i].period - 1) {
        tasks[i].state = tasks[i].TickFct(tasks[i].state);
        tasks[i].elapsedTime = millis(); // Last time this task was ran
      
     }
   }
  
   
}