#include <OneWire.h>
#include <DallasTemperature.h>
#include "Calculations.h"
#include "TimerOn.h"

const int oneWirePin = 5;
OneWire oneWireBus(oneWirePin);
DallasTemperature sensors(&oneWireBus);
DeviceAddress streamerSensor = { 0x28, 0x94, 0xE2, 0xDF, 0x02, 0x00, 0x00, 0xFE };
DeviceAddress poolSensor = { 0x28, 0x6B, 0xDF, 0xDF, 0x02, 0x00, 0x00, 0xC0 };

//global variables.
float ss;
float ps;



Calculations calcs;
TimerOn timer;



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

  if (calcs.measureError()) {
    Serial.print("Temperature sensor is not okay");
    return;
  } else {
    calcs.deltaTemp(ss, ps);


  }


}
