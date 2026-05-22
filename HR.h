#pragma once
#include "Sensor.h"

class MAX30102Sensor : public Sensor {
private:
    volatile bool sampleReady = false;
    uint32_t irValue = 0;

public:
    void begin();
    void handleInterrupt();

    bool hasSample();
    uint32_t getSample();
};