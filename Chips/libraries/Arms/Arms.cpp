/* Define a class object for the arms.



*/

// Destructor maybe not needed for arms, but for door only (arms are always functioning)

#include "Arms.h"

Arms::Arms(){
	_ID_leftArm = ID_ARM_LEFT;
	_foldPos_leftArm = FOLD_POS_LEFT;
	_openPos_leftArm = OPEN_POS_LEFT;
	_grabPos_leftArm = GRAB_POS_LEFT;

	_ID_rightArm = ID_ARM_RIGHT;
	_foldPos_rightArm = FOLD_POS_RIGHT;
	_openPos_rightArm = OPEN_POS_RIGHT;
	_grabPos_rightArm = GRAB_POS_RIGHT;
	
	_vel = 160;

	// Dynamixel setup
	Dynamixel.begin(1000000,2);
	Dynamixel.setEndless(_ID_leftArm, OFF);
    Dynamixel.setEndless(_ID_rightArm, OFF);
}



bool Arms::fold(){

	  Dynamixel.moveSpeed(_ID_leftArm,_foldPos_leftArm,_vel);
      Dynamixel.moveSpeed(_ID_rightArm,_foldPos_rightArm,_vel);

      return true;  //TODO: think of stop condition to return false

}


bool Arms::open(){

	Dynamixel.moveSpeed(_ID_leftArm,_openPos_leftArm,_vel);
    Dynamixel.moveSpeed(_ID_rightArm,_openPos_rightArm,_vel);

    return true;
}


bool Arms::grab(){

    Dynamixel.moveSpeed(_ID_leftArm,_grabPos_leftArm,_vel);
    Dynamixel.moveSpeed(_ID_rightArm,_grabPos_rightArm,_vel); 
    
//    int LeftPos = Dynamixel.readPosition(_ID_leftArm);
//    int RightPos = Dynamixel.readPosition(_ID_rightArm);
//    
//    Serial.print("LeftPos: ");
//    Serial.println(LeftPos);
//    Serial.print("RightPos: ");
//    Serial.println(RightPos);
    return true;
}

bool Arms::moveArm() {
       
        int choice = 0;
	Serial.println("LEFT: (<750!!)");
	Serial.print("> "); //curseur
	while(Serial.available() == 0){ //wait for user to enter key
	}
	choice = Serial.parseInt(); // reads choice
	Serial.println(choice); //print choice
	Serial.print("\n"); //space line
	delay(200);

	Dynamixel.moveSpeed(_ID_leftArm,choice,_vel);

	Serial.println("RIGHT: (<800!!)");
	Serial.print("> "); //curseur
	while(Serial.available() == 0){ //wait for user to enter key
	}
	choice = Serial.parseInt(); // reads choice
	Serial.println(choice); //print choice
	Serial.print("\n"); //space line
	delay(200);

	Dynamixel.moveSpeed(_ID_rightArm,choice,_vel); 
        

	return true;

}
 
