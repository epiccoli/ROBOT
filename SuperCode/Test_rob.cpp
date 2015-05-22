#include <iostream>

#include "Robot.cpp"

const unsigned int SEARCH = 0;
const unsigned int GRAB = 1;

int main () {

	Robot robbie;

	int init = robbie.getState();

	std::cout << "State is 0 if search: " << init << "\n";

	robbie.changeState(GRAB);

	init = robbie.getState();

	std::cout << "State is 1 if grab: "<< init << "\n";

	robbie.executeState(1);

	if (robbie.getState()==0) {
		std::cout << "End all";
	}


}