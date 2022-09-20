

#include "Arduino.h"
#include "TimerOn.h"


#ifndef Pump_h
#define Pump_h

//class Pump definition.
class Pump
{
    //Add public members.
  public:
    //Constructor.
    Pump(int pin);
    //Public methods.
    bool activation(bool comand);//activation start or stop the pump.
    void getStatus();//getStatus return the pump state.

    //Add private members.
  private:
    //private properties.
    int _pin;
    bool _status;

    //Add private methods.
    void _init();//_init inicializes the GPIO pin mode function.
    void _msg();//_msg return some msg.
};
#endif
