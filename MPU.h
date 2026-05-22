// Motion Processing Unit

#pragma once
#include <Wire.h>
#include "Sensor.h"

class MPU6050Sensor : public Sensor {
private:
    volatile bool dataReady = false;
    float motionMagnitude = 0;

public:
    void begin();
    void handleInterrupt();

    bool hasData();
    float getMotion();
};