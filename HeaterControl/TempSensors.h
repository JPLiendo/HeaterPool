#include "Arduino.h"

#ifndef TempSensors_h
#define TempSensors_h

//class TempSensors manages the temperature sensor ds18d20.
class TempSensors
{

  public:
    //Constructor.
    TempSensors(int pin);
    //Public methods.
    float getDeltaTemp(float sensor_1, float Sensor_2);
    bool deltaReached(float deltaTemp);

  private:
    //Private variables.
    int _pin;
    //Private methods.
    void _init();
}
#endif
