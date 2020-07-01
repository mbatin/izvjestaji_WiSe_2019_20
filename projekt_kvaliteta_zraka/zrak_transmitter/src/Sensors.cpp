#include "Sensors.h"

#define PIN_MQ135 A0
MQ135 mq135(PIN_MQ135);

SENSORS::SENSORS() {}
SENSORS::~SENSORS() {}

void SENSORS::TroykaMQ_init(){

  Serial.begin(9600);
  mq135.calibrate();
  Serial.print("Ro = ");
  Serial.println(mq135.getRo());
  
}

int SENSORS::readCO2(){

  Serial.print("Ratio: ");
  Serial.print(mq135.readRatio());
  Serial.print("\tCO2: ");
  Serial.print(mq135.readCO2());
  Serial.println(" ppm");
  delay(100);
  return mq135.readCO2();

}