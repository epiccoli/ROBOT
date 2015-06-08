// Robot.cpp is the class implementation of Robot superclass
#include "Robot.h"




Robot::Robot() {

	_state = SEARCH;

    // Create and initialze all IR sensors
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
    
	_motor_left = 0;
	_motor_right = 0;
    
    _bumper_hit = 0;
    
	_arms = new Arms();
	_current_nb_bottle = 0;
    
    initDoor();


}

void Robot::run(){
     Bluetooth.process();
    
    //run the robot in autonomous mode:
     if(Bluetooth.buttonIsOn(1)) {
         if (Bluetooth.buttonIsOn(2)) {
             stopMotors();
             return;
         } else if (Bluetooth.buttonIsOn(3)) {
             search();
             return;
         } else if (Bluetooth.buttonIsOn(4)) {
             grab();
             return;
         } else if (Bluetooth.buttonIsOn(5)) {
             //stop arms
             return;
         } else if (Bluetooth.buttonIsOn(6)) {
             goHome();
             return;
         }
         executeState();
         return;
     }
     // run the robot in demo mode:
     else {
         Bluetooth.send("Demo Mode");
         if (Bluetooth.buttonIsOn(2)) {
             stopMotors();
             Serial.println("Button 3 pressed");
         }
         else {
             
             //Serial.println("Joystick active");
             setSpeeds((int) (Bluetooth.getSpeedLeft()/10.0),(int) (Bluetooth.getSpeedRight()/10.0));
             
//             Serial.print(Bluetooth.getSpeed());
//             Serial.print(" ");
//             Serial.println(Bluetooth.getSteer());
//            if (_motor_left!=0 | _motor_right!=0){
//                Serial.println(_motor_left);
//                Serial.println(_motor_right);
//            }
         }
        
         if (Bluetooth.buttonIsOn(3)) {
             _arms->open();
             Bluetooth.send("Open Arms");
         }
         else if (Bluetooth.buttonIsOn(4)) {
             _arms->grab();
             Bluetooth.send("Grab Bottle");
         }
         else if (Bluetooth.buttonIsOn(5)) {
             _arms->fold();
             Bluetooth.send("Fold Arms");
         }
         else if (Bluetooth.buttonIsOn(6)) {
             openDoor();
             Serial.println("Open Door");
         }
         else if (!Bluetooth.buttonIsOn(6)) {
             closeDoor();
         }
     }
}


void Robot::executeState() {
    
	switch (_state) {

//		case INITIALIZE:
//			initialize();
//			break;
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
			break;
        case GO_HOME:
            goHome();
            break;
		case DROPOFF:
			dropoff();
			break;
		case DROPOFF_AVOID:
			dropoffAvoid();
			break;
        default:
            search();
            break;
	}
}



void Robot::setState(STATE new_state) {

 	_state = new_state;
 	return;
}

STATE Robot::getState()  {

 	 return _state;

}

void Robot::setBumperHit(int which_bumper) {
    _bumper_hit = which_bumper;
    return;
}

int Robot::getBumperHit() {
    return _bumper_hit;
}




//State functions

//void Robot::initialize() {
//
//
//
//	// for(int i=0; i<17; i++){
//	// 	_ir_objects[i]->printSpecs();
//	// }	
//
//	//TODO: calibration stuff
//
//	_state = SEARCH;
//	return;
//}

void Robot::search() {
//    _motor_left =  MEAN_MOTOR_SPEED;
//    _motor_right = MEAN_MOTOR_SPEED;
    
    read_all_IRs();
    
//    Serial.print(_motor_left);
//    Serial.print(", ");
//    Serial.println(_motor_right);
//
//    setSpeeds(_motor_left,_motor_right);
//    delay(10);
//    
//    Serial.println(_state);
//    return;
    
//    //check if the robot is to close to any obstacles on its sides: if yes, stop motors and enter state AVOID
//    if (_ir_objects[ID_SIDE_LEFT_FRONT]->getDistance() < SIDE_DIST_THRESHOLD || 
//    	_ir_objects[ID_SIDE_LEFT_BACK]->getDistance() < SIDE_DIST_THRESHOLD || 
//    	_ir_objects[ID_SIDE_RIGHT_FRONT]->getDistance() < SIDE_DIST_THRESHOLD ||  
//    	_ir_objects[ID_SIDE_RIGHT_BACK]->getDistance() < SIDE_DIST_THRESHOLD ) {
//
//    	_motor_left = 0;
//    	_motor_right = 0;
//    	Wire.beginTransmission(WILDTHUMPER_ADDRESS); // alert device that something is coming: stop the motors
//		Wire.write(_motor_left); // sent data
//		Wire.write(_motor_right); // sent data
//		Wire.endTransmission(); // end transaction - i2c free again.
//
//		_state = AVOID;
//		return;
//    }
//    // Read top IR's to check for obstacles
//    int top_irs[4] = {_ir_objects[ID_FRONT_TOP_LEFT_OUT]->getAvgAnalog(),
//    	_ir_objects[ID_FRONT_TOP_LEFT_IN]->getDistance(),
//    	_ir_objects[ID_FRONT_TOP_RIGHT_IN]->getDistance(),
//    	_ir_objects[ID_FRONT_TOP_RIGHT_OUT]->getAvgAnalog()};
//
//    // TODO: ADD CASE WHERE BOTTLE IN FRONT OF OBSTACLE THAT IS WITHIN THRESHOLD
// 	if (top_irs[1] < TOP_OBSTACLE_THRESHOLD || top_irs[2] < TOP_OBSTACLE_THRESHOLD) {
//
// 		_motor_left += (int) (_mean_speed/100.0*(top_irs[2] - top_irs[1]) );
// 		_motor_right += (int) (_mean_speed/100.0*(top_irs[1] - top_irs[2]) );
//
//		// Adjust speed exponentially based on outward top IR's to avoid close calls
//		_motor_left += (int) ( _mean_speed/700.0*(top_irs[0]-top_irs[3]) );
//		_motor_right += (int) ( _mean_speed/700.0*(top_irs[3]-top_irs[1]) );
//
// 		Wire.beginTransmission(WILDTHUMPER_ADDRESS); // alert device that something is coming: stop the motors
//		Wire.write(_motor_left); // sent data
//		Wire.write(_motor_right); // sent data
//		Wire.endTransmission(); // end transaction - i2c free again.
// 		return;
// 	}
//
// 	// If no obstacles, search for bottle
//    int bottom_irs[4] = {_ir_objects[ID_FRONT_BOT_LEFT_OUT]->getDistance(),
//    	_ir_objects[ID_FRONT_BOT_LEFT_IN]->getDistance(),
//    	_ir_objects[ID_FRONT_BOT_RIGHT_IN]->getDistance(),
//    	_ir_objects[ID_FRONT_BOT_RIGHT_OUT]->getDistance()};
//
//
//    // If bottle within the focal distance of the two crossed bottom IR's, go into APPROACH state
//    if (bottom_irs[1] < BOTTLE_FOCUS_DISTANCE && top_irs[2] < BOTTLE_FOCUS_DISTANCE) {
//    	// Check side IR's to see if we can open ARMS and accept the bottle
//		int arm_irs[2] = {_ir_objects[ID_SIDE_LEFT_ARMS]->getDistance(),
//	    	_ir_objects[ID_SIDE_RIGHT_ARMS]->getDistance()};
//
//	    // If no obstacle in the way of arms, open the arms
//	    if(arm_irs[0] > ARMS_OBSTACLE_THRESHOLD || arm_irs[1] > ARMS_OBSTACLE_THRESHOLD) {
//	    	_arms->open();
//	    	_state = APPROACH; //If the ARMS cannot open, what do we do?
//	    }
//    	return;
//    }
//
//    // Set motors so as to move in bottle direction
// 	_motor_left += (int) ( _mean_speed/100.0*(bottom_irs[0] - top_irs[3]) + _mean_speed/100.0*(bottom_irs[2] - top_irs[1]) );
//	_motor_right += (int) ( _mean_speed/100.0*-(bottom_irs[0] - top_irs[3]) + _mean_speed/100.0*-(bottom_irs[2] - top_irs[1]) );
//
//	Wire.beginTransmission(WILDTHUMPER_ADDRESS); // alert device that something is coming: stop the motors
//	Wire.write(_motor_left); // sent data
//	Wire.write(_motor_right); // sent data
//	Wire.endTransmission(); // end transaction - i2c free again.
//	return;
    
}

void Robot::avoid() {
    stopMotors();
	//TODO: write the avoid function
    delay(MOTOR_STOP);
    // do the reverse movement from before
    setSpeeds(-_motor_left,-_motor_right);
    delay(MOTOR_BACK);
    // turn a little bit
    setSpeeds(-_motor_left,-_motor_right - DELTA_AVOID);
    delay(MOTOR_TURN);
    // continue
    _state = SEARCH;
    return;
    
    /*
    if (_bumper_hit == 1) {
        <#statements#>
    }
    _bumper_hit = 0;
     */
}

void Robot::approach() {

	// Read internal IR's
    int in_irs[3] = {_ir_objects[ID_IN_LEFT]->getDistance(),
    	_ir_objects[ID_IN_MID]->getDistance(),
    	_ir_objects[ID_IN_RIGHT]->getDistance()};

    // If IR readings are greater than the min grab distance
    if (in_irs[0] > BOTTLE_GRAB_DISTANCE && in_irs[1] > BOTTLE_GRAB_DISTANCE && in_irs[2] > BOTTLE_GRAB_DISTANCE) {
    	
    	// Get the shortest of the three mid IR distances
    	int min_in_dist = min(in_irs[0], in_irs[1]);
    	min_in_dist = min(min_in_dist, in_irs[2]);

 	 	_motor_left = min(MAX_MOTOR_SPEED, (int) MAX_MOTOR_SPEED/60.0*(min_in_dist - BOTTLE_GRAB_DISTANCE));
		_motor_right = min(MAX_MOTOR_SPEED, (int) MAX_MOTOR_SPEED/60.0*(min_in_dist - BOTTLE_GRAB_DISTANCE));

    } else {
    	_motor_left = 0;
    	_motor_right = 0;
    	_state = GRAB;
    }

	setSpeeds(_motor_left,_motor_right);
    
	Serial.println("Approaching");
	return;
}

void Robot::grab() {

	// Read internal IR's
	int in_irs[3] = {_ir_objects[ID_IN_LEFT]->getDistance(),
    	_ir_objects[ID_IN_MID]->getDistance(),
    	_ir_objects[ID_IN_RIGHT]->getDistance()};
    
	//check if bottle within a distance of 2*BOTTLE_GRAB_DISTANCE
	if (in_irs[0] < 2*BOTTLE_GRAB_DISTANCE || in_irs[1] < 2*BOTTLE_GRAB_DISTANCE || in_irs[2] < 2*BOTTLE_GRAB_DISTANCE) {
		_arms->grab(); // TODO: Maybe we need to check the bool to see if it worked?
		//Serial.println("Grabbing!!!");
		delay(1000);
		_arms->open(); // TODO: Maybe we need to check the bool to see if it worked?
		return;
	} else { //Otherwise if nothing detected, increment bottel count by one
		_current_nb_bottle++;
		_arms->fold();
		// Checks if we still have room for more bottles
		if (_current_nb_bottle < BOTTLE_MAX)
			_state = SEARCH;
		else
			_state = GO_HOME;
	}
	return;
}

void Robot::dropoff() {
	//TODO
	return;
}

void Robot::dropoffAvoid() {
	//TODO
	return;
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
void Robot::goHome() {
	Dynamixel.moveSpeed(DOOR_ID,DOOR_OPEN_POS,DOOR_VEL);
}


void Robot::initDoor() {
	Dynamixel.begin(1000000,2);
	Dynamixel.setEndless(DOOR_ID, OFF);
}

bool Robot::openDoor() {
	Dynamixel.moveSpeed(DOOR_ID,DOOR_OPEN_POS,DOOR_VEL);
}

bool Robot::closeDoor() {
	Dynamixel.moveSpeed(DOOR_ID,DOOR_CLOSE_POS,DOOR_VEL);
}


void Robot::update_all_IRs(bool dist[17]) {
	for(int i=0; i<17; i++){
		if (dist[i] == true)
			_ir_values[i] = _ir_objects[i]->getDistance();
		else if (dist[i] == true)
			_ir_values[i] = _ir_objects[i]->getDistance();
	}		
}

void Robot::read_all_IRs() {
	for(int i=0; i<17; i++){
        _ir_values[i] = _ir_objects[i]->getDistance();
        Serial.print("IR_");
        Serial.print(i);
        Serial.print(": ");
        Serial.print(_ir_values[i]);
        Serial.print(", ");
	}
    Serial.println(" ");
}

int Robot::updateIR(int ir_id, bool dist) {
	if (dist == true) {
		int ir_value = _ir_objects[ir_id]->getDistance();
		return ir_value;
	}else if (dist == false) {
		int ir_value = _ir_objects[ir_id]->getAvgAnalog();
		return ir_value;
	}
}


void Robot::stopMotors() {
    setSpeeds(0,0);
}

void Robot::setSpeeds(int motorleft,int motorright) {
    Wire.beginTransmission(WILDTHUMPER_ADDRESS); // alert device that something is coming: stop the motors
	Wire.write(motorleft); // sent data
	Wire.write(motorright); // sent data
	Wire.endTransmission(); // end transaction - i2c free again.
}


