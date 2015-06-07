#ifndef COMPASS_H_INCLUDED
#define COMPASS_H_INCLUDED

#include "Arduino.h"

class Compass
{
public:
	Compass(int uart, int bRate);

	int readAngle();

private:
	int m_uart;
	int m_bRate;
	
	char valuebyte[8];
    int angle;
    int count;
    byte value;
};


#endif // SERIALCLASS_H_INCLUDED