#ifndef IR_MUX_H_INCLUDED
#define IR_MUX_H_INCLUDED

#include "Arduino.h"

class MUX
{
public:
	MUX(int sig, int s0, int s1, int s2, int s3);
	~MUX();

	void setup_MUX();

	int getSIG();
	int getS0();
	int getS1();
	int getS2();
	int getS3();

private:
	int _sig;
	int _s0;
	int _s1;
	int _s2;
	int _s3;
};

//Functions


// bool isObstacle();

// bool openArmsOK();
        
// bool isBottleInside();
        
// bool isBottleInPosition();

#endif // SERIALCLASS_H_INCLUDED
