#include "IR.h"

void setup() {
  Serial.begin(9600);
  void setupIR_MUX();
}

void loop() {
  
//  int val = 0;
  
//  for(int count = 0; count<1000; count++){
//    val = val + readIR(10);
//    Serial.println(val);
//  }
  
//  val = val/1000;

  for(int j =0;j<10;j++){
    int val = readIR(1);  
  //  Serial.println(val);
    delay(250);
  }
}
