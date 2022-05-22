#include "MelodyPlayer.h"
#include "tasks/Task.h"
#include "Tiles.h"
#include <LiquidCrystal.h>
#include "Common.h"
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

// Array of Output Pin variables, set to the pins being used
const int rs = 4, en = 5, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int delay_gcd = 10;



void setup() {
    //some set up (Default Arduino Function)
   Serial.begin(9600);

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

   delay_gcd = 10; // GCD
   lcd.begin(16,2);

   matrix.begin();
   matrix.setTextWrap(false);
   matrix.setBrightness(1);


    lcd.print("WE LOVE");
}


void loop() {
  // put your main code here, to run repeatedly:
  unsigned char i;
  for (i = 0; i < tasksNum; ++i) {
     if ( (millis() - tasks[i].elapsedTime) >= tasks[i].period - 1) {
        tasks[i].state = tasks[i].TickFct(tasks[i].state);
        tasks[i].elapsedTime = millis(); // Last time this task was ran
      
     }
   }
  

}