// Robot.h is the header file for the Robot 
#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED


#include "Arduino.h"
#include "MegaConstants.h"


class Robot
{

public:
	Robot();
	// ~Robot();

	void executeState();
	//void changeState(unsigned int NEW_STATE);
	void setState(STATE new_state);
	int getState(); // if we first define const unsigned int SEARCH = 0; etc

private:
	STATE _state;
	int _timer_max;
	int _bottle_max;


	// State functions
	void initialize();
	void search();
	void avoid();
	void approach();
	void grab();
	void dropoff();
	void dropoffAvoid();


	// Other function go here

};


#endif 