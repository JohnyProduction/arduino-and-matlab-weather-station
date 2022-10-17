#include <Wire.h>
#include "SparkFunBME280.h"
//BMP280
BME280 mySensorB; 

//WATER SENSOR
#define SIGNAL_PIN A2
int value = 0;

void setup()
{
  Serial.begin(115200);

  Wire.begin();

  mySensorB.setI2CAddress(0x76); /
  if(mySensorB.beginI2C() == false) Serial.println("Sensor B connect failed");
}
void loop()
{
  value = analogRead(SIGNAL_PIN);
  Serial.print(" Pressure: ");
  Serial.print( mySensorB.readFloatPressure(), 0);
  Serial.print(" Temp: ");
  Serial.print(mySensorB.readTempC(), 2);
  Serial.print(" Water: ");
  Serial.print(value);

  Serial.println();

  delay(1000);
}
