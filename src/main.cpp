#include <Arduino.h>
#include "calibration.h"


void setup() {
  Serial.begin(115200);

  Guess initialGuess = generateInitialGuess(700, 420);

  Measurements measurements[9];

  const int initialWidth = 700;
  const int initialHeight = 420;

  const float centerX = initialWidth / 2.0;
  const float centerY = initialHeight / 2.0;

  const float measurementError = 0.0;
  measurements[0] = takeSimulatedMeasurement(centerX, centerY, measurementError);
  measurements[1] = takeSimulatedMeasurement(centerX - 200.0, centerY + 100.0, measurementError);
  measurements[2] = takeSimulatedMeasurement(centerX - 200.0, centerY, measurementError);
  measurements[3] = takeSimulatedMeasurement(centerX - 200.0, centerY - 100.0, measurementError);
  measurements[4] = takeSimulatedMeasurement(centerX, centerY + 100.0, measurementError);
  measurements[5] = takeSimulatedMeasurement(centerX, centerY - 100.0, measurementError);
  measurements[6] = takeSimulatedMeasurement(centerX + 200.0, centerY + 100.0, measurementError);
  measurements[7] = takeSimulatedMeasurement(centerX + 200.0, centerY, measurementError);
  measurements[8] = takeSimulatedMeasurement(centerX + 200.0, centerY - 100.0, measurementError);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello world");
  delay(400);
}

