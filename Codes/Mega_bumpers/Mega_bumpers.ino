#include <Wire.h>
#include "bumpers.h"

#define Brate 9600

void setup() {
  Serial.begin(Brate);
  SetupBumpers();
}


void loop() {
  
}
