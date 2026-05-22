#pragma once

class Sensor {
public:
    virtual void begin() = 0;
    virtual void handleInterrupt() = 0;
};