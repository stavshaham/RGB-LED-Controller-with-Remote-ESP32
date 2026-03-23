#include "Constants.h"
#include "LedController.h"
#include "RemoteControl.h"

#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

LEDController led;
RemoteControl remote(led);

IRrecv irrecv(recvPin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  delay(2000);

  Serial.print("IR receiver running on pin ");
  Serial.println(recvPin);

  led.begin();
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  led.update();
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    remote.handle(results);
    irrecv.resume();
  }

  delay(5);

}
