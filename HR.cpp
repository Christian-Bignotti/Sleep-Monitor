#include "HR.h"

void MAX30102Sensor::begin() {
    // Configure FIFO + interrupts
}

void MAX30102Sensor::handleInterrupt() {
    sampleReady = true;
}

bool MAX30102Sensor::hasSample() {
    return sampleReady;
}

uint32_t MAX30102Sensor::getSample() {
    sampleReady = false;

    // Read FIFO sample
    return irValue;
}