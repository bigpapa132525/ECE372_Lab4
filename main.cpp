// Author:
// Net ID:
// Date:
// Assignment:     Lab 3
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements:
//----------------------------------------------------------------------//





#include <avr/io.h>
#include "led.h"
#include "switch.h"
#include "timer.h"
#include "lcd.h"
#include <avr/interrupt.h>
#include <avr/io.h>

// defines


/*
 * Define a set of states that can be used in the state machine using an enum.
 */
// typedef enum .......


// Initialize states.  Remember to use volatile 

/*
 * Define a set of states that can be used in the state machine using an enum.
 */


volatile int counter=0;
volatile int time_base=10;

// Sequence that the led's are going through
int number = 1;

// Boolian value wheather faster mode is on or not
int fast = 0;

// see if button is pressed
volatile int bttnPress = 0;

int wait = 0;

typedef enum state_table{
  Wait_Press,
  Debounce_Press,
  Change_Mode,
  Wait_Release,
  Debounce_Release,
}state;

volatile state Current_state = Wait_Press;


int main(){

// ---- initiallizing ---- //
  initTimer1();
  initTimer0();
  initLCD();
  switch_init();
  initLED();
  sei(); // Enable global interrupts.

  moveCursor(0, 0); // moves the cursor to 0,0 position
  writeString("BR= 100 ms");
  moveCursor(1, 0);  // moves the cursor to 1,0 position
  writeString("Fast");
  // moveCursor(0, 0); // moves the cursor to 0,0 position
  // writeString("This is a TEST"); //write top line of LCD
  // moveCursor(1, 2);  // moves the cursor to 1,2 position
  // // writing a special character from the datasheet table
  //  writeCharacter(0xF4); // write a theta 
  //  moveCursor(1, 5);  // moves the cursor to 5,1 position

  moveCursor(1,9);// zero and zero first location

// while loop
  while(1){
// State machine
switch (Current_state)
{
case Wait_Press:
  break;
case Debounce_Press:
  delay_3ms();
    counter = 0;
    Current_state = Change_Mode;
  
  break;
  case Change_Mode:
    if (!(PINB & (1<<PINB3)))
    {
      if(fast){
        fast = 0;
      } 
      else fast = 1;
// lcd display change
      if(fast){
        moveCursor(0,0);
        writeString("BR = 100 ms ");
        moveCursor(1,0);
        writeString("Fast ");
      }
      else{
        moveCursor(0,0);
        writeString("BR = 200 ms ");
        moveCursor(1,0);
        writeString("Slow ");
      }


    }
    Current_state = Wait_Release;
  break;
case Wait_Release:
    if ((PINB & (1<<PINB3)))
      Current_state = Debounce_Release;
    
break;

case Debounce_Release:
    delay_3ms();  
    Current_state = Wait_Press;
  break;
default:
  break;
}
               // timer length //
// ------------------------------------------ //
if (fast)
{
  time_base = 10;
// This is 10x10 = 100 ms
}
else {
  time_base = 20;
//This is 20x10 = 200 ms
}
// ------------------   timer   -------------------------- //
    Timer_100ms(time_base);
    turnOnLEDWithChar(number);
    if(number==15){
    number = 0;
    }
    else {
    number++;
    }
}
  return 0;
}

/* Implement an Pin Change Interrupt which handles the switch being
* pressed and released. When the switch is pressed and released, the LEDs
* change at twice the original rate. If the LEDs are already changing at twice
* the original rate, it goes back to the original rate.
*/
ISR(PCINT0_vect){
  if (Current_state == Wait_Press) {
          Current_state = Debounce_Press;
          counter = 0;
      }
}