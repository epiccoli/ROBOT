// Robot.h is the header file for the Robot 
#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED


#include "Arduino.h"
#include "mega_constants.h"
#include "MUX.h"
#include "IR.h"
#include "Wire.h"
#include "Communications.h"
#include "Motor.h"

class Robot
{

public:
	Robot();
	// ~Robot();

	void executeState();
	//void changeState(unsigned int NEW_STATE);
	void setState(STATE new_state);
	STATE getState(); // if we first define const unsigned int SEARCH = 0; etc

private:
	STATE _state;
	int _current_nb_bottle;
	IR* _ir_objects[17];
	int _ir_values[17];
	// int _ir_dist[17];
	// int _ir_analog[17];

	int _mean_speed;

	int _motor_left;
	int _motor_right;

	// State functions
	void initialize();
	void search();
	void avoid();
	void approach();
	void grab();
	void dropoff();
	void dropoffAvoid();


	// Other function go here
	// void braitenberg();

	void update_all_IRs(bool dist[17]) ;
	int updateIR(int ir_id, bool dist);

};


#endif 