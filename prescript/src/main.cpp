#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <string>
#include <vector>

bool button_pressed = false;
String phrases[4] = {"Hello World", "The Middle Never Forgets", "Gallop on, Rocinate!", "Fishmael"};
String phrase;
String obscured = phrase;

Adafruit_SSD1306 display(128, 64, &Wire, -1);

// generates the random stuff until the button is pressed
void generate() {
  for (int i = 0; i < phrase.length(); i++) {
    long rand = random(33, 126);
    obscured[i] = rand;
  }
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(obscured);
  display.display();
  delay(150);
}

// reveals the prescript
void reveal() {
  for (int i = 0; i < phrase.length(); i++) {
    for (int j = i; j < phrase.length(); j++) {
      long rand = random(33,126);
      obscured[j] = rand;
    }
    obscured[i] = phrase[i];

    display.clearDisplay();
    display.setCursor(0,0);
    display.print(obscured);
    display.display();
    delay(150);
  }
  delay(1000);
  phrase = phrases[random(1,4)];
  button_pressed = false;
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
  display.setTextSize(1);
  display.display();
  phrase = phrases[random(1, 4)];
}

void loop() {
  generate();
  if (digitalRead(18) && !button_pressed) {
    reveal();
  }
}
