// Robot.h is the header file for the Robot 
#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

class Robot
{

public:
	Robot();
	// ~Robot();

	/* data */

	void executeState(unsigned int STATE);
	void changeState(unsigned int NEW_STATE);
	int getState(); // if we first define const unsigned int SEARCH = 0; etc

private:
	unsigned int _state;
};


#endif 