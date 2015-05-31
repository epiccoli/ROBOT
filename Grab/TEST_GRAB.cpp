#include "DynamixelSerial.h"
#include "RobotComp_HardwareTests.h"

void testDynamixel(){

  Serial.println("Enter the ID of your dynamixel servo (number at the back)");
  Serial.print("> ");
  Serial.setTimeout(1200); //leave time to type number
  while(Serial.available() == 0){ //wait for user to enter key
  }
  int DYMX_ID = Serial.parseInt(); // reads ID
  Serial.println(String(DYMX_ID)+"\n\r"); //print entered key
  FlushInput();
  Serial.setTimeout(100); //reset

  //******* setup ****************
  // Serial.begin(9600);
  Dynamixel.begin(1000000,2);  // Initialize the servo at 1Mbps and Pin Control 2
  Dynamixel.setEndless(DYMX_ID, OFF); // disables continuous rotation
  Dynamixel.moveSpeed(DYMX_ID, 0, 1023); //sets angular position to zero
  delay(1000);
  //******************************

  //******* LOOP ******************
  // position test
  Serial.println("The servo should go fast to position 180° and return slowly to 0° ");
  Serial.println("Press a key to go to the continuous rotation test\n");
  Serial.print("> ");
  while(Serial.available() == 0){ //wait for user to enter key
    Dynamixel.moveSpeed(DYMX_ID, 614, 1023); //move to 180°
    delay(2000);
    Dynamixel.moveSpeed(DYMX_ID, 0, 150); // come back slowly to 0°
    delay(3000);
  }
  Serial.println(Serial.readString()+"\n\r"); //print entered key
  FlushInput();

  // continous rotation test
  Serial.println("The servo should now turn continously: fast counter-clockwise and then slowly clockwise");
  Serial.println("Press a key to go to end the test\n");
  Serial.print("> ");
  while(Serial.available() == 0){ //wait for user to enter key
    Dynamixel.setEndless(DYMX_ID, ON); // enables continuous rotation
    Dynamixel.turn(DYMX_ID, LEFT, 1023);
    delay(2500);
    Dynamixel.turn(DYMX_ID, RIGTH, 300);
    delay(3000);
  }
  //*************************************
  Serial.println(Serial.readString()+"\n\r"); //print entered key
  FlushInput();
  Dynamixel.setEndless(DYMX_ID, OFF); // stops continuous rotation
  
}


