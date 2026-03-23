#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include <Arduino.h>
#include "Constants.h"

class LEDController {
private:
  int rPin, gPin, bPin;
  float rSmooth, gSmooth, bSmooth;

  /* gammaCorrect corrects the gamma of the LED light
   * @param value The current value of the LED light
   * @return The corrected gamma
  */
  int gammaCorrect(float value);

public:
  /* LEDController constructor function, sets up default values */
  LEDController();

  /* begin runs when the object is initialized */
  void begin();
  /* update runs in the loop */
  void update();

  /* increase increases the current state value by 1, makes sure max doesn't exceed */
  void increase(int step);
  /* decrease decreases the current state value by 1, makes sure the value is not lower than min */
  void decrease(int step);
  /* nextChannel updates the channel to the next one, after channel two goes back to zero */
  void nextChannel();
  /* previousChannel updates the channel to the previous one, after zero goes back to two */
  void previousChannel();
  /* powerOff turns off al the LED lights, set them all to zero */
  void powerOff();
};

#endif