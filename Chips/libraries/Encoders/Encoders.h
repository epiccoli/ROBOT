#ifndef _ENCODERS_
#define _ENCODERS_

#include <arduino.h>
#include <wire.h>




#define This_Address      1        // Address of Wildthumper controller board used for I2C

/* PIN MAPPINGS
WILD THUMPER    ATMEGA     ATMEGA ALTERNATE
A1              PC1        PCINT9
A2              PC2        PCINT10
A3              PC3        PCINT11
A4              PC4        PCINT12 ---> SDA 
A5              PC5        PCINT13 ---> SCL

D0              PD0        PCINT16
D1              PD1        PCINT17
D2              PD2        PCINT18/INT0
D4              PD4        PCINT20/XCK/T0
D7              PD7        PCIN23/AIN1
D8              PB0        PCINT0/CLK0/ICP1
D9              PB1        PCINT1/OC1A
D10             PB2        PCINT2/SS/OC1B
D12             PB4        PCINT4/MISO
*/

/* Motors
L1        11
L2        12
R1        13
R2        10
*/

// Variables for encoder
#define EncA_IN PINB // pin of encoder A
#define EncB_IN PIND // pin of encoder B
#define EncA_DDR DDRB // data direction register of encoder A
#define EncB_DDR DDRD // data direction register of encoder B 

#define EncL1A PCINT0 // D8 input pin of encoder A of motor L1
#define EncL2A PCINT1 // D9 input pin of encoder A of motor L2
#define EncR1A PCINT2 // D10 input pin of encoder A of motor R1
#define EncR2A PCINT4 // D12 input pin of encoder A of motor R2

#define EncL1B PIND0 // D0 input pin of encoder B of motor L1
#define EncL2B PIND7 // D7 input pin of encoder B of motor L2
#define EncR1B PIND2 // D2 input pin of encoder B of motor R1
#define EncR2B PIND4 // D4 input pin of encoder B of motor R2

typedef enum{LEFT, RIGHT} side;

#define EncTimerFreq 100 // Frequency for PID, updating position


// Gains for discrete-time PID
#define K1 -5
#define K2 4


void EncoderSetup(void);
/*
Setup of Pin change interrupts for encoder counting
Setup of Timer for getting the encoder measurements at predefined frequency
*/

void receiveEvent(int howMany);

int getDirection(int EncA, int EncB); 
/*
Returns direction of motor 
-1 for backwords
1 for forwards
*/

int getSpeed(side this_side);
/*
Returns speed of motor (0 to 255)
side = 0: left
side = 1: right
*/


#endif
