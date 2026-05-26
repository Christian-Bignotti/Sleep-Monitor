#include "SleepMonitor.h"


SleepMonitor* monitorInstance = nullptr;

void IRAM_ATTR mpuISR() {
    monitorInstance->onMPUInterrupt();
}

void IRAM_ATTR maxISR() {
    monitorInstance->onMAXInterrupt();
}


#define MPU_INT_PIN 2
#define MAX_INT_PIN 3

// TODO:


// 1. Need to add ISR handling in Sleepmon cpp
// 2. Attach interrupt

void SleepMonitor::begin() {
    Wire.begin(8, 9);


    pinMode(MPU_INT_PIN, INPUT_PULLUP);
    pinMode(MAX_INT_PIN, INPUT_PULLUP);

    attachInterrupt(
        digitalPinToInterrupt(MPU_INT_PIN),
        mpuISR,
        FALLING
    );

    attachInterrupt(
        digitalPinToInterrupt(MAX_INT_PIN),
        maxISR,
        FALLING
    );

    mpu.begin();
    max.begin();
}

// Interrupt handlers


void SleepMonitor::onMPUInterrupt() {
    mpu.handleInterrupt();
}

void SleepMonitor::onMAXInterrupt() {
    max.handleInterrupt();
}

void SleepMonitor::process() {

    if (mpu.hasData()) {
        float motion = mpu.getMotion();

        if (max.hasSample()) {
            max.getSample();

            float hrvValue = hrv.computeRMSSD();

            SleepStage stage =
                classifier.classify(motion, hrvValue);

            switch(stage) {
                case AWAKE:
                    Serial.println("Awake");
                    break;
                case LIGHT:
                    Serial.println("Light Sleep");
                    break;
                case DEEP:
                    Serial.println("Deep Sleep");
                    break;
            }
        }
    }
}