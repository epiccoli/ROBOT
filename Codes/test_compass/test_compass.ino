#include "Arduino.h"
#include "Compass.h"

int uart = 3;
int bRate = 9600;
int angle = 0;

Compass my_compass(uart, bRate);

void setup() {

  Serial.begin(9600);

}

void loop() {

  angle = my_compass.readAngle();

}
