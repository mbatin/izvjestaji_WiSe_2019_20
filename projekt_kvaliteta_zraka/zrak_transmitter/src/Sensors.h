#ifndef Sensors_h
#define Sensors_h

#include <Arduino.h>
#include <Wire.h>
#include <TroykaMQ.h>

class SENSORS
{
public:
        SENSORS();
        ~SENSORS();
        
        int readCO2();
        void TroykaMQ_init();
};

#endif