/************************************************************************************************************
 * SharpIR.h - Arduino library for retrieving distance (in cm) from the analog GP2Y0A21Y and GP2Y0A02YK     *
 * Distance sensors                                                                                         *
 * Copyright 2014 Dr. Marcal Casas-Cartagena (marcal.casas@gmail.com)                                       *
 ************************************************************************************************************

 ************************************************************************************************************
 * This library is free software; you can redistribute it and/or                                            *
 * modify it under the terms of the GNU Lesser General Public                                               *
 * License as published by the Free Software Foundation; either                                             *
 * version 2.1 of the License, or (at your option) any later version.                                       *
 *                                                                                                          *
 * This library is distributed in the hope that it will be useful,                                          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of                                           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU                                        *
 * Lesser General Public License for more details.                                                          *
 *                                                                                                          *
 * You should have received a copy of the GNU Lesser General Public                                         *
 * License along with this library; if not, write to the Free Software                                      *
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA                               *
 ***********************************************************************************************************/

#ifndef SharpIR_h
#define SharpIR_h

#include "Arduino.h"
#include "IR.h"

class SharpIR
{
  public:
    SharpIR (int MUXPin, int avg, int tolerance, int sensorModel);
    int distance();
    
    
  private:
    
    int cm();
    int readIR(int IR_number);
    
    int _MUXPin;
    int _model;
    int _avg;
    int _p;
    int _sum;
    int _previousDistance;
    int _tol;
    
};

#endif
