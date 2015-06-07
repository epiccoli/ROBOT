/* Define a class object for the arms.



*/

// NEED TO INCLUDE #include "DynamixelSerial.h"
// Destructor maybe not needed for arms, but for door only (arms are always functioning)

#include "Arms.h"

Arms::Arms(int ID, int foldPos){//, int openPos, int grabPos){
	_ID = ID;
	_foldPos = foldPos;
	// _openPos = openPos;
	// _grabPos = grabPos;

	// Dynamixel setup
	Dynamixel.begin(1000000,2);
	Dynamixel.setEndless(_ID, OFF);
}

bool Arms::fold(){

	  Dynamixel.moveSpeed(_ID,_foldPos,_speed); 

}


// bool Arms::open(){

// }


// bool Arms::grab(){

// }



private: 
	int ID;				// ID of dynamixel servo
	int openPos;		// position for opening (to set in Dynamixel.moveSpeed(ID,pos,speed))
	int foldPos;		// *
	int grabPos;		// *
}; 