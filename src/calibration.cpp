#include "calibration.h"

Guess generateInitialGuess(int initialWidth, int initialHeight) {
    Guess initialGuess = {
        {0, initialHeight},
        {initialWidth, initialHeight},
        {0, 0},
        {initialWidth, 0},
        10000
    };
    return initialGuess;
}

// Compute the distance between two points
float distanceBetweenPoints(float a, float b, float c, float d) {
    float dx = c - a;
    float dy = d - b;
    return sqrt(dx * dx + dy * dy);
}

// This takes in the X and Y coordinates to take a measurement along with the maximum error and
// returns a simulated measurement at that location. X and Y are referenced to the BL corner.
//TODO: Error is not yet implemented
Measurements takeSimulatedMeasurement(float x, float y, float maxError) {
    float tl = distanceBetweenPoints(trueTLX, trueTLY, x, y);
    float tr = distanceBetweenPoints(trueTRX, trueTRY, x, y);
    float bl = distanceBetweenPoints(trueBLX, trueBLY, x, y);
    float br = distanceBetweenPoints(trueBRX, trueBRY, x, y);
    return {tl, tr, bl, br};
}

Guess computeLinesFitness(Measurements measurements, Guess lastGuess){
    float fitnesses[9];
    Measurements allLines[9];
    
    //Check each of the measurements against the guess
    measurements.forEach(measurement => {
        const {fitness, lines} = magneticallyAttractedLinesFitness(measurement, lastGuess);
        fitnesses.push(fitness);
        allLines.push(lines);
    });
    
    float fitness = calculateAverage(fitnesses);

    //Here is where we need to do the calculation of which line is the most fucked and which direction to move it
    lastGuess = computeFurthestFromCenterOfMass(allLines, lastGuess);

    Serial.println("Fitness: " + String(1/fitness));

    return lastGuess;
}

