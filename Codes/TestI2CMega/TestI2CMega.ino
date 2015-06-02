#include "Wire.h"
int motor_left = -8; // 
int motor_right = 8; // 
#define wildthumper_address 1 // address of board

void setup() {
  Wire.begin(); // join i2c bus as a master
  Serial.begin(9600);
}

void loop() {

  Wire.beginTransmission(wildthumper_address); // alert device that something is coming
  Wire.write(motor_left); // sent data
  Wire.write(motor_right); // sent data
  Wire.endTransmission(); // end transaction - i2c free again.
  
  //motor_left = (motor_left + 1) % 2;
  //motor_right = (motor_right + 1) % 2;
  delay(10);

  Serial.print(motor_right);
  Serial.print(" ");
  Serial.println(motor_left);
}
