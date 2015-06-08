#include "Bumpers.h"

void SetupBumpers() {
    // put bumper pins as inputs
    
    // Front bumpers_old
    //bumpBDDR &= ~ (bumpBPins);
    
    bumpCDDR &= ~ (bumpCPins);
    bumpKDDR &= ~ (bumpKPins);
    
    // set pullup resistors
    //bumpBPORT |= (bumpBPins);
    bumpCPORT |= (bumpCPins);
    bumpKPORT |= (bumpKPins);

    
    // set 2 pins C7 and C6 to  ground
    pinMode(ground1,OUTPUT);
    pinMode(ground2,OUTPUT);
    digitalWrite(ground1,LOW);
    digitalWrite(ground2,LOW);
    
    // -------------------------------------------------------
    // Setup external interrupt control registers
    // -------------------------------------------------------
    /*
    
    // Set all to interrupt on falling edge (when bumper is pressed):
    //   ICSn0 = 0, ICSn1 = 1 -- falling edge
    // EICRA controls INT3:0, EICRB controls INT7:4
    
    EICRB |= ((1 << ISC41) | (1 << ISC51));
    EICRB &= ~ ((1 << ISC40) | (1 << ISC50));
    
    // Enable bits in external interrupt mask to activate interrupts
    EIMSK |= (bumpBPins);
    
    
    */
    // -------------------------------------------------------
    // Setup pin change interrupt control registers
    // -------------------------------------------------------
    
    // Set PCIE0 bit in pin change control register to enable interrupts
    // for PCINT7:0
    PCICR |= (1 << PCIE0); // PC interrupts 0 to 7
    PCICR |= (1 << PCIE2); // PC interrupts 16 to 23
    // Set appropriate bits in pin change mask register 0 to enable
    // interrupts *only* on desired pins
    PCMSK0 |= (bumpCPins);
    PCMSK2 |= (bumpKPins);

    
    // Enable global interrupts
    sei();
    
}




// -------------------------------------------------------
// INTERRUPT SUB ROUTINES FOR BUMPERS
// -------------------------------------------------------

// -------------------------------------------------------
// External interrupt subroutines
// -------------------------------------------------------


// Front bumpers_old
/*ISR (bumpB1vect) {
    Serial.println("Bumper Front_Left triggered");
}

ISR (bumpB2vect) {
    Serial.println("Bumper Front_Right triggered");
}*/


// -------------------------------------------------------
// Pin change interrupt subroutines
// -------------------------------------------------------

/*
ISR ( bumpKvect ) {
    // Check which pins are 0 - these bumpers are pressed
    // Note that these are not necessarily the pins that
    // triggered the interrupt but we don't care, just want
    // to know which bumpers are activated
    //Serial.println("Pin Change Interrupt");
    if (~(bumpKIN) & (1 << bumpK1)){
        Serial.println("Bumper Front_Left triggered");
        bumpKPORT |= (1<<bumpK1);
    }
    
    if (~(bumpKIN) & (1 << bumpK2)){
        Serial.println("Bumper Front_Right triggered");
        bumpKPORT |= (1<<bumpK2);
    }
    _state=AVOID;
}

ISR ( bumpCvect ) {
    // Check which pins are 0 - these bumpers are pressed
    // Note that these are not necessarily the pins that
    // triggered the interrupt but we don't care, just want
    // to know which bumpers are activated
    //Serial.println("Pin Change Interrupt");
    if (~(bumpCIN) & (1 << bumpC1))
        Serial.println("Bumper Left_Back triggered");
    if (~(bumpCIN) & (1 << bumpC2))
        Serial.println("Bumper Right_Front triggered");
    if (~(bumpCIN) & (1 << bumpC3))
        Serial.println("Bumper Left_Front triggered");
    if (~(bumpCIN) & (1 << bumpC4))
        Serial.println("Bumper Back_Left triggered");
    if (~(bumpCIN) & (1 << bumpC5))
        Serial.println("Bumper Right_Back triggered");
    if (~(bumpCIN) & (1 << bumpC6))
        Serial.println("Bumper Back_Right triggered");
}
 */
