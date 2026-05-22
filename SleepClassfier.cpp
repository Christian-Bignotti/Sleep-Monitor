#include "SleepClassifier.h"

SleepStage SleepClassifier::classify(float motion, float hrv) {

    if (motion > 1500 || hrv < 20)
        return AWAKE;

    if (motion > 500 || hrv < 45)
        return LIGHT;

    return DEEP;
} 