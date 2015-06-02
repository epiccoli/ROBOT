/// Motor library ///

#include "Motor.h" //include the declaration for this class

//<<constructor>>
Motor::Motor(){
}
//<<destructor>>
Motor::~Motor(){/*nothing to destruct*/}

//init Motor
void Motor::init(int inputA, int inputB, int inputC){
	motorA = inputA;
	motorB = inputB;
	motorC = inputC;
	pwm = 0;
	lastoverloadtime = 0;
	mode = 1;					 // set forward (2) or reverse mode (0), brake mode (1)
}

//set speed
void Motor::set_speed(int Speed){
	
	if (Speed>0)                  // set forward (2) or reverse mode (0), brake mode (1)
		mode = 2;
	else
		mode = 0;
	
	pwm = min(abs(Speed),255);                      // set maximum limit 255
	
	drive_motor();
}

//set speed to motor
void Motor::drive_motor(){
	//cli();
	if((millis()-lastoverloadtime)>overloadtime){
		switch (mode)
		{
			case 2:                                               // motor forward
			analogWrite(motorA,0);
			analogWrite(motorB,pwm);
			break;
			
			case 1:                                               // motor brake
			analogWrite(motorA,pwm);
			analogWrite(motorB,pwm);
			break;
			
			case 0:                                               // motor reverse
			analogWrite(motorA,pwm);
			analogWrite(motorB,0);
			break;
		}
	}
	//sei();
}

void Motor::turn_off(){
	analogWrite(motorA,0);
	analogWrite(motorB,0);
}
