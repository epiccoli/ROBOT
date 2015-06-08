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
  
  Serial.begin(BRATE); 
  Wire.begin();

  Serial.print("Start");
  // Activate interrupts for bumpers
  SetupBumpers();
}

void loop()
{
  Spazzino.run();
  //Spazzino.executeState();
  delay(10);
}


ISR ( bumpCvect ) {
    // Check which pins are 0 - these bumpers are pressed
    // Note that these are not necessarily the pins that
    // triggered the interrupt but we don't care, just want
    // to know which bumpers are activated
    if (~(bumpCIN) & (1 << bumpC1))
        Serial.println("Bumper Left_Back triggered");
        Spazzino.setBumperHit(4);
    if (~(bumpCIN) & (1 << bumpC2))
        Serial.println("Bumper Right_Front triggered");
        Spazzino.setBumperHit(3);
    if (~(bumpCIN) & (1 << bumpC3))
        Serial.println("Bumper Left_Front triggered");
        Spazzino.setBumperHit(4);
    if (~(bumpCIN) & (1 << bumpC4))
        Serial.println("Bumper Back_Left triggered");
        Spazzino.setBumperHit(2);
    if (~(bumpCIN) & (1 << bumpC5))
        Serial.println("Bumper Right_Back triggered");
        Spazzino.setBumperHit(3);
    if (~(bumpCIN) & (1 << bumpC6))
        Serial.println("Bumper Back_Right triggered");
        Spazzino.setBumperHit(2);
        
        
    Spazzino.setState(AVOID);
}

ISR ( bumpKvect ) {
    if (~(bumpKIN) & (1 << bumpK1)){
        Serial.println("Bumper Front_Left triggered");
        Spazzino.setBumperHit(1);
        bumpKPORT |= (1<<bumpK1);
    }
    
    if (~(bumpKIN) & (1 << bumpK2)){
        Serial.println("Bumper Front_Right triggered");
        Spazzino.setBumperHit(1);
        bumpKPORT |= (1<<bumpK2);
    }
    
    Spazzino.setState(AVOID);
}


