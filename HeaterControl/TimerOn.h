
#include "Arduino.h"

#ifndef TimerOn_h
#define TimerOn_h

//class Pump definition.
class TimerOn
{
    //Add public members.
  public:
    //Constructor.
    TimerOn();
    //Public methods.
    bool activation(bool comand);//activation enable or disable the timer.
    unsigned long getCount();//getCount return the time counter value.
    void setTimer( unsigned long delay);//setTimerOn sets the time delay value on.
    
    //Add private members.
  private:
    //private properties.
    unsigned long _delay;
    unsigned long _lastTime ;
    unsigned long _count;
    //Add private methods.
    void _init();//_init inicializes the GPIO pin mode function.
};
#endif
