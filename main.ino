#include <Wire.h>
#include "SleepMonitor.h"

SleepMonitor monitor;

void setup() {
    Serial.begin(115200);
    monitor.begin();
}

void loop() {
    monitor.process();
}