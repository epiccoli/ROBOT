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
 2:  B1
 3:  B2
 10: C5
 11: C6
 50: C4
 51: C3
 52: C2
 53: C1
 */

#include <arduino.h>
#include <wire.h>
#include <avr/io.h>
#include <avr/interrupt.h>

// Define pins for bumpers
// Separated into three registers: bumpA (PD), bumpB (PE), bumpC (PB)
// bumpA and bumpB are INT pins, bumpC are PCINT pins


// Front bumpers_old
//#define bumpB1 INT4 // Front_Left
//#define bumpB2 INT5 // Front_Right

#define bumpC1 PCINT0 // Left_back
#define bumpC2 PCINT1 // Right_Front
#define bumpC3 PCINT2 // Left_Front
#define bumpC4 PCINT3 // Back_Left
#define bumpC5 PCINT4 // Right_Back
#define bumpC6 PCINT5 // Back_Right

#define bumpK1 PCINT16 // Front_Left
#define bumpK2 PCINT17 // Front_Right

// ground pins
#define ground1 48
#define ground2 49

// Front bumpers_old
//#define bumpBPins ((1<<bumpB1) | (1<<bumpB2))

#define bumpKPins ((1<<bumpK1) | (1<<bumpK2))
#define bumpCPins ((1<<bumpC1) | (1<<bumpC2) | (1<<bumpC3) | (1<<bumpC4) | (1<<bumpC5) | (1<<bumpC6))

// Define registers for bumpers

// Front bumpers_old
//#define bumpBIN PINE
//#define bumpBDDR DDRE
//#define bumpBPORT PORTE

#define bumpKIN PINK
#define bumpKDDR DDRK
#define bumpKPORT PORTK

#define bumpCIN PINB
#define bumpCDDR DDRB
#define bumpCPORT PORTB

// Define interrupt vectors for bumpers

// Front bumpers_old
//#define bumpB1vect INT4_vect
//#define bumpB2vect INT5_vect

#define bumpCvect PCINT0_vect
#define bumpKvect PCINT2_vect

void SetupBumpers();

#endif