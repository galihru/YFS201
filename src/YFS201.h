#ifndef YFS201_H
#define YFS201_H

#include <Arduino.h>

class yfs201 {
public:
    yfs201(int pin);
    void begin();
    float getFlowRate();
    unsigned long getTotalPulses();

private:
    int pulsePin;
    volatile unsigned long pulseCount;
    unsigned long lastTime;
    static void pulseCounter();
};

#endif
