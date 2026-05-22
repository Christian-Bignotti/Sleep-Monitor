#pragma once

enum SleepStage {
    AWAKE,
    LIGHT,
    DEEP
};

class SleepClassifier {
public:
    SleepStage classify(float motion, float hrv);
};