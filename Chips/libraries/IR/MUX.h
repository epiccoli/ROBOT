#ifndef MUX_H_INCLUDED
#define MUX_H_INCLUDED

#include "Arduino.h"

class MUX
{
public:
	MUX(int sig, int s0, int s1, int s2, int s3);
	// ~MUX();

	int getSIG();
	int getS0();
	int getS1();
	int getS2();
	int getS3();

private:
	int m_sig;
	int m_s0;
	int m_s1;
	int m_s2;
	int m_s3;
};


#endif // SERIALCLASS_H_INCLUDED
