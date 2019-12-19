#include "TimeoutCallback.h"

void TimeoutCallback::start(unsigned long duration, ExternalCallbackPointer onTimeoutCallbackPointer) {
	this->onTimeoutCallbackPointer = onTimeoutCallbackPointer;
	this->duration = duration;
	this->lastMillis = millis();
}

void TimeoutCallback::stop() {
	this->onTimeoutCallbackPointer = 0;
}

void TimeoutCallback::loop() {
	if (this->onTimeoutCallbackPointer != 0) {
		unsigned long currentMillis = millis();
		if ((currentMillis - this->lastMillis) >= this->duration) {
			this->onTimeoutCallbackPointer();
			this->stop();
		}
	}
}
