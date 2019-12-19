#ifndef TIMEOUT_H
#define TIMEOUT_H

#include <Arduino.h>

class TimeoutCallback {

public:
	typedef void (*ExternalCallbackPointer)();
	void start(unsigned long duration, ExternalCallbackPointer onTimeoutCallbackPointer);
	void stop();
	void loop();
protected:

private:
	ExternalCallbackPointer onTimeoutCallbackPointer;
	unsigned long duration;
	unsigned long lastMillis;
};

#endif
