#include "LEDController.h"
#include "Constants.h"

#include <Arduino.h>
#include <math.h>

LEDController::LEDController() : 
  rPin(RED_LED), gPin(GREEN_LED), bPin(BLUE_LED), 
  rSmooth(0), gSmooth(0), bSmooth(0) {
    int i = 0;
    for (i = 0; i < SIZE; i++) {
      rawValues[i] = 0;
    }


}

void LEDController::begin() {
  ledcAttach(rPin, 5000, 8);
  ledcAttach(gPin, 5000, 8);
  ledcAttach(bPin, 5000, 8);
}

void LEDController::increase(int step) {
  rawValues[currentChannel] = min(rawValues[currentChannel] + step, MAX_VALUE);
}

void LEDController::decrease(int step) {
  rawValues[currentChannel] = max(rawValues[currentChannel] - step, MIN_VALUE);
}

void LEDController::nextChannel() {
  currentChannel = (currentChannel + 1) % 3;
  Serial.println(currentChannel);
}

void LEDController::previousChannel() {
  currentChannel = (currentChannel + 2) % 3;
  Serial.println(currentChannel);
}

void LEDController::powerOff() {
  int i = 0;
  for (i = 0; i < SIZE; i++) {
    rawValues[i] = 0;
  }
}

int LEDController::gammaCorrect(float value) {
  return (int)(pow(value / 255.0, GAMMA) * 255.0 + 0.5);
}

void LEDController::update() {

  float r = map(rawValues[0], 0, MAX_VALUE, 0, 255);
  float g = map(rawValues[1], 0, MAX_VALUE, 0, 255);
  float b = map(rawValues[2], 0, MAX_VALUE, 0, 255);

  rSmooth += (r - rSmooth) * SMOOTHING;
  gSmooth += (g - gSmooth) * SMOOTHING;
  bSmooth += (b - bSmooth) * SMOOTHING;

  ledcWrite(rPin, gammaCorrect(rSmooth));
  ledcWrite(gPin, gammaCorrect(gSmooth));
  ledcWrite(bPin, gammaCorrect(bSmooth));
}