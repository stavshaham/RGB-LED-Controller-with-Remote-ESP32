#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include "LEDController.h"

class RemoteControl {
private:
  LEDController &led;
  uint32_t lastButton = 0;
  unsigned long lastHoldTime = 0;
  unsigned long holdStartTime = 0;

public:
  RemoteControl(LEDController &controller);

  void handle(decode_results &results);
};

#endif