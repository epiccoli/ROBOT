#ifndef WILDTHUMPER_H
#define WILDTHUMPER_H

#include <Arduino.h>

//=================================== BATTERY CHARGER SETTINGS ======================================================================

#define batvolt            487     // This is the nominal battery voltage reading. Peak charge can only occur above this voltage.
#define lowvolt            410     // This is the voltage at which the speed controller goes into recharge mode.
#define chargetimeout   300000     // If the battery voltage does not change in this number of milliseconds then stop charging.

//=================================== H BRIDGE SETTINGS =============================================================================

#define Leftmaxamps        800     // set overload current for left motor
#define Rightmaxamps       800     // set overload current for right motor
#define Maxamps            800     // set overload current for right motor

//=================================== IOpins SETTINGS =============================================================================

#define LmotorA             3  // Left  motor H bridge, input A
#define LmotorB            11  // Left  motor H bridge, input B
#define RmotorA             5  // Right motor H bridge, input A
#define RmotorB             6  // Right motor H bridge, input B

#define Battery             0  // Analog input 00
#define RmotorC             6  // Analog input 06
#define LmotorC             7  // Analog input 07
#define Charger            13  // Low=ON High=OFF

#define Brate 9600 // address for I2C


class WildThumper {
  public:
  WildThumper();
  ~WildThumper();
  
  void init();
  void control_state();
  
  uint16_t battery(void);
  uint8_t motor_current(int pin);
  uint8_t currentTotal(void);
  uint8_t charging(void);
  
  byte Charged;
  unsigned long leftoverload;
  unsigned long rightoverload;
  
  private:
  
  unsigned int Volts;
  unsigned int LeftAmps;
  unsigned int RightAmps;
  unsigned long chargeTimer;
  int highVolts;
  int startVolts;
};

#endif

