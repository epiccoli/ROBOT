// Robot.cpp is the class implementation of Robot superclass
#include "Robot.h"


// Define MUX here
// MUX mux_left(MUX_L_SIG, MUX_L_S0, MUX_L_S1, MUX_L_S2, MUX_L_S3);
// MUX mux_right(MUX_R_SIG, MUX_R_S0, MUX_R_S1, MUX_R_S2, MUX_R_S3);

// //Define IR sensors
// IR IR_test(mux_left, C0, ShortRange, 5); // new short range IR connected to C0 on MUX1, averaging 5 values for averaging.


// IR IR_test2(MUX_1_SIG, MUX_1_S0, MUX_1_S1, MUX_1_S2, MUX_1_S3, C1, ShortRange, 5); // new short range IR connected to C0 on MUX1, averaging 5 values for averaging.


Robot::Robot() {

	_state = INITIALIZE;

	_ir_objects[ID_FRONT_BOT_LEFT_OUT] = new IR(IR_FRONT_BOT_LEFT_OUT);
	_ir_objects[ID_FRONT_BOT_LEFT_IN] = new IR(IR_FRONT_BOT_LEFT_IN);
	_ir_objects[ID_FRONT_TOP_LEFT_OUT] = new IR(IR_FRONT_TOP_LEFT_OUT);
	_ir_objects[ID_FRONT_TOP_LEFT_IN] = new IR(IR_FRONT_TOP_LEFT_IN);
	_ir_objects[ID_SIDE_LEFT_FRONT] = new IR(IR_SIDE_LEFT_FRONT);
	_ir_objects[ID_SIDE_LEFT_ARMS] = new IR(IR_SIDE_LEFT_ARMS);

	_ir_objects[ID_FRONT_BOT_RIGHT_OUT] = new IR(IR_FRONT_BOT_RIGHT_OUT);
	_ir_objects[ID_FRONT_BOT_RIGHT_IN] = new IR(IR_FRONT_BOT_RIGHT_IN);
	_ir_objects[ID_FRONT_TOP_RIGHT_OUT] = new IR(IR_FRONT_TOP_RIGHT_OUT);
	_ir_objects[ID_FRONT_TOP_RIGHT_IN] = new IR(IR_FRONT_TOP_RIGHT_IN);
	_ir_objects[ID_SIDE_RIGHT_FRONT] = new IR(IR_SIDE_RIGHT_FRONT);
	_ir_objects[ID_SIDE_RIGHT_ARMS] = new IR(IR_SIDE_RIGHT_ARMS);

	_ir_objects[ID_SIDE_LEFT_BACK] = new IR(IR_SIDE_LEFT_BACK);
	_ir_objects[ID_IN_LEFT] = new IR(IR_IN_LEFT);
	_ir_objects[ID_IN_MID] = new IR(IR_IN_MID);
	_ir_objects[ID_IN_RIGHT] = new IR(IR_IN_RIGHT);
	_ir_objects[ID_SIDE_RIGHT_BACK] = new IR(IR_SIDE_RIGHT_BACK);

	memset(_ir_values,0,17);

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
    
    
    // int val = IR_test.getDistance();
    // Serial.println("val");
    // Serial.println(val);
    // // int val2 = IR_test2.getDistance();
    // // Serial.println("val2");
    // // Serial.println(val2);
    
    // if (val < 10) {
    //     motor_left = 8;
    //     motor_right= -8;
    // }
    // else if (val2 < 10) {
    //     motor_left = -8;
    //     motor_right= 8;
    // }
    // else {
    //     motor_left = 12;
    //     motor_right = 12;
    // }
    
    // Wire.beginTransmission(wildthumper_address); // alert device that something is coming
    // Wire.write(motor_left); // sent data
    // Wire.write(motor_right); // sent data
    // Wire.endTransmission(); // end transaction - i2c free again.

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


// #include "Servo.h"
 
// Servo leftServo;
// Servo rightServo;
// int leftValue = 0;
// int rightValue = 0;
 
// void setup() {
//   leftServo.attach(10);
//   rightServo.attach(9);
// }
 
// void loop() {
//   // sensor values between 50..900
//   leftValue = (analogRead(0) - 50) / 50;
//   rightValue = (analogRead(1) - 50) / 50;
//   leftServo.write(89 + rightValue);
//   rightServo.write(89 - leftValue);
//   delay(10);
// }


// Other function go here
// void Robot::braitenberg() {


// }

void Robot::update_all_IRs(bool dist) {
	if (dist == true) {
		for(int i=0; i<17; i++){
			_ir_values[i] = _ir_objects[i]->getDistance();
		}	
	}else if (dist == false) {
		for(int i=0; i<17; i++){
			_ir_values[i] = _ir_objects[i]->getAvgAnalog();
		}	
	}
}

int Robot::updateIR(int ir_id, bool dist) {
	if (dist == true) {
		int ir_value = _ir_objects[ir_id]->getDistance();
		return ir_value;
	}else if (dist == false) {
		int ir_value = _ir_objects[ir_id]->getDistance();
		return ir_value;
	}
}

