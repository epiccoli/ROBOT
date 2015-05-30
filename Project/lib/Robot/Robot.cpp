// Robot.cpp is the class implementation of Robot superclass
#include "Robot.h"


Robot::Robot() {
	_state = INITIALIZE;
}

void Robot::executeState() {

	switch (getState()) {

		case INITIALIZE:
			initialize();
			break;
		case SEARCH: 
			search();
			/*std::cout << "Mode in switch case: search"<< "\n";
			_state=1;*/
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
		case DROPOFF_AVOID;
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
	_timer_max = TIMER_MAX;
	_bottle_max = BOTTLE_MAX;
	//TODO: calibration stuff

	_state = SEARCH;
}

void Robot::search() {
	//TODO: write the search function and the navigation function
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