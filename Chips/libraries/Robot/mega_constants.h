#ifndef MEGA_CONSTANTS_INCLUDED
#define MEGA_CONSTANTS_INCLUDED

#include "IR.h"

enum STATE
{
  INITIALIZE,
  SEARCH,
  AVOID,
  APPROACH,
  GRAB,
  DROPOFF,
  DROPOFF_AVOID,
};


#define TIMER_MAX  9	*60*1000 // in milliseconds
#define BOTTLE_MAX  5


// Arduino Mega Pin mapping
// TODO: Pin mapping need to be thoroughly thought out and completed

//MUX to Arduino Mega analog pins
#define		MUX_1_SIG	A0
#define		MUX_2_SIG	A1

//MUX to Arduino Mega digital pins
#define		MUX_1_S0		22
#define		MUX_1_S1		24
#define		MUX_1_S2		26
#define		MUX_1_S3		28

#define		MUX_2_S0		23
#define		MUX_2_S1		25
#define		MUX_2_S2		27
#define		MUX_2_S3		29

//MUX analog pins to IR sensors
#define		C0		0
#define		C1		1
#define		C2		2
#define		C3		3
#define		C4		4
#define		C5		5
#define		C6		6
#define		C7		7
#define		C8		8
#define		C9		9
#define		C10		10
#define		C11		11
#define		C12		12
#define		C13		13
#define		C14		14
#define		C15		15

//Define IR sensor types
#define 	LongRange 	1
#define 	ShortRange	2

#endif