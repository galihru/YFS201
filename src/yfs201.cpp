#include "yfs201.h"

yfs201::yfs201(int pin) : pulsePin(pin), pulseCount(0), lastTime(0) {}

void yfs201::begin() {
    pinMode(pulsePin, INPUT);
    attachInterrupt(digitalPinToInterrupt(pulsePin), pulseCounter, FALLING);
}

float yfs201::getFlowRate() {
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - lastTime;
    lastTime = currentTime;

    float frequency = (pulseCount * 1000.0) / elapsedTime; // Frekuensi dalam Hz
    pulseCount = 0; // Reset pulse count

    float flowRate = (frequency * 60) / 7.5; // Laju aliran dalam L/min
    return flowRate;
}

unsigned long yfs201::getTotalPulses() {
    return pulseCount;
}

void yfs201::pulseCounter() {
    pulseCount++;
}
