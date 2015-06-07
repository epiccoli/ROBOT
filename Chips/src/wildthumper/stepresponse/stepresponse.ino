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
int test_speed = -150;
int time_counter = 0;

void setup() {
  Wire.begin(WILDTHUMPER_ADDRESS); // join i2c bus with address wildthumper_address
  Wire.onReceive(receiveEvent); // function that executes whenever data is received from master
  Serial.begin(Brate);

  WildThumper_board.init();
  MotorLeft.init(LmotorA, LmotorB, LmotorC);
  MotorRight.init(RmotorA, RmotorB, RmotorC);

  EncoderSetup();
  delay(5000);
  
}
void loop() {
  //Serial.println("New loop");
  MotorLeft.set_speed(-getSpeed(LEFT));
  MotorRight.set_speed(getSpeed(RIGHT));

  WildThumper_board.control_state();          //Control battery and maxcurrent

  MotorLeft.lastoverloadtime = WildThumper_board.leftoverload;
  MotorRight.lastoverloadtime = WildThumper_board.rightoverload;
  if(time_counter < 10000) {
  time_counter++;
  }
  else{
    MotorLeft.turn_off();
    MotorRight.turn_off();
    delay(6000);
  }
}



