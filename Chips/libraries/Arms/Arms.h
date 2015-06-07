/* Define a class object for the arms.

need to do: 

calibrate the dynamixel


*/


#ifndef ARMS_INCLUDED
#define ARMS_INCLUDED

#include <Arduino.h>
#include "DynamixelSerial.h"


#define ID_ARM_LEFT 7

#define OPEN_POS_LEFT 850
#define FOLD_POS_LEFT 550
#define GRAB_POS_LEFT 300
#define MAX_LEFT 750

#define ID_ARM_RIGHT 1 // it is written 6

#define OPEN_POS_RIGHT 300
#define FOLD_POS_RIGHT 570
#define GRAB_POS_RIGHT 820
#define MAX_RIGHT 930

class Arms
{
public:
	Arms(); 
	/* when the constructor is activated, it does not compile giving "In function `setup':
/Users/emilepiccoli/Test_Grab_arduino.ino:11: undefined reference to `Arms::~Arms()' 
collect2: error: ld returned 1 exit status Error compiling. */

    // ~Arms();

	// Functions needed: bool only to return if all is OK
	bool fold();
	bool open();
	bool grab();
	bool moveArm();



private: 
	int _ID_leftArm;                // ID of dynamixel servo
	int _foldPos_leftArm;		// position for folding arms 
	int _openPos_leftArm;		// position for opening (to set in Dynamixel.moveSpeed(ID,pos,speed))		
	int _grabPos_leftArm;		// *

    int _ID_rightArm;	        // ID of dynamixel servo
    int _foldPos_rightArm;		// position for folding arms 
	int _openPos_rightArm;		// position for opening (to set in Dynamixel.moveSpeed(ID,pos,speed))		
	int _grabPos_rightArm;		// *

	int _vel;			// set the dynamixel speed 0-1023
	//int _velGrab;		// set the dynamixel speed for grabbing --> where do I put the value if it should stay constant? I put it in the cpp
}; 

#endif // grab_H_INCLUDED
