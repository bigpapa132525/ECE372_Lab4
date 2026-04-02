// Description: This file implements the initialization of an external
// switch.
//----------------------------------------------------------------------//

#include<avr/io.h>
void switch_init(){
//PB5
DDRB&=~(1<<DDB3); //INPUT
PORTB|=(1<<PORTB3);
//ENABLE INTERRUPTS
PCICR|=(1<<PCIE0);// TURN ON THE VECTOR PCINT0_VECT
PCMSK0|=(1<<PCINT3); // turn on only pCINT5 
}
