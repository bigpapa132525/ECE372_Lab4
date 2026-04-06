#include "adc.h"
#include <avr/io.h>

void initADC(){

    ADMUX = 0;
    ADCSRB = 0;
    ADCSRA = 0;

    // AVCC reference
    ADMUX |= (1 << REFS0);

    // right justified
    ADMUX &= ~(1 << ADLAR);

    // ADC0 selected -> MUX[4:0] = 00000
    ADMUX &= ~((1 << MUX4) | (1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
    ADCSRB &= ~(1 << MUX5);

    // enable ADC, auto trigger, prescaler 128
    ADCSRA |= (1 << ADEN) | (1 << ADATE);
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

    // free running
    ADCSRB &= ~((1 << ADTS2) | (1 << ADTS1) | (1 << ADTS0));

    // disable digital input on ADC0
    DIDR0 |= (1 << ADC0D);

    // start conversion
    ADCSRA |= (1 << ADSC);
}