#include <Arduino.h>
#include <math.h>
#include "LEDController.h"
#include "Constants.h"

static float rSmooth = 0;
static float gSmooth = 0;
static float bSmooth = 0;

static int gammaCorrect(float value) {
  return (int)(pow(value / 255.0, GAMMA) * 255.0 + 0.5);
}

void initLEDs() {
  ledcAttach(RED_LED, 5000, 8);
  ledcAttach(GREEN_LED, 5000, 8);
  ledcAttach(BLUE_LED, 5000, 8);
}

void setColor() {
  float r = map(rawValues[0], 0, MAX_VALUE, 0, 255);
  float g = map(rawValues[1], 0, MAX_VALUE, 0, 255);
  float b = map(rawValues[2], 0, MAX_VALUE, 0, 255);

  rSmooth += (r - rSmooth) * SMOOTHING;
  gSmooth += (g - gSmooth) * SMOOTHING;
  bSmooth += (b - bSmooth) * SMOOTHING;

  ledcWrite(RED_LED,   gammaCorrect(rSmooth));
  ledcWrite(GREEN_LED, gammaCorrect(gSmooth));
  ledcWrite(BLUE_LED,  gammaCorrect(bSmooth));
}