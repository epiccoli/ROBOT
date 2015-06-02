#include <Arduino.h>
#include <Robot.h>
#include <IR.h>
//#include <mega_bumpers.h>
#include <mega_constants.h>
#include <Wire.h>

Robot Spazzino;

void setup()
{
  Spazzino.executeState();
  Serial.begin(115200); //Serial1.begin(9600);
  STATE thisState = SEARCH;
  //Spazzino.setState(SEARCH);
  delay(5000);
  Serial.println("Start...");

}

void loop()
{
  Spazzino.executeState();

  //Test IR sensors

  delay(200);
}



