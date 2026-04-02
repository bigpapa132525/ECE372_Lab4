#include "adc.h"
#include <avr/io.h>

void initADC(){
    //1) AVCC = 5V output.
        ADMUX |= (1 << REFS0);
        ADMUX &= ~(1 << REFS1);

    //2) determine left or right justified (ADLAR = 0 RIGHT JUSTIFIED)
        ADMUX &= ~(1 << ADLAR);

    //3) Set ADC7 as single-ended input with MUX[5:0] = 0b000000 at a0
        ADMUX &= ~((1 << MUX4) | (1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
        ADCSRB &= ~(1 << MUX5);
    
    //4) Enable ADC 
    //5) Enable auto-triggering
        ADCSRA|= (1 << ADEN) | (1 << ADATE);

    //6) Set auto trigger Source Selection use free-running mode ADTS[2:0] = 0b000
        ADCSRB &= ~((1 << ADTS2) | (1 << ADTS1) | (1 << ADTS0));

    //7) Set Auto Trigger Source Selection
    // ADC clock frequency is 16 Mhz divided by pre-scaler = 125KHz
    // Sampling rate is fs=13 f_ADC = (13 clock cycles)*125K Hz = 9.615 KHz
        ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

    //8)Enable the analog i/p for ADC pins and disable ADC0 pin digital input - pin A0 on board
        DIDR0 |= (1 << ADC7D);
    //9) Start ADC conversion
    // start the first ADC conversion
        ADCSRA |= ( 1 << ADSC);
}
