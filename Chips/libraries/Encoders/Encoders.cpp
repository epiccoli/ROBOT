#include "Encoders.h"

int inputValue;
uint8_t portBHistory = 0xFF;
int dir;

uint8_t changedbits;

int8_t PosL1 = 0;
int8_t PosL2 = 0;
int8_t PosR1 = 0;
int8_t PosR2 = 0;

int8_t PosL1_test = 0;
int8_t PosL2_test = 0;

int8_t OldEL = 0;
int8_t EL;
int8_t OldER = 0;
int8_t ER;

int left_speed = 0;
int right_speed = 0;

// Controller
// forward:
//int PosL_target = -30;
//int PosR_target = 30;
// turn left:
//int PosL_target = 15;
//int PosR_target = 15;
// turn right:
//int PosL_target = -15;
//int PosR_target = -15;

int PosL_target = 0;
int PosR_target = 0;

void EncoderSetup() {

  //--------------------Timer---------------------//
  cli();
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0;

  // set timer count for 1 increments
  OCR1A = 16000000 / 8 / EncTimerFreq; // = 16MHz / prescaler / desired frequency
  TCCR1B |= (1 << WGM12); // turn on CTC mode

  // Set CS11 bit for 8 prescaler
  TCCR1B &= ~ ((1 << CS10) | (1 << CS12));
  TCCR1B |= (1 << CS11);

  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);



  //-----------PinChange interrupts---------------//

  // set ADC pins to be digital inputs
  EncA_DDR &= ~ (1 << EncL1A);
  EncA_DDR &= ~ (1 << EncL2A);
  EncB_DDR &= ~ (1 << EncL1B);
  EncB_DDR &= ~ (1 << EncL2B);
  EncA_DDR &= ~ (1 << EncR1A);
  EncA_DDR &= ~ (1 << EncR2A);
  EncB_DDR &= ~ (1 << EncR1B);
  EncB_DDR &= ~ (1 << EncR2B);

  PCICR |= (1 << PCIE0);     // set PCIE1 to enable PCMSK0 scan
  PCMSK0 |= ((1 << EncL1A) | (1 << EncL2A) | (1 << EncR1A) | (1 << EncR2A)) ;   // set mask bits for pins that are plugged into interrupts


  Wire.begin(This_Address);

  Wire.onReceive(receiveEvent);
  sei();

}

int getSpeed(side this_side) {

  if (this_side == RIGHT) return right_speed;
  else return left_speed;
}

int getDirection(int EncA, int EncB) {
  dir = (((EncA_IN & (1 << EncA)) >> EncA) ^ ((EncB_IN & (1 << EncB)) >> EncB));
  if (!dir) dir = -1;
  return dir;
}


//----------PIN CHANGE INTERRUPTS FOR READING ENCODERS----------//
ISR ( PCINT0_vect ) {

  // find out which Pin has triggered interrupt
  changedbits = EncA_IN ^ portBHistory;
  portBHistory = EncA_IN;


  if (changedbits & (1 << EncL1A)) // The bit that has changed corresponds to EncL1A
    PosL1 += getDirection(EncL1A, EncL1B);
  if (changedbits & (1 << EncL2A))
    PosL2 += getDirection(EncL2A, EncL2B);
  if (changedbits & (1 << EncR1A)) // The bit that has changed corresponds to EncL1A
    PosR1 += getDirection(EncR1A, EncR1B);
  if (changedbits & (1 << EncR2A))
    PosR2 += getDirection(EncR2A, EncR2B);
}

//-----TIMER INTERRUPT FOR DOING PID, CALCULATING SPEED ETC.----//
ISR( TIMER1_COMPA_vect ) {

  EL = PosL_target - 0.5 * (PosL1 + PosL2);
  ER = PosR_target - 0.5 * (PosR1 + PosR2);
    
  PosL1_test = PosL1;
  PosL2_test = PosL2;
    

  PosL1 = 0;
  PosL2 = 0;
  PosR1 = 0;
  PosR2 = 0;
    
    

  sei();

  if ((left_speed + K1 * EL + K2 * OldEL) <= 0) {
    left_speed = max(left_speed + K1 * EL + K2 * OldEL, -255);
  }
  else {
    left_speed = min(left_speed + K1 * EL + K2 * OldEL, 255);
  }

  if ((right_speed + K1 * ER + K2 * OldER) <= 0) {
    right_speed = max(right_speed + K1 * ER + K2 * OldER, -255);
  }
  else {
    right_speed = min(right_speed + K1 * ER + K2 * OldER, 255);
  }

  OldEL = EL;
  OldER = ER;
    
  //Serial.print(PosL1_test);
  //Serial.print(" ");
  //Serial.println(PosL2_test);
}

void receiveEvent(int howMany)
{
  //while (Wire.available()) { // loop through all 
    PosL_target = Wire.read(); // receive a byte as an integer
    if (PosL_target > 127) // these values correspond to negative values.
      PosL_target = -(PosL_target - 256); // negative target corresponds to going forwards.
    else
        PosL_target = -PosL_target;
    
    PosR_target = Wire.read(); //
    if (PosR_target > 127) // these values correspond to negative values.
      PosR_target = (PosR_target - 256);
 // }

  Serial.print(PosR_target);
  Serial.print(" ");
  Serial.println(PosL_target);
}

