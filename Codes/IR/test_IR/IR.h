#ifndef IR_H_INCLUDED
#define IR_H_INCLUDED

#include <Arduino.h>
#include "SharpIR.h"

// pin mapping

//Mux control pins
#define		s0		22		//value of select pin at Arduino MEGA (s0)
#define		s1		24      //value of select pin Arduino MEGA (s1)
#define		s2		26      //value of select pin Arduino MEGA (s2)
#define		s3		28      //value of select pin Arduino MEGA (s3)

//Mux in "SIG" pin
#define		SIG_pin		A0		//value of select pin Arduino MEGA (common)

#define    model_1    1080


void setupIR_MUX();

//int readIR(int IR_number);

bool isObstacle();

bool openArmsOK();
        
bool isBottleInside();
        
bool isBottleInPosition();

//int getDistanceLong(int IRpin);
//
//int getDistanceShort(int IRpin);



#endif // SERIALCLASS_H_INCLUDED

