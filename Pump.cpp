#include "Arduino.h"
#include "Pump.h"

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
    digitalWrite(_pin, HIGH);
    _status = true;
    _msg();
    return;
  } else {
    digitalWrite(_pin, LOW);
    _status = false;
    _msg();
    return;
  }
}

//getStatus return the pump state.
int Pump::getStatus() {
    _msg();
}

//setTimerOn sets the time delay to starts the pump.
void Pump::setTimerOn(long offsetOn){
  _delayOn= offsetOn;
  }

//setTimerOff sets the time delay to stop the pump.
void Pump::setTimerOff(long offsetOff){
  _delayOff= offsetOff;
  }



  //init inicializes the GPIO pin mode function.
  void Pump::_init() {
    pinMode(_pin, OUTPUT);
  }

  //msg return some msg.
  void Pump::_msg() {
    if (_status) {
      Serial.print("Pump is running...");
      return;
    } else {
      Serial.print("Pump is stopped.");
      return;
    }
  }

//_checkDelay verify if the time given as parameter was reached and return true.
  bool Pump::_checkDelay(long offsetTime){
    do{
      long actualTime = millis();
      long lastTime = 0;
      }
    _actualTime= millis();
    if actualTime-lastTime > offsetTime{
      
      }
    
    


    
    }
  
