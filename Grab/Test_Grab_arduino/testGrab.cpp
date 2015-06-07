#include "testGrab.h"

void testGrab(){
	// Serial.begin(9600) // needed?
	

	Dynamixel.moveSpeed(ID_dyn,0,1023); // Sets angular position to zero (resets?)
        delay(2000);
	Dynamixel.moveSpeed(ID_dyn,1000,1023); 

        int pos = Dynamixel.readPosition(ID_dyn);
        Serial.println(pos);
}