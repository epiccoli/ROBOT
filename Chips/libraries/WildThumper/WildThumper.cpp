/// WilThumper library ///

#include "WildThumper.h" //include the declaration for this class

//<<constructor>>
WildThumper::WildThumper(){
}
//<<destructor>>
WildThumper::~WildThumper(){/*nothing to destruct*/}

//init WildThumper
void WildThumper::init(){
	
	Charged = 1;

	pinMode (Charger,OUTPUT);                         // change Charger pin to output
	digitalWrite (Charger,1);                         // disable current regulator to charge battery
}

//Control battery and current
void WildThumper::control_state(){
	Volts = battery();                       // read the battery voltage
	LeftAmps = motor_current(LmotorC);        // read left motor current draw
	RightAmps = motor_current(RmotorC);      // read right motor current draw
	
	if (LeftAmps>Leftmaxamps)                                   // is motor current draw exceeding safe limit
	{
		analogWrite (LmotorA,0);                                  // turn off motors
		analogWrite (LmotorB,0);                                  // turn off motors
		leftoverload = millis();                    // record time of overload
	}

	if (RightAmps>Rightmaxamps)                                 // is motor current draw exceeding safe limit
	{
		analogWrite (RmotorA,0);                                  // turn off motors
		analogWrite (RmotorB,0);                                  // turn off motors
		rightoverload = millis();                   // record time of overload
	}
	
	if ((Volts<lowvolt) && (Charged==1))                        // check condition of the battery
	{                                                           // change battery status from charged to flat

		//---------------------------------------------------------- FLAT BATTERY speed controller shuts down until battery is recharged ----
		//---------------------------------------------------------- This is a safety feature to prevent malfunction at low voltages!! ------

		Charged=0;                                                // battery is flat
		highVolts=Volts;                                          // record the voltage
		startVolts=Volts;
		chargeTimer=millis();                                     // record the time

		digitalWrite (Charger,0);                                 // enable current regulator to charge battery
	}
	
	//------------------------------------------------------------ CHARGE BATTERY -------------------------------------------------------

	if ((Charged==0) && (Volts-startVolts>67))                  // if battery is flat and charger has been connected (voltage has increased by at least 1V)
	{
		if (Volts>highVolts)                                      // has battery voltage increased?
		{
			highVolts=Volts;                                        // record the highest voltage. Used to detect peak charging.
			chargeTimer=millis();                                   // when voltage increases record the time
		}

		if (Volts>batvolt)                                        // battery voltage must be higher than this before peak charging can occur.
		{
			if ((highVolts-Volts)>5 || (millis()-chargeTimer)>chargetimeout) // has voltage begun to drop or levelled out?
			{
				Charged=1;                                            // battery voltage has peaked
				digitalWrite (Charger,1);                             // turn off current regulator
			}
		}
	}
}

uint16_t WildThumper::battery(void){
	return analogRead(Battery);
}

uint8_t WildThumper::motor_current(int pin){
	return analogRead(pin);
}

uint8_t WildThumper::currentTotal(void){
	return this->motor_current(LmotorC) + this->motor_current(RmotorC);
}
