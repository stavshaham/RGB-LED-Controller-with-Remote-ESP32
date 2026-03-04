#include <Arduino.h>
#include "RemoteControl.h"
#include "Constants.h"

static uint32_t lastButton = 0;
static unsigned long lastHoldTime = 0;
static unsigned long holdStartTime = 0;

void initIR(IRrecv &irrecv) {
  irrecv.enableIRIn();
}

void checkButtons(int length, decode_results &results) {
  unsigned long now = millis();

  // HOLD behavior
  if (results.repeat) {
    if (lastButton == PLUS_BUTTON && now - lastHoldTime >= HOLD_INTERVAL) {
      unsigned long heldFor = now - holdStartTime;
      int step = (1 + heldFor / 100) * RATIO;
      step = min(step, 300);

      rawValues[currentState] = min(rawValues[currentState] + step, MAX_VALUE);
      lastHoldTime = now;
    } else if (lastButton == MINUS_BUTTON && now - lastHoldTime >= HOLD_INTERVAL) {
      unsigned long heldFor = now - holdStartTime;
      int step = (1 + heldFor / 100) * RATIO;
      step = min(step, 300);

      rawValues[currentState] = max(rawValues[currentState] - step, MIN_VALUE);

      lastHoldTime = now;
    }
    return;
  }

  // New button press
  lastButton = results.value;
  holdStartTime = now;

  switch (results.value) {
    case POWER_BUTTON:
      for (int i = 0; i < length; i++) {
        rawValues[i] = 0;
      }

      Serial.println("POWER");
      break;

    case PLUS_BUTTON:
      if (rawValues[currentState] < MAX_VALUE)
        rawValues[currentState] = rawValues[currentState] + RATIO;
      
      Serial.println("PLUS");
      break;

    case MINUS_BUTTON:
      if (rawValues[currentState] > MIN_VALUE)
        rawValues[currentState] = rawValues[currentState] - RATIO;
      
      Serial.println("MINUS");
      break;

    case NEXT_BUTTON:
      if (currentState == 2)
        currentState = 0;
      else
        currentState++;
      
      Serial.println(currentState);
      break;

    case PREVIOUS_BUTTON:
      if (currentState == 0)
        currentState = 2;
      else
        currentState--;

      Serial.println(currentState);
      break;
  }

  lastHoldTime = now;
}