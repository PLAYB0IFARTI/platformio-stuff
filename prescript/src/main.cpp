#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
long rand;

void generate() {

}
void prescript() {

}

void setup() {
  Serial.begin(115200);
  pinMode(18, INPUT_PULLDOWN);
  randomSeed(analogRead(2));

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true) {}
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.write("blub");
  display.display();
}

void loop() {

}
