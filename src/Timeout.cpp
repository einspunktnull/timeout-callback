#include "Timeout.h"

/***************************** PUBLIC *********************************/
void Timeout::start(unsigned long duration, ExternalCallbackPointer onTimeoutCallbackPointer) {
	this->onTimeoutCallbackPointer = onTimeoutCallbackPointer;
	this->duration = duration;
	this->lastMillis = millis();
}

void Timeout::stop() {
	this->onTimeoutCallbackPointer = 0;
}

void Timeout::loop() {
	if (this->onTimeoutCallbackPointer != 0) {
		unsigned long currentMillis = millis();
		if ((currentMillis - this->lastMillis) >= this->duration) {
			this->onTimeoutCallbackPointer();
			this->stop();
		}
	}
}

/***************************** PRIVATE *********************************/

