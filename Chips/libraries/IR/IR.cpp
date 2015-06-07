#include "IR.h"


// IR::IR(MUX mux(int sig, int s0, int s1, int s2, int s3), int mux_pin, int ir_model, int avg) {
//     m_sig = mux.getSIG();
//     m_s0 = mux.getS0();
//     m_s1 = mux.getS1();
//     m_s2 = mux.getS2();
//     m_s3 = mux.getS3();
//     m_mux_pin = mux_pin;
//     m_analog_pin = -1;
//     m_ir_model = ir_model;
//     m_avg = avg;
// }

IR::IR(int sig, int s0, int s1, int s2, int s3, int mux_pin, int ir_model, int avg){
    m_sig = sig;
    m_s0 = s0;
    m_s1 = s1;
    m_s2 = s2;
    m_s3 = s3;
    m_mux_pin = mux_pin;
    m_analog_pin = -1;
	m_ir_model = ir_model;
	m_avg = avg;

    Serial.begin(9600);

    // Setup of associated MUX pins on Arduino
    pinMode(m_sig, INPUT);

    pinMode(m_s0, OUTPUT); 
    pinMode(m_s1, OUTPUT); 
    pinMode(m_s2, OUTPUT); 
    pinMode(m_s3, OUTPUT);

    // Serial.print("SIG: ");
    // Serial.print(m_sig);
    // Serial.print(", S0: ");
    // Serial.print(m_s0);
    // Serial.print(", S1: ");
    // Serial.print(m_s1);
    // Serial.print(", S2: ");
    // Serial.print(m_s2);
    // Serial.print(", S3: ");
    // Serial.print(m_s3);
    // Serial.print(", MUX pin: ");
    // Serial.print(m_mux_pin);
    // Serial.print(", Analog pin: ");
    // Serial.print(m_analog_pin);
    // Serial.print(", IR model: ");
    // Serial.print(m_ir_model);
    // Serial.print(", avg: ");
    // Serial.println(m_avg);
}


IR::IR(int analog_pin, int ir_model, int avg){
    m_sig = -1;
    m_s0 = -1;
    m_s1 = -1;
    m_s2 = -1;
    m_s3 = -1;
    m_mux_pin = -1;
    m_analog_pin = analog_pin;
    m_ir_model = ir_model;
    m_avg = avg;

    Serial.begin(9600);

    // Setup of pinS on Arduino
    pinMode(m_analog_pin, INPUT);


    // Serial.print("SIG: ");
    // Serial.print(m_sig);
    // Serial.print(", S0: ");
    // Serial.print(m_s0);
    // Serial.print(", S1: ");
    // Serial.print(m_s1);
    // Serial.print(", S2: ");
    // Serial.print(m_s2);
    // Serial.print(", S3: ");
    // Serial.print(m_s3);
    // Serial.print(", MUX pin: ");
    // Serial.print(m_mux_pin);
    // Serial.print(", Analog pin: ");
    // Serial.print(m_analog_pin);
    // Serial.print(", IR model: ");
    // Serial.print(m_ir_model);
    // Serial.print(", avg: ");
    // Serial.println(m_avg);

};


void IR::setAvg(int new_avg) {
    m_avg = new_avg;
}


int IR::readIR(){

    int analog_signal = 0;
    
    if(m_sig != -1){    
        
//        Serial.println("m_mux_pin:");
//        Serial.println(m_mux_pin);
        // select the bit to send to mux
        int r0 = bitRead(m_mux_pin,0);        
        int r1 = bitRead(m_mux_pin,1);  
        int r2 = bitRead(m_mux_pin,2);    
        int r3 = bitRead(m_mux_pin,3);
        
//        Serial.println("r0:");
//        Serial.println(r0);
//        Serial.println("r1:");
//        Serial.println(r1);
//        Serial.println("r2:");
//        Serial.println(r2);
//        Serial.println("r3:");
//        Serial.println(r3);

        digitalWrite(m_s0, r0);
        digitalWrite(m_s1, r1);
        digitalWrite(m_s2, r2);
        digitalWrite(m_s3, r3);
//        
//        Serial.println("r0:");
//        Serial.println(r0);
//        Serial.println("r1:");
//        Serial.println(r1);
//        Serial.println("r2:");
//        Serial.println(r2);
//        Serial.println("r3:");
//        Serial.println(r3);

 
        
        delay(20);
        // read analog signal out from mux
        analog_signal = analogRead(m_sig);
//        Serial.println(analog_signal);

    }else if(m_analog_pin != -1){

        // read analog signal directly from arduino analog
        analog_signal = analogRead(m_analog_pin);
    }
    
    return analog_signal;
    
}

int IR::getAvgAnalog() {

    int analog_signal = 0;

    // reads the average analog signal
    for (int i=0; i<m_avg; i++){
        
        analog_signal += readIR();
    }

    analog_signal = analog_signal/m_avg;

}

int IR::getDistance() {

    int analog_signal = getAvgAnalog();

    // read the corresponding position in a lookup table
 
    int dist = 200; //large default value

    //for LongRangeModel
    if( m_ir_model == 1){

        // if(analog_signal <= 33)  
        //     dist = 180;
        if(analog_signal <= 60)
            dist = 90;
        else if(analog_signal <= 63)
            dist = 85;
        else if(analog_signal <= 71)
            dist = 80;
        else if(analog_signal <= 72)
            dist = 79;
        else if(analog_signal <= 73)
            dist = 78;
        else if(analog_signal <= 74)
            dist = 77;
        else if(analog_signal <= 75)
            dist = 75;
        else if(analog_signal <= 76)
            dist = 74;
        else if(analog_signal <= 77)
            dist = 73;
        else if(analog_signal <= 78)
            dist = 72;
        else if(analog_signal <= 79)
            dist = 71;
        else if(analog_signal <= 80)
            dist = 70;
        else if(analog_signal <= 81)
            dist = 69;
        else if(analog_signal <= 82)
            dist = 68;
        else if(analog_signal <= 83)
            dist = 67;
        else if(analog_signal <= 84)
            dist = 66;
        else if(analog_signal <= 85)
            dist = 65;
        else if(analog_signal <= 87)
            dist = 64;
        else if(analog_signal <= 88)
            dist = 63;
        else if(analog_signal <= 89)
            dist = 62;
        else if(analog_signal <= 90)
            dist = 61;
        else if(analog_signal <= 92)
            dist = 60;
        else if(analog_signal <= 93)
            dist = 59;
        else if(analog_signal <= 94)
            dist = 58;
        else if(analog_signal <= 96)
            dist = 57;
        else if(analog_signal <= 97)
            dist = 56;
        else if(analog_signal <= 99)
            dist = 55;
        else if(analog_signal <= 100)
            dist = 54;
        else if(analog_signal <= 102)
            dist = 53;
        else if(analog_signal <= 104)
            dist = 52;
        else if(analog_signal <= 106)
            dist = 51;
        else if(analog_signal <= 107)
            dist = 50;
        else if(analog_signal <= 109)
            dist = 49;
        else if(analog_signal <= 111)
            dist = 48;
        else if(analog_signal <= 113)
            dist = 47;
        else if(analog_signal <= 115)
            dist = 46;
        else if(analog_signal <= 118)
            dist = 45;
        else if(analog_signal <= 120)
            dist = 44;
        else if(analog_signal <= 122)
            dist = 43;
        else if(analog_signal <= 125)
            dist = 42;
        else if(analog_signal <= 128)
            dist = 41;
        else if(analog_signal <= 130)
            dist = 40;
        else if(analog_signal <= 133)
            dist = 39;
        else if(analog_signal <= 136)
            dist = 38;
        else if(analog_signal <= 140)
            dist = 37;
        else if(analog_signal <= 143)
            dist = 36;
        else if(analog_signal <= 147)
            dist = 35;
        else if(analog_signal <= 150)
            dist = 34;
        else if(analog_signal <= 154)
            dist = 33;
        else if(analog_signal <= 158)
            dist = 32;
        else if(analog_signal <= 163)
            dist = 31;
        else if(analog_signal <= 168)
            dist = 30;
        else if(analog_signal <= 173)
            dist = 29;
        else if(analog_signal <= 178)
            dist = 28;
        else if(analog_signal <= 184)
            dist = 27;
        else if(analog_signal <= 190)
            dist = 26;
        else if(analog_signal <= 196)
            dist = 25;
        else if(analog_signal <= 204)
            dist = 24;
        else if(analog_signal <= 211)
            dist = 23;
        else if(analog_signal <= 220)
            dist = 22;
        else if(analog_signal <= 229)
            dist = 21;
        else if(analog_signal <= 239)
            dist = 20;
        else if(analog_signal <= 250)
            dist = 19;
        else if(analog_signal <= 262)
            dist = 18;
        else if(analog_signal <= 275)
            dist = 17;
        else if(analog_signal <= 290)
            dist = 16;
        else if(analog_signal <= 307)
            dist = 15;
        else if(analog_signal <= 326)
            dist = 14;
        else if(analog_signal <= 347)
            dist = 13;
        else if(analog_signal <= 373)
            dist = 12;
        else if(analog_signal <= 402)
            dist = 11;
        else if(analog_signal <= 437)
            dist = 10;
        else if(analog_signal <= 639)
            dist = 5;
        else
            dist = 0;
    }

    //for ShortRangeModel
    if( m_ir_model == 2){

        if(analog_signal <= 27)
            dist = 70;
        else if(analog_signal <= 33)
            dist = 60;
        else if(analog_signal <= 40)
            dist = 50;
        else if(analog_signal <= 48)
            dist = 45;
        else if(analog_signal <= 50)
            dist = 42;
        else if(analog_signal <= 52)
            dist = 41;
        else if(analog_signal <= 53)
            dist = 40;
        else if(analog_signal <= 55)
            dist = 39;
        else if(analog_signal <= 57)
            dist = 38;
        else if(analog_signal <= 58)
            dist = 37;
        else if(analog_signal <= 60)
            dist = 36;
        else if(analog_signal <= 63)
            dist = 35;
        else if(analog_signal <= 64)
            dist = 34;
        else if(analog_signal <= 67)
            dist = 33;
        else if(analog_signal <= 69)
            dist = 32;
        else if(analog_signal <= 72)
            dist = 31;
        else if(analog_signal <= 77)
            dist = 30;
        else if(analog_signal <= 79)
            dist = 29;
        else if(analog_signal <= 80)
            dist = 28;
        else if(analog_signal <= 84)
            dist = 27;
        else if(analog_signal <= 88)
            dist = 26;
        else if(analog_signal <= 92)
            dist = 25;
        else if(analog_signal <= 96)
            dist = 24;
        else if(analog_signal <= 100)
            dist = 23;
        else if(analog_signal <= 106)
            dist = 22;
        else if(analog_signal <= 114)
            dist = 21;
        else if(analog_signal <= 121)
            dist = 20;
        else if(analog_signal <= 126)
            dist = 19;
        else if(analog_signal <= 133)
            dist = 18;
        else if(analog_signal <= 142)
            dist = 17;
        else if(analog_signal <= 149)
            dist = 16;
        else if(analog_signal <= 161)
            dist = 15;
        else if(analog_signal <= 173)
            dist = 14;
        else if(analog_signal <= 186)
            dist = 13;
        else if(analog_signal <= 198)
            dist = 12;
        else if(analog_signal <= 217)
            dist = 11;
        else if(analog_signal <= 238)
            dist = 10;
        else if(analog_signal <= 265)
            dist = 9;
        else if(analog_signal <= 291)
            dist = 8;
        else if(analog_signal <= 326)
            dist = 7;
        else if(analog_signal <= 383)
            dist = 6;
        else if(analog_signal <= 424)
            dist = 5;
        else if(analog_signal <= 519)
            dist = 4;
        else if(analog_signal <= 606)
            dist = 3;
        else
            dist = 0;
    }

    
    return dist;

}

void IR::printSpecs() {

    delay(200);
    Serial.print("SIG: ");
    Serial.print(m_sig);
    Serial.print(", S0: ");
    Serial.print(m_s0);
    Serial.print(", S1: ");
    Serial.print(m_s1);
    Serial.print(", S2: ");
    Serial.print(m_s2);
    Serial.print(", S3: ");
    Serial.print(m_s3);
    Serial.print(", MUX pin: ");
    Serial.print(m_mux_pin);
    Serial.print(", Analog pin: ");
    Serial.print(m_analog_pin);
    Serial.print(", IR model: ");
    Serial.print(m_ir_model);
    Serial.print(", avg: ");
    Serial.println(m_avg);
}
