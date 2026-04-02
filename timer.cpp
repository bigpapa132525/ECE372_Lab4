// Author: 
// Net ID: 
// Date: 
// Assignment: Lab 3
//----------------------------------------------------------------------//

#include "timer.h"
//You many use any timer you wish for the microsecond delay and the millisecond delay
// int counter = 0;

/* Initialize timer 1, you should not turn the timer on here. Use CTC mode  .*/
void initTimer1(){
// 1. CTC mode 010 WGM02, WGM00=0
    TCCR1A&=~(1<<WGM10);
    TCCR1A|=(1<<WGM11);
    TCCR1B&=~(1<<WGM12);
// 2. choose Prescalar=8--> 010
    TCCR1B&=~(1<<CS12);
    TCCR1B|=(1<<CS11);
    TCCR1B&=~(1<<CS10);
//3. Counter Register
//4. Compare register value
    OCR1A=1; // 0.5 u sec * 2 = 1 us
// Turn on Enable Interrupt 
}

/* This delays the program an amount of microseconds specified by unsigned int delay.
*/
void delayUs(unsigned int delay){
    int counter = 0;
    // TIFR1|=(1<<OCF1A);//erase the flag/rais it down=1
    while(counter< delay){
        TIFR1|=(1<<OCF1A);
        TCNT1=0;
    while(!(TIFR1&(1<<OCF1A)));// wait loop
    counter++;
    }
}

/* Initialize timer 0, you should not turn the timer on here.
* You will need to use CTC mode */
void initTimer0(){
// 1. CTC mode 010 WGM02, WGM00=0
    TCCR0A&=~(1<<WGM00);
    TCCR0A|=(1<<WGM01);
    TCCR0B&=~(1<<WGM02);
// 2. choose Prescalar=64--> 011
    TCCR0B&=~(1<<CS02);
    TCCR0B|=(1<<CS01);
    TCCR0B|=(1<<CS00);
//3. Counter Register
//4. Compare register value
    OCR0A=249; // 4 u sec * 250 = 1ms
// Turn on Enable Interrupt 
}

/* This delays the program an amount specified by unsigned int delay.
* Use timer 0. Keep in mind that you need to choose your prescalar wisely
* such that your timer is precise to 1 millisecond and can be used for
* 100-2000 milliseconds
*/
void delayMs(unsigned int delay){
       int counter = 0;
    while(counter < delay){
        TIFR0|=(1<<OCF0A);
        TCNT0=0;
        while (!(TIFR0&(1<<OCF0A)))
            counter++;
    }
}




// ------------- main led timer delay -------------- //
void Timer_100ms(int time_base){
    time_base *= 10;
    int counter=0; 
    // TIFR0|=(1<<OCF0A);//erase the flag/rais it down=1
    while(counter< time_base){
        TIFR0|=(1<<OCF0A);
        TCNT0=0;
while(!(TIFR0&(1<<OCF0A)));// wait loop
counter++;
}

}
// --------------- button delay ------------------- //
void delay_3ms(){
    int counter = 0;
    int max = 3;// creates delay of 3.ms as every flag is 1ms
    while(counter < max){
        TIFR0|=(1<<OCF0A);
        TCNT0=0;
        while (!(TIFR0&(1<<OCF0A)))
            counter++;
    }
}