#include <OneWire.h>
#include <DallasTemperature.h>
#include "Calculations.h"
#include "TimerOn.h"
#include "Pump.h"

//Global constants.
const int pumpPin = 2;
const int oneWirePin = 5;

//global variables.
float ss;
float ps;
float delta = 10.0;
OneWire oneWireBus(oneWirePin);
DallasTemperature sensors(&oneWireBus);
DeviceAddress streamerSensor = { 0x28, 0x94, 0xE2, 0xDF, 0x02, 0x00, 0x00, 0xFE };
DeviceAddress poolSensor = { 0x28, 0x6B, 0xDF, 0xDF, 0x02, 0x00, 0x00, 0xC0 };


//Objects.
Calculations calcs;
TimerOn timer;
Pump pump(pumpPin);



void setup() {
  Serial.begin(9600);
  sensors.begin();
  sensors.setResolution(streamerSensor, 10);
  sensors.setResolution(poolSensor, 10);

}

void loop() {
  // Send comand to get temperature from sensors.
  sensors.requestTemperatures();
  ss = sensors.getTempC(streamerSensor);
  ps = sensors.getTempC(poolSensor);

  //Check if temp sensed by sensors is correct.
  if (calcs.measureError()) {
    Serial.print("Temperature sensor is not okay");
    delay(2000);
    return;
  } else {
    calcs.setDetaSp(delta);
    if (pump.activation(calcs.deltaTemp(ss, ps))) {
      pump.getStatus();
    } else {
      pump.getStatus();
    }
  }
}
