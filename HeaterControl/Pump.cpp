#include "Arduino.h"
#include "Pump.h"
#include "TimerOn.h"
TimerOn tPumpOn;
TimerOn tPumpOff;

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
    tPumpOn.setTimer(5000);
    if (tPumpOn.activation(comand)) {
      digitalWrite(_pin, HIGH);
      _status = true;

    }
    return;
  } else if (!comand)  {
    tPumpOff.setTimer(5000);
    if (tPumpOff.activation(true)) {
      _status = false;
    }
    return;
  }
}

//getStatus return the pump state.
void Pump::getStatus() {
  _msg();
}

//init initializes the GPIO pin function mode .
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
