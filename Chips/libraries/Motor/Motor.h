#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

//=================================== H BRIDGE SETTINGS =============================================================================

#define overloadtime       100     // time in mS before motor is re-enabled after overload occurs

class Motor {
	public:
	Motor();
	~Motor();
	
	void init(int inputA, int inputB, int inputC);
	
	void set_speed(int Speed);
	void turn_off();
	
	int motorA;
	int motorB;
	int motorC;	
	
	unsigned long lastoverloadtime;
	
	private:
	
	int pwm;
	int mode;          // 0=reverse, 1=brake, 2=forward
	
	void drive_motor();
};

#endif
