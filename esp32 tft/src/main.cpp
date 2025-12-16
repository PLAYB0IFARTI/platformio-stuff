#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// Pin definitions
#define TFT_CS   5
#define TFT_DC   32
#define TFT_RST  15

int circlex = 80;
int circley = 64;

// Hardware SPI
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);

  // Initialize SPI explicitly (recommended for ESP32)
  SPI.begin(18, 19, 23, TFT_CS);

  // Initialize display
  tft.initR(INITR_BLACKTAB);   // Most common ST7735
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("ESP32 + ST7735");
  tft.setCursor(1, 80);
  tft.drawCircle(circlex, circley, 3, ST7735_WHITE);
}

void loop() {
  if 
}
