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

void initSevSeg(){
    DDRC|= (1<<DDC0);
    DDRC|= (1<<DDC1);
    DDRC|= (1<<DDC2);
    DDRC|= (1<<DDC3);
    DDRC|= (1<<DDC4);
    DDRC|= (1<<DDC5);
    DDRC|= (1<<DDC6);
    DDRC|= (1<<DDC7);
}

void numOut(char num){

    if(num == 0){
        PORTC = 0b00111111;
    }
    else if(num == 1){
        PORTC = 0b00000110;
    }
    else if(num == 2){
        PORTC = 0b01011011;
    }
    else if(num == 3){
        PORTC = 0b01001111;
    }
    else if(num == 4){
        PORTC = 0b01100110;
    }
    else if(num == 5){
        PORTC = 0b01101101;
    }
    else if(num == 6){
        PORTC = 0b01111101;
    }
    else if(num == 7){
        PORTC = 0b00000111;
    }
    else if(num == 8){
        PORTC = 0b01111111;
    }
    else if(num == 9){
        PORTC = 0b01101111;
    }
    else{
        PORTC = 0b00000000;
    }
}

