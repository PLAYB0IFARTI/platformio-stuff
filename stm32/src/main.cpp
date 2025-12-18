#include <Arduino.h>

void setup() {
  pinMode(PA6, OUTPUT);
}

void loop() {
  digitalWrite(PA6, LOW);
  delay(1000);
  digitalWrite(PA6, HIGH);
  delay(1000);
}
