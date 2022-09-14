#include "Arduino.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "TempSensors.h"

//Contructor.
TempSensors::TempSensors(int pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
  const int oneWireBus = _pin;

  // Setup a oneWire instance to communicate with any OneWire devices
  OneWire oneWire(oneWireBus);

  // Pass our oneWire reference to Dallas Temperature sensor
  DallasTemperature sensorsTemp(&oneWire);
  // Start the DS18B20 sensor
  sensorsTemp.begin();
}
