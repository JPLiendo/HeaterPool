


#define pumpPin  13
float sensorPool;
float sensorStreamer;
float offsetTemp;
int presetTime;



void setup() {
  // put your setup code here, to run once:
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  
  // put your main code here, to run repeatedly:

pump(pumpActivation(deltaCalc(sensorStreamer, sensorPool),offsetTemp,presetTime ));

}

//deltCalc returns the diferenrce between sensor1 and sensor2.
float deltaCalc(float sensorStreamersorA, float sensorPool ) {
  return sensorStreamer - sensorPool;
}

//pumpActivation manages the pump ON/OFF state.
bool pumpActivation(float deltaTemp, float offsetTemp, int presetTime) {
  bool aux = false;
  if (deltaTemp < offsetTemp) {
    aux = true;
    if (timer(presetTime, aux)) {
      return true;
    } else {
      return false;
    }
  }
}

//timer count a presetTime and return true.
bool timer(int presetTime, bool retention) {
  int acumulate = 0;
  while (retention) {
    if (acumulate <= presetTime) {
      int now = millis();
      acumulate += now;
    } else {
      return true;
    }
  }
  return false;
}

void pump(bool pumpActivation) {
  if (pumpActivation) {
    Serial.print("Pump is running");
    digitalWrite(pumpPin, HIGH);
  } else {
    Serial.print("Pump is stopped");
    digitalWrite(pumpPin, LOW);
  }
}
