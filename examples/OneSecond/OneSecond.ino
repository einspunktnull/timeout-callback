#include "Arduino.h"
#include <Timeout.h>

Timeout timeout;

int num = 0;

void setup() {
	Serial.begin(57600);
	Serial.print("waiting for timeout...");
	timeout.start(1000, onTimeout);
}

void loop() {
	timeout.loop();
}

void onTimeout() {
	Serial.print("got timeout");
}
