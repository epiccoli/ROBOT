#include "MUX.h"

    MUX::MUX(int sig, int s0, int s1, int s2, int s3){
        m_sig = sig;
        m_s0 = s0;
        m_s1 = s1;
        m_s2 = s2;
        m_s3 = s3;

        // Setup of associated MUX pins on Arduino
        pinMode(m_sig, INPUT);

	    pinMode(m_s0, OUTPUT); 
	    pinMode(m_s1, OUTPUT); 
	    pinMode(m_s2, OUTPUT); 
	    pinMode(m_s3, OUTPUT);
    }

    // ~MUX();

    int getSIG(){
        return m_sig;
    }

    int getS0(){
        return m_s0;
    }

    int getS1(){
        return m_s1;
    }

    int getS2(){
        return m_s2;
    }

    int getS3(){
        return m_s3;
    }

}
