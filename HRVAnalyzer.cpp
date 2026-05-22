#include "HRVAnalyzer.h"
#include <math.h>

void HRVAnalyzer::processBeat(unsigned long timestamp) {
    if (lastBeat != 0) {
        rrIntervals[index++] = timestamp - lastBeat;
        index %= 20;
    }

    lastBeat = timestamp;
}

float HRVAnalyzer::computeRMSSD() {
    float sum = 0;

    for(int i = 1; i < 20; i++) {
        float diff = rrIntervals[i] - rrIntervals[i-1];
        sum += diff * diff;
    }

    return sqrt(sum / 19);
}