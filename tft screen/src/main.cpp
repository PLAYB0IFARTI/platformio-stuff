#include <Arduino.h>

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.print("BAZINGA");
  pinMode(2, OUTPUT);
}

void loop() {
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  // put your main code here, to run repeatedly:
}
