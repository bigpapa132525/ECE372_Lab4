// Description: This file implements turnOnLED and initLED to control
// the LEDs.
//----------------------------------------------------------------------//


#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

/* Initialize PG0, PG1, PG2, and PG3 to outputs
*/
void initLED(){
    DDRC|=(1<<DDC3);
    DDRC|=(1<<DDC2);
    DDRC|=(1<<DDC1);
    DDRC|=(1<<DDC0);
}

/* This must be one line of code.
* In this function you will be giving a number "num" which will be represented
* in binary by four LEDs. You must effectively assign the lowest four bits of
* "num" to the appropriate bits of PORTA.
*/
void turnOnLEDWithChar(unsigned char num){

PORTC = (PORTC & 0xF0) | (num & 0x0F); // sets the first four bits to zero. // sets the top four bits of num to 
}

