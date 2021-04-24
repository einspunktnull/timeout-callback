#ifndef TIMEOUT_CALLBACK_H
#define TIMEOUT_CALLBACK_H

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
    void setCallback(ExternalCallbackPointer onTimeoutCallbackPointer);
    void setDuration(unsigned long durationMillis);
    unsigned long getDuration();
    boolean isRunning();
protected:

private:
    ExternalCallbackPointer onTimeoutCallbackPointer;
    unsigned long duration;
    unsigned long lastMillis;
    boolean running = false;
};

#endif
