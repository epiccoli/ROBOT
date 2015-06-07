#include "Arms.h"

#define ID 1

  Arms leftArm(ID,600,500);

void setup()

{
  Serial.begin(9600);
 
}

void loop()

{
   // create one Arm object

  //testGrab();
//  delay(200);
//  Dynamixel.moveSpeed(ID,970,500);     // position=970 : L is vertical for door --> position = 800: door is open
//  delay(200);
//  Dynamixel.moveSpeed(ID,800,500);     // position=970 : L is vertical for door --> position = 800: door is open
//  Serial.println("I executed the function");
    bool isOk=leftArm.fold();
    Serial.println(isOk);
}




