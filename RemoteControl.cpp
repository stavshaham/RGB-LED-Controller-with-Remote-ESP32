#include "RemoteControl.h"
#include "Constants.h"

RemoteControl::RemoteControl(LEDController &controller)
    : led(controller)
{
  lastButton = 0;
  lastHoldTime = 0;
  holdStartTime = 0;
}
void RemoteControl::handle(decode_results &results) {
  unsigned long now = millis();

  Serial.println(results.value, HEX);  // debug

  // HOLD behavior
  if (results.repeat) {
    if (lastButton == PLUS_BUTTON && now - lastHoldTime >= HOLD_INTERVAL) {
      unsigned long heldFor = now - holdStartTime;
      int step = (1 + heldFor / 100) * RATIO;
      step = min(step, 300);

      led.increase(step);
      lastHoldTime = now;
    } else if (lastButton == MINUS_BUTTON && now - lastHoldTime >= HOLD_INTERVAL) {
      unsigned long heldFor = now - holdStartTime;
      int step = (1 + heldFor / 100) * RATIO;
      step = min(step, 300);

      led.decrease(step);
      lastHoldTime = now;
    }

    return;
  }

  // New button press
  lastButton = results.value;
  holdStartTime = now;

  switch (results.value) {
    case POWER_BUTTON:
      Serial.println("POWER");
      led.powerOff();
      break;

    case PLUS_BUTTON:
      Serial.println("PLUS");
      led.increase(1);
      break;

    case MINUS_BUTTON:
      Serial.println("MINUS");
      led.decrease(1);
      break;

    case NEXT_BUTTON:
      Serial.println("NEXT");
      led.nextChannel();
      break;

    case PREVIOUS_BUTTON:
      Serial.println("PREVIOUS");
      led.previousChannel();
      break;
  }

  lastHoldTime = now;
}