#include <Arduino.h>
#include "Robot.h"
#include "IR.h"
#include "Bumpers.h"


void setup()
{
  Serial.begin(115200); //Serial1.begin(9600);

  delay(5000);
  Serial.println("Start...");

}

void loop()
{
  //Test loops//

  //Test IR sensors
  int val = IR_test.getDistance();  
  Serial.println("val");
  Serial.println(val);
  int val2 = IR_test2.getDistance();
  Serial.println("val2");  
  Serial.println(val2);
  delay(200);


}


