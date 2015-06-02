#include "Wire.h"
int motor_left = 0; // 
int motor_right = 0; // 
#define wildthumper_address 1 // address of board

void setup() {
  Wire.begin(wildthumper_address); // join i2c bus with address wildthumper_address
  Wire.onReceive(receiveEvent); // function that executes whenever data is sent by master
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop()
{
  delay(100);
}

void receiveEvent(int howMany)
{
  while (Wire.available()) // loop through all but the last
  {
    motor_left = Wire.read(); // receive a byte as an integer
    motor_right = Wire.read(); // 
  }
    
   Serial.print(motor_right);
   Serial.print(" ");
   Serial.println(motor_left);
}
