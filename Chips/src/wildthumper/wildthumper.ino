#include <avr/io.h>
#include <avr/interrupt.h>    // Needed to use interrupts  
#include "IOpins.h"
#include <Wire.h>

#include "WildThumper.h"
#include "Motor.h"
#include "Encoders.h"
#include "Communications.h"

WildThumper WildThumper_board;
Motor MotorLeft;
Motor MotorRight;
int test_speed = 70;

void setup() {
  Wire.begin(WILDTHUMPER_ADDRESS); // join i2c bus with address wildthumper_address
  Wire.onReceive(receiveEvent); // function that executes whenever data is received from master
  Serial.begin(BRATE);

  WildThumper_board.init();
  MotorLeft.init(LmotorA, LmotorB, LmotorC);
  MotorRight.init(RmotorA, RmotorB, RmotorC);

  EncoderSetup();

  Serial.println(WildThumper_board.battery());

  pinMode(A3, INPUT_PULLUP);

}
void loop() {
  //Serial.println("New loop");

  WildThumper_board.control_state();          //Control battery and maxcurrent

  MotorLeft.lastoverloadtime = WildThumper_board.leftoverload;
  MotorRight.lastoverloadtime = WildThumper_board.rightoverload;

  if (1) { //WildThumper_board.Charged == 1){                   // Only power motors if battery voltage is good

    //if(!digitalRead(A3)) {
    MotorLeft.set_speed(-getSpeed(LEFT));
    MotorRight.set_speed(getSpeed(RIGHT));
  }
  else {
    MotorLeft.turn_off();
    MotorRight.turn_off();
  }

}



