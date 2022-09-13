#include "Arduino.h"


#ifndef FlowSensor_h
#define FlowSensor_h

class FlowSensor
{
  public:
    //Constructor.
    FlowSensor(int pin);
    //Public methods.
    bool CheckFlow(bool comand, bool feedback);

  private:
    //Private Variables.
    int _pin;
    //Private Methods.
    void _init();
};
#endif
