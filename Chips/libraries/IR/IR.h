#ifndef IR_H_INCLUDED
#define IR_H_INCLUDED

#include <Arduino.h>
#include "MUX.h"

class IR
{
public:
	IR(MUX mux(int sig, int s0, int s1, int s2, int s3), int mux_pin, int ir_model, int avg);
    IR(int sig, int s0, int s1, int s2, int s3, int mux_pin, int ir_model, int avg);
	IR(int analog_pin, int ir_model, int avg);
//	~IR();

	int getDistance();
	int getAvgAnalog();

private:
	int readIR();
    
    int m_sig;
    int m_s0;
    int m_s1;
    int m_s2;
    int m_s3;
	int m_mux_pin;
	int m_analog_pin;
	
	int m_ir_model;
	int m_avg;

};

#endif // SERIALCLASS_H_INCLUDED

