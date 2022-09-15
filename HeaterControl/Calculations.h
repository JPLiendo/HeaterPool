#include "Arduino.h"

#ifndef Calculations_h
#define Calculations_h

class Calculations
{
    //Add public members.
  public:
    //Constructor.
    Calculations();
    //Public methods.
    float deltaTemp(float sensor1, float sensor2);
};
#endif
