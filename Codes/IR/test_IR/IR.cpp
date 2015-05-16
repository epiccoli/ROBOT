#include "IR.h"


void setupIR_MUX(){
    pinMode(s0, OUTPUT); 
    pinMode(s1, OUTPUT); 
    pinMode(s2, OUTPUT); 
    pinMode(s3, OUTPUT);
    
    pinMode(SIG_pin, INPUT);
       
//    digitalWrite(s0, LOW);
//    digitalWrite(s1, LOW);
//    digitalWrite(s2, LOW);
//    digitalWrite(s3, LOW);

}

int readIR(int IR_number){
    
    SharpIR IR_test(SIG_pin, 35, 30, model_1);
    
    // select the bit  
    int r0 = bitRead(IR_number,0);        
    int r1 = bitRead(IR_number,1);  
    int r2 = bitRead(IR_number,2);    
    int r3 = bitRead(IR_number,3);
     
    // write bit to mux from digital pins
    digitalWrite(s0, r0);
    digitalWrite(s1, r1);
    digitalWrite(s2, r2);
    digitalWrite(s3, r3);
     
    delay(100);
    // read analog out from mux
    int dist = IR_test.distance();
//    int dist = analogRead(SIG_pin);
//    int dist = getDistanceLong(SIG_pin);
    
    return dist;
    
}


int getDistanceLong(int IRpin) //gets sensor value and maps into distance for long range sensor
{
  int sensorValue;
  int outputValue;    //in cm
  sensorValue = analogRead(IRpin);
  //Serial.print("Sensor value: ");                       
  //Serial.println(sensorValue); 
  if(sensorValue < 134)
    outputValue = 200;    
  else if(sensorValue < 141)
    outputValue = 95;
  else if(sensorValue < 148)
    outputValue = 90;  
  else if(sensorValue < 155)
    outputValue = 85; 
  else if(sensorValue < 164)
    outputValue = 80;
  else if(sensorValue < 176)
    outputValue = 75;
  else if(sensorValue < 195)
    outputValue = 70;    
  else if(sensorValue < 209)
    outputValue = 65;
  else if(sensorValue < 221)
    outputValue = 60;    
  else if(sensorValue < 243)
    outputValue = 55;
  else if(sensorValue < 266)
    outputValue = 50;
  else if(sensorValue < 292)
    outputValue = 45;
  else if(sensorValue < 321)
    outputValue = 40;
  else if(sensorValue < 350)
    outputValue = 37;
  else if(sensorValue < 380)
    outputValue = 34;
  else if(sensorValue < 411)
    outputValue = 31;
  else if(sensorValue < 443)
    outputValue = 28;
  else if(sensorValue < 477)
    outputValue = 25;
  else if(sensorValue < 510)
    outputValue = 22;
  else if(sensorValue < 536)
    outputValue = 19;
  else
    outputValue = 0;
  return outputValue;                     
}

int getDistanceShort(int IRpin) //gets sensor value and maps into distance for short range sensor
{
  int sensorValue;
  int outputValue;    
  sensorValue = analogRead(IRpin);
  //Serial.print("Sensor value: ");                       
  //Serial.println(sensorValue); 
  if(sensorValue < 82)
    outputValue = 140;   
  else if(sensorValue < 84)
    outputValue = 65;
  else if(sensorValue < 88)
    outputValue = 60;    
  else if(sensorValue < 94)
    outputValue = 55;
  else if(sensorValue < 102)
    outputValue = 50;
  else if(sensorValue < 113)
    outputValue = 45;
  else if(sensorValue < 124)
    outputValue = 40;
  else if(sensorValue < 135)
    outputValue = 37;
  else if(sensorValue < 146)
    outputValue = 34;
  else if(sensorValue < 159)
    outputValue = 31;
  else if(sensorValue < 174)
    outputValue = 28;
  else if(sensorValue < 192)
    outputValue = 25;
  else if(sensorValue < 215)
    outputValue = 22;
  else if(sensorValue < 241)
    outputValue = 19;
  else if(sensorValue < 269)
    outputValue = 17;
  else if(sensorValue < 301)
    outputValue = 15;
  else if(sensorValue < 344)
    outputValue = 13;
  else if(sensorValue < 398)
    outputValue = 11;
  else if(sensorValue < 465)
    outputValue = 9;
  else if(sensorValue < 559)
    outputValue = 7;
  else if(sensorValue < 625)
    outputValue = 5;
  else
    outputValue = 0;  
  return outputValue;           
}


//void loop(){
//
//  //Loop through and read all 16 values
//  //Reports back Value at channel 6 is: 346
//  for(int i = 0; i < 16; i ++){
//    Serial.print("Value at channel ");
//    Serial.print(i);
//    Serial.print("is : ");
//    Serial.println(readMux(i));
//    delay(1000);
//  }
//
//}
