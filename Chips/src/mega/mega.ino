#include <Arduino.h>
#include <Robot.h>
#include <Motor.h>
#include <MUX.h>
#include <IR.h>
#include <mega_bumpers.h>
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
  Serial.begin(9600); 
//  Serial.println("Hello");
//  Spazzino.executeState();
  
  Wire.begin();
   
//  Serial.begin(9600); 
//  Serial.begin(BRATE); //Serial1.begin(9600);
//  Spazzino.setState(SEARCH);
  
  delay(50);
  Serial.println("Start...");

}

void loop()
{
  Spazzino.executeState();

//  delay(200000);
}



