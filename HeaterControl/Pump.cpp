#include "Arduino.h"
#include "Pump.h"
#include "TimerOn.h"
TimerOn timer;

//Constructor.
Pump::Pump(int pin)
{
  _pin = pin;
  _init();
}

//activation start or stop the pump.
void Pump::activation(bool comand)
{
  if (comand) {
    timer.setTimer(5000);
    if (timer.activation(comand)) {
      digitalWrite(_pin, HIGH);
      _status = true;
 
    }
    return;
  } else if (!comand)  {
      if (timer.activation(true)){
        _status = false;
       }
    return;
  }
}

//getStatus return the pump state.
void Pump::getStatus() {
  _msg();
}

//init inicializes the GPIO pin mode function.
void Pump::_init() {
  pinMode(_pin, OUTPUT);

}

//msg return some msg.
void Pump::_msg() {
  if (_status) {
    Serial.println("Pump is running...");
    return;
  } else {
    Serial.println("Pump is stopped.");
    return;
  }
}
