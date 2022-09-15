#include "Arduino.h"
#include "Calculations.h"
//Constructor.
Calculations::Calculations(){}

//DeltaTemp returns the diference between sensor1 minus sensor2.
float Calculations::deltaTemp(float sensor1, float sensor2)
{ 
  return sensor1-sensor2;
  }
