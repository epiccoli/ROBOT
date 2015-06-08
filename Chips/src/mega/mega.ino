#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <Robot.h>
#include <Motor.h>
#include <MUX.h>
#include <IR.h>
#include "Bumpers.h"
#include <mega_constants.h>
#include <Wire.h>
#include "Communications.h"
#include <Arms.h>
#include <DynamixelSerial.h>
//#include "BluetoothController.h"

Robot Spazzino;

void setup()
{ 
  delay(200);
  
  Wire.begin();
<<<<<<< HEAD
  Serial.begin(BRATE); 
=======
   
//  Serial.begin(9600); 
//  Serial.begin(BRATE); //Serial1.begin(9600);
//  Spazzino.setState(SEARCH);
>>>>>>> a2282cc24b4b21f3899a54f55b9e58bf7672126c
  
  delay(50);
  Serial.println("Start...");
  // Activate interrupts for bumpers
  SetupBumpers();
}

void loop()
{
  Spazzino.executeState();
}



