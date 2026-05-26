#pragma once

#include "MPU.h"
#include "HR.h"
#include "HRVAnalyzer.h"
#include "SleepClassifier.h"

class SleepMonitor {
private:
    MPU6050Sensor mpu;
    MAX30102Sensor max;
    HRVAnalyzer hrv;
    SleepClassifier classifier;

public:
    void begin();
    void process();

    void onMPUInterrupt();
    void onMAXInterrupt();
};