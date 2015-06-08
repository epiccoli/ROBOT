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
#include "Arms.h"
#include "BluetoothController.h"

class Robot
{

public:
	Robot();
	// ~Robot();

	void executeState();
    void run();
	// //void changeState(unsigned int NEW_STATE);
	void setState(STATE new_state);
	STATE getState(); // if we first define const unsigned int SEARCH = 0; etc
    
    void setBumperHit(int which_bumper);
    int getBumperHit();

private:
	STATE _state;
	int _current_nb_bottle;
	IR* _ir_objects[17];
	int _ir_values[17];
	// int _ir_dist[17];
	// int _ir_analog[17];

	Arms* _arms;

	int _mean_speed;

	int _motor_left;
	int _motor_right;
    
    int _bumper_hit; // 0 = none, 1 = front, 2 = back, 3 = right, 4 = left

	// State functions
//	void initialize();
	void search();
	void avoid();
	void approach();
	void grab();
	void goHome();
	void dropoff();
	void dropoffAvoid();


	// Other function go here
	// void braitenberg();

    void initDoor();
	bool openDoor();
	bool closeDoor();
    
    void stopMotors();
    void setSpeeds(int motorleft, int motorright);
    
    void read_all_IRs();

	void update_all_IRs(bool dist[17]) ;
	int updateIR(int ir_id, bool dist);

};


#endif 