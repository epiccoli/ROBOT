#include "PIN_MAPPING.h"
#include "IR.h"


//#define ir_pin A0

//create instances of IR sensors
IR IR_test(MUX_1_SIG, MUX_1_S0, MUX_1_S1, MUX_1_S2, MUX_1_S3, C15, ShortRange, 25);
IR IR_test2(MUX_1_SIG, MUX_1_S0, MUX_1_S1, MUX_1_S2, MUX_1_S3, C0, LongRange, 25);
//IR IR_test(ir_pin, ShortRange, 25);


void setup() {
  Serial.begin(9600);
  
    pinMode(MUX_1_SIG, INPUT);

    pinMode(MUX_1_S0, OUTPUT); 
    pinMode(MUX_1_S1, OUTPUT); 
    pinMode(MUX_1_S2, OUTPUT); 
    pinMode(MUX_1_S3, OUTPUT);
  
// setupIR_MUX();
//  pinMode(ir_pin, INPUT);
}

void loop() {
    
    int val = IR_test.getDistance();  
    Serial.println("val");
    Serial.println(val);
    int val2 = IR_test2.getDistance();
    Serial.println("val2");  
    Serial.println(val2);
    delay(200);

}
