#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

#include "Constants.h"
#include "LEDController.h"
#include "RemoteControl.h"

IRrecv irrecv(recvPin); // Create a class object used to receive class
decode_results results; // Create a decoding results class object

void setup() {
  Serial.begin(9600);

  initIR(irrecv);
  initLEDs();

  Serial.print("IR receiver running on pin ");
  Serial.println(recvPin);
}

void loop() {
  setColor();

  if (irrecv.decode(&results)) {
    checkButtons(SIZE, results);
    irrecv.resume();
  }

  delay(5);
}
