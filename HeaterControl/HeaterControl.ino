#include "Pump.h"
#include "TimerOn.h"

Pump pump(14);

TimerOn timerOn;

void setup() {
  Serial.begin(9600);
  pinMode(13, INPUT);
}

void loop() {
  String comandSerial;
  if (Serial.available()) {
    comandSerial = Serial.readString();
    switch (comandSerial.toInt()) {
      case 1:
        pump.getStatus();
        break;
    }
  }


  if (digitalRead(13)) {
    pump.activation(true);
  } else {
    pump.activation(false);
  }
}
