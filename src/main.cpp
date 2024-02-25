#include <Arduino.h>

int sensorPin = A0;
int sensorValue = 0;

const int DIN_PIN = 9;
const int CS_PIN = 8;
const int CLK_PIN = 7;


void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);

  Serial.println(sensorValue);
  // sensorValue is between 0 and 350 when using 3.3V pin
  if (sensorValue > 200) {
    Serial.println("moisture level too high");
  }
  if (sensorValue <= 200 && sensorValue > 100) {
    Serial.println("moisture level good");
  }
  if (sensorValue <= 100 && sensorValue >= 0) {
    Serial.println("moisture level too low");
  }
  delay(1000);
}