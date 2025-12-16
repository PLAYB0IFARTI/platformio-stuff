#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;

int x = 0;
int y = 0;
int textsize = 1;

// Reset pin (not used on many modules, so set to -1)
const int OLED_RESET = -1;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Initialize Serial (for debugging)
  Serial.begin(115200);

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don’t proceed, loop forever
  }

  display.clearDisplay();
  
  // Draw some text
  display.setTextSize(textsize);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x,y);
  display.println(F("Hello world!"));
  Wire.begin(21,22);
  display.display(); 
}

void loop() {
  delay(100);
}
