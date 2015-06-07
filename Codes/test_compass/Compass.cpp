#include "Compass.h"

Compass::Compass(int uart, int bRate) {
    
    memset(valuebyte, 0, 8);
    angle = 0;
    count = 0;
    value = 0;

    m_uart = uart; 
    m_bRate = bRate;
    

    // Setup of baud rate for compass UART
    switch (m_uart) {
        case 0:
            Serial.begin(m_bRate);
            break;
        case 1: 
            Serial1.begin(m_bRate);
            break;
        case 2:
            Serial2.begin(m_bRate);
            break;
        case 3:
            Serial3.begin(m_bRate);
            break;
    }    
}

int Compass::readAngle() {
    count = 0;
    value = 0;

    switch (m_uart) {
        case 0:
            Serial.write(0x31);
            while (value == 0) {
                if (Serial.available()) {
                    valuebyte[count] = Serial.read();
                    count = (count + 1) % 8;
                    if (count == 0) {
                        angle = (valuebyte[2] - 48) * 100 + (valuebyte[3] - 48) * 10 + (valuebyte[4] - 48);
                        value = 1;
                    }
                }
            }
            break;
        case 1: 
            Serial1.write(0x31);
            while (value == 0) {
                if (Serial1.available()) {
                    valuebyte[count] = Serial1.read();
                    count = (count + 1) % 8;
                    if (count == 0) {
                        angle = (valuebyte[2] - 48) * 100 + (valuebyte[3] - 48) * 10 + (valuebyte[4] - 48);
                        value = 1;
                    }
                }
            }
            break;
        case 2:
            Serial2.write(0x31);
            while (value == 0) {
                if (Serial2.available()) {
                    valuebyte[count] = Serial2.read();
                    count = (count + 1) % 8;
                    if (count == 0) {
                        angle = (valuebyte[2] - 48) * 100 + (valuebyte[3] - 48) * 10 + (valuebyte[4] - 48);
                        value = 1;
                    }
                }
            }
            break;
        case 3:
            Serial3.write(0x31);
            while (value == 0) {
                if (Serial3.available()) {
                    valuebyte[count] = Serial3.read();
                    count = (count + 1) % 8;
                    if (count == 0) {
                        angle = (valuebyte[2] - 48) * 100 + (valuebyte[3] - 48) * 10 + (valuebyte[4] - 48);
                        value = 1;
                    }
                }
            }
            break;
    }


    // Serial3.write(0x31);
    // while (value == 0) {
    //     if (Serial3.available()) {
    //         valuebyte[count] = Serial3.read();
    //         count = (count + 1) % 8;
    //         if (count == 0) {
    //             angle = (valuebyte[2] - 48) * 100 + (valuebyte[3] - 48) * 10 + (valuebyte[4] - 48);
    //             value = 1;
    //         }
    //     }
    // }

    // Serial.println(angle);
    // delay(300);

    return angle;
}
