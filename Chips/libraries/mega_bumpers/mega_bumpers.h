#ifndef _BUMPERS_
#define _BUMPERS_
/*
Code to manage 10 bumpers plugged into Arduino Mega. (Pins to use are defined below.)
Pins are set to inputs with pullup resistors. When the bumpers are 
pressed the input should go to ground, triggering an interrupt.

Note that the interrupt functions are likely to be called multiple times each time
a bumper is pressed (because of rebounds).

4 bumpers are managed using external interrupts. (A1-2, B1-2)
6 bumpers are managed using pin change interrupts. (C1-6)


Arduino pins for bumpers:
2: B1
3: B2
10: C5
11: C6
18: A2
19: A1
50: C4
51: C3
52: C2
53: C1


*/



#include <arduino.h>
#include <Wire.h>
#include <avr/io.h>
#include <avr/interrupt.h>


// Define pins for bumpers
// Separated into three registers: bumpA (PD), bumpB (PE), bumpC (PB)
// bumpA and bumpB are INT pins, bumpC are PCINT pins
#define bumpA1 INT2 // front bumper L
#define bumpA2 INT3 // front bumper R

#define bumpB1 INT4 // rear bumper L
#define bumpB2 INT5 // rear bumper R

#define bumpC1 PCINT0 // right bumper 1 (front)
#define bumpC2 PCINT1 // right bumper 2 (middle)
#define bumpC3 PCINT2 // right bumper 3 (rear)
#define bumpC4 PCINT3 // left bumper 1 (front)
#define bumpC5 PCINT4 // left bumper 2 (middle)
#define bumpC6 PCINT5 // left bumper 3 (rear)

#define bumpAPins ((1<<bumpA1) | (1<<bumpA2))
#define bumpBPins ((1<<bumpB1) | (1<<bumpB2))
#define bumpCPins ((1<<bumpC1) | (1<<bumpC2) | (1<<bumpC3) | (1<<bumpC4) | (1<<bumpC5) | (1<<bumpC6))

// Define registers for bumpers
#define bumpAIN PIND
#define bumpADDR DDRD
#define bumpAPORT PORTD

#define bumpBIN PINE
#define bumpBDDR DDRE
#define bumpBPORT PORTE

#define bumpCIN PINB
#define bumpCDDR DDRB
#define bumpCPORT PORTB


// Define interrupt vectors for bumpers
#define bumpA1vect INT2_vect
#define bumpA2vect INT3_vect

#define bumpB1vect INT4_vect
#define bumpB2vect INT5_vect

#define bumpCvect PCINT0_vect

void SetupBumpers();


#endif
