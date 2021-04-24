#ifndef TIMEOUT_H
#define TIMEOUT_H

#include <Arduino.h>

class TimeoutCallback {

public:
    typedef void (*ExternalCallbackPointer)();
    TimeoutCallback(unsigned long durationMillis, ExternalCallbackPointer onTimeoutCallbackPointer);
    void start();
    void restart();
    void stop();
    void loop();
    void reset();
    void setDuration(unsigned long durationMillis);
    void setCallback(ExternalCallbackPointer onTimeoutCallbackPointer);
protected:

private:
    ExternalCallbackPointer onTimeoutCallbackPointer;
    unsigned long duration;
    unsigned long lastMillis;
    boolean running = false;
};

#endif
