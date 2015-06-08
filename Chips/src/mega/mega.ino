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
#include "BluetoothController.h"

Robot Spazzino;

void setup()
{ 
  delay(100);
  
  //Serial.begin(BRATE); 
  Serial.begin(9600);
 // Wire.begin();

  Serial.print("Start");
  // Activate interrupts for bumpers
  SetupBumpers();
}

void loop()
{
  //Serial.print("Loop");
  //delay(100);
  Serial.print("BIDON");
  Spazzino.executeState();
}



