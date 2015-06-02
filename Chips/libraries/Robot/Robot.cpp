// Robot.cpp is the class implementation of Robot superclass
#include "Robot.h"


// Define IR Sensors here
IR IR_test(MUX_1_SIG, MUX_1_S0, MUX_1_S1, MUX_1_S2, MUX_1_S3, C0, ShortRange, 5); // new short range IR connected to C0 on MUX1, averaging 5 values for averaging.
IR IR_test2(MUX_1_SIG, MUX_1_S0, MUX_1_S1, MUX_1_S2, MUX_1_S3, C1, ShortRange, 5); // new short range IR connected to C0 on MUX1, averaging 5 values for averaging.


Robot::Robot() {
	_state = INITIALIZE;
}

void Robot::executeState() {

	switch (_state) {

		case INITIALIZE:
			initialize();
			break;
		case SEARCH: 
			search();
			break;
		case AVOID:
			avoid();
			break;
		case APPROACH:
			approach();
			break;
		case GRAB: 
			grab();
			/*std::cout << "grabbing and changing to searching at end" << "\n";
			_state = SEARCH;*/
			break;
		case DROPOFF:
			dropoff();
			break;
		case DROPOFF_AVOID:
			dropoffAvoid();
			break;
	}
}


void Robot::setState(STATE new_state) {

	_state = new_state;
}

STATE Robot::getState()  {

	 return _state;

}




//State functions

void Robot::initialize() {
	_current_nb_bottle = 0;

	//TODO: calibration stuff

	_state = SEARCH;
}

void Robot::search() {
    int motor_left;
    int motor_right;
    
    
    int val = IR_test.getDistance();
    Serial.println("val");
    Serial.println(val);
    int val2 = IR_test2.getDistance();
    Serial.println("val2");
    Serial.println(val2);
    
    if (val < 10) {
        motor_left = 8;
        motor_right= -8;
    }
    else if (val2 < 10) {
        motor_left = -8;
        motor_right= 8;
    }
    else {
        motor_left = 12;
        motor_right = 12;
    }
    
    Wire.beginTransmission(wildthumper_address); // alert device that something is coming
    Wire.write(motor_left); // sent data
    Wire.write(motor_right); // sent data
    Wire.endTransmission(); // end transaction - i2c free again.

}

void Robot::avoid() {
	//TODO: write the avoid function
}

void Robot::approach() {
	//TODO: write
}

void Robot::grab() {
	//TODO
}

void Robot::dropoff() {
	//TODO
}

void Robot::dropoffAvoid() {
	//TODO
}