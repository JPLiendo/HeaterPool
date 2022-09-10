

#include "Arduino.h"

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
    void activation(bool comand);//activation start or stop the pump.
    int getStatus();//getStatus return the pump state.
    void setTimerOn(long offsetOn);//setTimerOn sets the time delay to starts the pump.
    void setTimerOff(long offsetOff);//setTimerOff sets the time delay to stop the pump.

    //Add private members.
  private:
    //private properties.
    int _pin;
    bool _status;
    long _delayOn;
    long _delayOff;
    long _actualTime;
    long _lastTime;
    
    //Add private methods.
    void _init();//_init inicializes the GPIO pin mode function.
    void _msg();//_msg return some msg.
    bool _checkDelay(long offsetTime);//_checkDelay verify if the time given as parameter was reached and return true.
};
#endif
