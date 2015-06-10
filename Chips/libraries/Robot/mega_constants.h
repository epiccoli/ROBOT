#ifndef MEGA_CONSTANTS_INCLUDED
#define MEGA_CONSTANTS_INCLUDED


enum STATE
{
  INITIALIZE,
  SEARCH,
  AVOID,
  APPROACH,
  GRAB,
  GO_HOME,
  DROPOFF,
  DROPOFF_AVOID,
};


#define TIMER_MAX  9	*60*1000 // in milliseconds
#define BOTTLE_MAX  5

// Robot motor speeds definitions
#define MAX_MOTOR_SPEED 19
#define MEAN_MOTOR_SPEED 15
#define DELTA_AVOID 3

// AVOID TIMES
#define MOTOR_STOP 500
#define MOTOR_BACK 1500
#define MOTOR_TURN 1500


// IR sensor threshold distances
#define SIDE_DIST_THRESHOLD 30
#define TOP_OBSTACLE_THRESHOLD 60
#define BOTTLE_FOCUS_DISTANCE 30
#define ARMS_OBSTACLE_THRESHOLD 50
#define BOTTLE_GRAB_DISTANCE 7
#define TARGET 30


// Door
#define DOOR_ID 3
#define DOOR_OPEN_POS 450 // We need to calibrate this
#define DOOR_CLOSE_POS 650
#define DOOR_VEL 50


// Arduino Mega Pin mapping
// TODO: Pin mapping need to be thoroughly thought out and completed

//MUX to Arduino Mega analog pins
#define		MUX_L_SIG	A1
#define		MUX_R_SIG	A0

//MUX to Arduino Mega digital pins
#define		MUX_L_S0		21
#define		MUX_L_S1		23
#define		MUX_L_S2		25
#define		MUX_L_S3		27

#define		MUX_R_S0		22
#define		MUX_R_S1		24
#define		MUX_R_S2		26
#define		MUX_R_S3		28

//MUX analog pins to IR sensors
#define		C0		0
#define		C1		1
#define		C2		2
#define		C3		3
#define		C4		4
#define		C5		5
#define		C6		6
#define		C7		7
#define		C8		8
#define		C9		9
#define		C10		10
#define		C11		11
#define		C12		12
#define		C13		13
#define		C14		14
#define		C15		15

//Define IR sensor types
#define 	LONG_RANGE 	1
#define 	SHORT_RANGE	2

//Define IR objects
// #define 	IR_FRONT_BOT_LEFT_OUT		MUX_L_SIG, MUX_L_S0, MUX_L_S1, MUX_L_S2, MUX_L_S3, C2, LONG_RANGE, 5
#define 	IR_FRONT_BOT_LEFT_IN		MUX_R_SIG, MUX_R_S0, MUX_R_S1, MUX_R_S2, MUX_R_S3, C4, LONG_RANGE, 5
//#define 	IR_FRONT_TOP_LEFT_OUT		MUX_R_SIG, MUX_R_S0, MUX_R_S1, MUX_R_S2, MUX_R_S3, C4, LONG_RANGE, 5
#define 	IR_FRONT_TOP_LEFT_IN		MUX_R_SIG, MUX_R_S0, MUX_R_S1, MUX_R_S2, MUX_R_S3, C13, LONG_RANGE, 5
#define 	IR_SIDE_LEFT_FRONT			MUX_R_SIG, MUX_R_S0, MUX_R_S1, MUX_R_S2, MUX_R_S3, C14, SHORT_RANGE, 5
#define 	IR_SIDE_LEFT_ARMS			MUX_R_SIG, MUX_R_S0, MUX_R_S1, MUX_R_S2, MUX_R_S3, C8, SHORT_RANGE, 5

//#define 	IR_FRONT_BOT_RIGHT_OUT		MUX_R_SIG, MUX_R_S0, MUX_R_S1, MUX_R_S2, MUX_R_S3, C1, LONG_RANGE, 5
#define 	IR_FRONT_BOT_RIGHT_IN		MUX_R_SIG, MUX_R_S0, MUX_R_S1, MUX_R_S2, MUX_R_S3, C15, LONG_RANGE, 5
//#define 	IR_FRONT_TOP_RIGHT_OUT		MUX_R_SIG, MUX_R_S0, MUX_R_S1, MUX_R_S2, MUX_R_S3, C2, LONG_RANGE, 5
#define 	IR_FRONT_TOP_RIGHT_IN		MUX_R_SIG, MUX_R_S0, MUX_R_S1, MUX_R_S2, MUX_R_S3, C10, LONG_RANGE, 5
#define 	IR_SIDE_RIGHT_FRONT			MUX_R_SIG, MUX_R_S0, MUX_R_S1, MUX_R_S2, MUX_R_S3, C2, SHORT_RANGE, 5
#define 	IR_SIDE_RIGHT_ARMS			MUX_R_SIG, MUX_R_S0, MUX_R_S1, MUX_R_S2, MUX_R_S3, C6, SHORT_RANGE, 5

#define 	IR_SIDE_LEFT_BACK			A6, SHORT_RANGE, 5
#define 	IR_IN_LEFT					A3, SHORT_RANGE, 5
#define 	IR_IN_MID					A4, SHORT_RANGE, 5
#define 	IR_IN_RIGHT					A5, SHORT_RANGE, 5
#define 	IR_SIDE_RIGHT_BACK			A2, SHORT_RANGE, 5

//Define IR identifiers
#define 	ID_FRONT_BOT_LEFT_OUT		0
#define 	ID_FRONT_BOT_LEFT_IN		1
#define 	ID_FRONT_TOP_LEFT_OUT		2
#define 	ID_FRONT_TOP_LEFT_IN		3
#define 	ID_SIDE_LEFT_FRONT			4
#define 	ID_SIDE_LEFT_ARMS			5

#define 	ID_FRONT_BOT_RIGHT_OUT		6
#define 	ID_FRONT_BOT_RIGHT_IN		7
#define 	ID_FRONT_TOP_RIGHT_OUT		8
#define 	ID_FRONT_TOP_RIGHT_IN		9
#define 	ID_SIDE_RIGHT_FRONT			10
#define 	ID_SIDE_RIGHT_ARMS			11

#define 	ID_SIDE_LEFT_BACK			12
#define 	ID_IN_LEFT					13
#define 	ID_IN_MID					14
#define 	ID_IN_RIGHT					15
#define 	ID_SIDE_RIGHT_BACK			16


#endif