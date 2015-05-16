#include "IR.h"

void setup() {
  Serial.begin(9600);
  void setupIR_MUX();
  
}

void loop() {
  
    SharpIR IR_no_1(1, 25, 7, model_1);
    int val = IR_no_1.distance();  
    Serial.println(val);
    delay(25);

}
