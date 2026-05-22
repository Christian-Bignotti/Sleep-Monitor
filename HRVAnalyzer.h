#pragma once

class HRVAnalyzer {
private:
    unsigned long lastBeat = 0;
    float rrIntervals[20];
    int index = 0;

public:
    void processBeat(unsigned long timestamp);
    float computeRMSSD();
};