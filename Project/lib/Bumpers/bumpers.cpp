#include "bumpers.h"

void SetupBumpers() {
  // put bumper pins as inputs
  bumpADDR &= ~ (bumpAPins);
  bumpBDDR &= ~ (bumpBPins);
  bumpCDDR &= ~ (bumpCPins);

  // set pullup resistors
  bumpAPORT |= (bumpAPins);
  bumpBPORT |= (bumpBPins);
  bumpCPORT |= (bumpCPins);



  // -------------------------------------------------------
  // Setup external interrupt control registers
  // -------------------------------------------------------


  // Set all to interrupt on falling edge (when bumper is pressed):
  //   ICSn0 = 0, ICSn1 = 1 -- falling edge
  // EICRA controls INT3:0, EICRB controls INT7:4

  EICRA |= ((1 << ISC21) | (1 << ISC31));
  EICRA &= ~ ((1 << ISC20) | (1 << ISC30));

  EICRB |= ((1 << ISC41) | (1 << ISC51));
  EICRB &= ~ ((1 << ISC40) | (1 << ISC50));

  // Enable bits in external interrupt mask to activate interrupts
  EIMSK |= ((bumpAPins) | (bumpBPins));



  // -------------------------------------------------------
  // Setup pin change interrupt control registers
  // -------------------------------------------------------

  // Set PCIE0 bit in pin change control register to enable interrupts
  // for PCINT7:0
  PCICR |= (1 << PCIE0);

  // Set appropriate bits in pin change mask register 0 to enable
  // interrupts *only* on desired pins
  PCMSK0 |= (bumpCPins);


  // Enable global interrupts
  sei();

}




// -------------------------------------------------------
// INTERRUPT SUB ROUTINES FOR BUMPERS
// -------------------------------------------------------

// -------------------------------------------------------
// External interrupt subroutines
// -------------------------------------------------------

ISR (bumpA1vect) {
  Serial.println("Bumper A1 triggered");
}

ISR (bumpA2vect) {
  Serial.println("Bumper A2 triggered");
}

ISR (bumpB1vect) {
  Serial.println("Bumper B1 triggered");
}

ISR (bumpB2vect) {
  Serial.println("Bumper B2 triggered");
}

// -------------------------------------------------------
// Pin change interrupt subroutines
// -------------------------------------------------------
ISR ( bumpCvect ) {
  // Check which pins are 0 - these bumpers are pressed
  // Note that these are not necessarily the pins that
  // triggered the interrupt but we don't care, just want
  // to know which bumpers are activated
  //Serial.println("Pin Change Interrupt");
  if (~(bumpCIN) & (1 << bumpC1))
    Serial.println("Bumper C1 triggered");
  if (~(bumpCIN) & (1 << bumpC2))
    Serial.println("Bumper C2 triggered");
  if (~(bumpCIN) & (1 << bumpC3))
    Serial.println("Bumper C3 triggered");
  if (~(bumpCIN) & (1 << bumpC4))
    Serial.println("Bumper C4 triggered");
  if (~(bumpCIN) & (1 << bumpC5))
    Serial.println("Bumper C5 triggered");
  if (~(bumpCIN) & (1 << bumpC6))
    Serial.println("Bumper C6 triggered");
}
