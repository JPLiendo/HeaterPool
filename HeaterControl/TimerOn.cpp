#include "Arduino.h"
#include "TimerOn.h"
/******************************************************************/
//Public Methods.
/******************************************************************/
//Constructor.
TimerOn::TimerOn()
{
  _init();
}

//activation enable or disable the timer.
bool TimerOn::activation(bool comand) {
 
  if (!comand) { 
    _lastTime = millis();
    return 0;
  } else {
    if ((millis() - _lastTime) > _delay) {
      _count = millis() - _lastTime;
      return 1;
    }
    return 0;
  }
}

//getCount return the time counter value.
unsigned long TimerOn::getCount() {
  return _count;
}

//setTimerOn sets the time delay value on.
void TimerOn::setTimer( unsigned long delay) {
  _delay = delay;
}

/******************************************************************/
//Private Methods.
/******************************************************************/
//_init inicializes the timer values.
void TimerOn::_init() {
  _delay = 0;
  _lastTime= millis();
  _count=0;
}
