#include "yfs201.h"

const int flowSensorPin = 2; // Pin tempat sensor terhubung
yfs201 flowSensor(flowSensorPin);

float totalVolume = 0; // Total volume dalam liter
unsigned long lastTime = 0;

void setup() {
    Serial.begin(9600);
    flowSensor.begin();
    lastTime = millis(); // Catat waktu awal
}

void loop() {
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - lastTime;
    lastTime = currentTime;

    float flowRate = flowSensor.getFlowRate(); // Laju aliran dalam L/min
    float volumeIncrement = (flowRate * elapsedTime) / 60000.0; // Volume dalam liter

    totalVolume += volumeIncrement; // Tambahkan ke total volume

    Serial.print("Laju Aliran: ");
    Serial.print(flowRate);
    Serial.println(" L/min");

    Serial.print("Total Volume: ");
    Serial.print(totalVolume);
    Serial.println(" L");

    delay(1000); // Tunggu 1 detik sebelum membaca lagi
}
