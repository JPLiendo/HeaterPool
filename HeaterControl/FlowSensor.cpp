#include "Arduino.h"
#include "FlowSensor.h"
#include "TimerOn.h"

TimerOn tFlow;

//Constructor.
FlowSensor::FlowSensor(int pin)
{
  _pin = pin;
  _init();
}


//CheckFlow returns true whether there is flow.
bool FlowSensor::CheckFlow(bool comand, bool feedback)
{
  if (comand && !feedback) {
    tFlow.setTimer(5000);
    if (tFlow.activation(true)) {
      return true;
    }
  } else {
    return false;
  }
}

//init initializes the GPIO pin function mode .
void FlowSensor::_init() {
  pinMode(_pin, INPUT);
}
