#include <Arduino.h>
#include <LowPower.h>
#include "main.h"
#include "Sensors.h"
#include "Radio_nRF.h"

SENSORS sensor;
RADIO radioNRF;

SensorData dataToSend;
StateType state = READ_SERIAL;

bool rslt;

void setup()
{
  Serial.begin(115200);
  sensor.TroykaMQ_init();
  radioNRF.nRF_init();
}

void loop()
{
  switch (state)
  {
  case READ_SERIAL:
    
    state = READ_SENSORS;
    break;

  case READ_SENSORS:
    dataToSend.air = sensor.readCO2();
    delay(100);
    
    state = RADIO_TX;
    break;
  
  case RADIO_TX:
    Serial.println(F("slanje"));
    Serial.println(dataToSend.air);
    delay(100);
    radioNRF.RF_send(dataToSend);
    
    state = SLEEP;
    break;
  
  case SLEEP:
    delay(50);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    delay(50);

    state = READ_SERIAL;
    break;
  
  default:
    break;
  }
}