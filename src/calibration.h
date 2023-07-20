#include <Arduino.h>

#ifndef CALIBRATION_H
#define CALIBRATION_H

struct Point {
    int x;
    int y;
};

struct Guess {
    Point tl;
    Point tr;
    Point bl;
    Point br;
    int fitness;
};

struct Measurements {
    float tl;
    float tr;
    float bl;
    float br;
};

// These are the true corners of the machine that we want to solve for...used for testing only
const float trueTLX = -5.0;
const float trueTLY = 410.0;
const float trueTRX = 708.0;
const float trueTRY = 385.0;
const float trueBLX = 0.0;
const float trueBLY = 0.0;
const float trueBRX = 710.0;
const float trueBRY = 0.0;

Guess generateInitialGuess(int initialWidth, int initialHeight);
Measurements takeSimulatedMeasurement(float x, float y, float maxError);

#endif