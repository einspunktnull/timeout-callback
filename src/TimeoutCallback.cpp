#include "TimeoutCallback.h"

TimeoutCallback::TimeoutCallback(
        unsigned long durationMillis,
        ExternalCallbackPointer onTimeoutCallbackPointer
) {
    this->onTimeoutCallbackPointer = onTimeoutCallbackPointer;
    this->duration = durationMillis;
}

void TimeoutCallback::start() {
    this->lastMillis = millis();
    this->running = true;
}

void TimeoutCallback::restart() {
    this->start();
}

void TimeoutCallback::stop() {
    this->running = false;
}

// Call this in Arduino loop() function
void TimeoutCallback::loop() {
    if (this->running) {
        unsigned long currentMillis = millis();
        if ((currentMillis - this->lastMillis) >= this->duration) {
            this->stop();
            this->onTimeoutCallbackPointer();
        }
    }
}

void TimeoutCallback::reset() {
    this->lastMillis = millis();
}

void TimeoutCallback::setDuration(unsigned long durationMillis) {
    this->duration = durationMillis;
}

void TimeoutCallback::setCallback(ExternalCallbackPointer onTimeoutCallbackPointer) {
    this->onTimeoutCallbackPointer = onTimeoutCallbackPointer;
}
