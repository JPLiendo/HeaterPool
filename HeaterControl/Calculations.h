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
    float deltaTemp(float streamerSensor, float poolSensor);
    bool detaTempReached(float deltaSp, float deltaPv);
    bool measureError();

    //Add private members.
    private:
    //private variables.
    float _streamerSensor;
    float _poolSensor;
};
#endif
