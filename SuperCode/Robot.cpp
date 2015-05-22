// Robot.cpp is the class implementation of Robot superclass
#include "Robot.h"


Robot::Robot() {

	_state = 0;
}

void Robot::executeState(unsigned int STATE) {

	switch (STATE) {

		case (0) : 

		// search();

		std::cout << "Mode in switch case: search"<< "\n";
		_state=1;

		case (1) : 

		// grab();

		std::cout << "grabbing and changing to searching at end" << "\n";
		_state = 0;

	}
}


void Robot::changeState(unsigned int NEW_STATE) {

	_state = NEW_STATE;
}

int Robot::getState()  {

	 return _state;

}