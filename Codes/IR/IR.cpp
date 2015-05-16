#include <Arduino.h>
#include <IR.h>

void setupIR_MUX(){
    pinMode(s0, OUTPUT); 
    pinMode(s1, OUTPUT); 
    pinMode(s2, OUTPUT); 
    pinMode(s3, OUTPUT); 

    digitalWrite(s0, LOW);
    digitalWrite(s1, LOW);
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);

//  Serial.begin(9600);
}

int readIR(int IR_number){
    
    int IR_out = 0;
    
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
 
    // read analog out from mux
    IR_out = analogRead(SIG_pin);
    
    return IR_out;
    
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