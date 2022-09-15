#include "Arduino.h"
#include "Calculations.h"
#include "TimerOn.h"

//timerHisteresis manages the delay time for avoid signal bounce.
TimerOn timerHisteresis;

//Constructor.
Calculations::Calculations() {
  _streamerSensor = 0.0;
  _poolSensor = 0.0;

}

//DeltaTemp returns the diference between streamerSensor minus poolSensor.
float Calculations::deltaTemp(float streamerSensor, float poolSensor)
{
  _streamerSensor = streamerSensor;
  _poolSensor = poolSensor;
  return _streamerSensor - _poolSensor;
}

//detaTempReached returns true if the delta temp form sensor and setpoint was reached.
 bool Calculations::detaTempReached(float deltaSp, float deltaPv){
  if (deltaPv>=deltaSp){
    if (timerHisteresis.activation(true)){
      return true;
      }
    
    }else{
      return false;
      }  
  }

//measureError return true if the temp value measure by some of both sensors is -127 grades.
bool Calculations::measureError()
{
  if (_streamerSensor || _poolSensor <= -127.0) {
    return true;
  } else {
    return false;
  }
}
