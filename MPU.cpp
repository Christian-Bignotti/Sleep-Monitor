#include "MPU.h"

void MPU6050Sensor::begin() {
    // initialize MPU registers
}

void MPU6050Sensor::handleInterrupt() {
    dataReady = true;
}

bool MPU6050Sensor::hasData() {
    return dataReady;
}

float MPU6050Sensor::getMotion() {
    dataReady = false;

    // Read accel registers
    int16_t ax = 0, ay = 0, az = 0;

    motionMagnitude = sqrt(ax*ax + ay*ay + az*az);

    return motionMagnitude;
}