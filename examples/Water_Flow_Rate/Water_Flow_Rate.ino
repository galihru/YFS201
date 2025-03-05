#include "yfs201.h"

const int flowSensorPin = 2; // Pin tempat sensor terhubung
yfs201 flowSensor(flowSensorPin);

void setup() {
    Serial.begin(9600);
    flowSensor.begin();
}

void loop() {
    float flowRate = flowSensor.getFlowRate();
    unsigned long totalPulses = flowSensor.getTotalPulses();

    Serial.print("Laju Aliran: ");
    Serial.print(flowRate);
    Serial.println(" L/min");

    Serial.print("Total Pulses: ");
    Serial.println(totalPulses);

    delay(1000); // Tunggu 1 detik sebelum membaca lagi
}
