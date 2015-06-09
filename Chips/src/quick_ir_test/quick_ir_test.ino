#include <Arduino.h>
#include <IR.h>


IR ir_test(A0, 1, 1);

void setup() {
  Serial.begin(9600);

}

void loop() {
  
//  ir_test.getAvgAnalog();
  Serial.println(ir_test.getDistance());

}
