#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>     
#include <Adafruit_ST7735.h>  

#define TFT_CS  5
#define TFT_RST 15
#define TFT_DC  32
// #define TFT_MOSI  23  // SDA // HW MOSI
// #define TFT_SCLK  18  // SCL // HW SCLK
// #define TFT_MISO  19  // not used
#define TFT_BL  22  // LED back-light

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);  // hardware SPI
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup(void) {
  Serial.begin(115200);
  pinMode(16, INPUT_PULLDOWN);
  
  //tft.initB();
  tft.initR(INITR_BLACKTAB); // Init ST7735S chip, black tab
  //tft.initR(INITR_GREENTAB); // Init ST7735S chip, green tab
  //tft.setSPISpeed(27000000);

  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(15, 50);
  tft.println("Makerguides");
}

void loop() {

 }