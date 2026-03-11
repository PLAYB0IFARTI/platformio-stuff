#include <Arduino.h>
#include <TFT_eSPI.h>      // Graphics and font library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI(); // Invoke library

void drawTestPattern(); void colorTest(); void textRotationTest(); void shapeDrawingTest(); void colorBarsTest();

// Color definitions
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

void setup() {
  Serial.begin(115200);
  Serial.println("ST7735 TFT Test Starting...");
  
  // Initialize display
  tft.init();
  
  // Set rotation (0-3) - adjust based on your mounting [citation:8]
  // 0 = portrait, 1 = landscape, 2 = reverse portrait, 3 = reverse landscape
  tft.setRotation(1);
  
  // Fill screen with black
  tft.fillScreen(BLACK);
  
  // Draw some shapes and text
  drawTestPattern();
  
  delay(2000);
  
  // Run color test
  colorTest();
}

void loop() {
  // Run through various tests
  textRotationTest();
  delay(5000);
  shapeDrawingTest();
  delay(5000);
  colorBarsTest();
  delay(5000);
}

void drawTestPattern() {
  // Draw border
  tft.drawRect(0, 0, 128, 160, WHITE);
  
  // Draw colored rectangles
  tft.fillRect(10, 10, 30, 30, RED);
  tft.fillRect(50, 10, 30, 30, GREEN);
  tft.fillRect(90, 10, 30, 30, BLUE);
  
  tft.fillRect(10, 50, 30, 30, YELLOW);
  tft.fillRect(50, 50, 30, 30, CYAN);
  tft.fillRect(90, 50, 30, 30, MAGENTA);
  
  // Draw text
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(1);
  tft.setCursor(10, 90);
  tft.print("ESP32");
  
  tft.setCursor(10, 105);
  tft.print("ST7735");
  
  tft.setTextSize(2);
  tft.setCursor(10, 125);
  tft.print("OK");
}

void colorTest() {
  // Test solid colors to verify display variant is correct [citation:10]
  tft.fillScreen(RED);
  delay(1000);
  tft.fillScreen(GREEN);
  delay(1000);
  tft.fillScreen(BLUE);
  delay(1000);
  tft.fillScreen(WHITE);
  delay(1000);
  tft.fillScreen(BLACK);
  delay(1000);
}

void textRotationTest() {
  tft.fillScreen(BLACK);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(1);
  
  for (int i = 0; i < 4; i++) {
    tft.setRotation(i);
    tft.setCursor(10, 10);
    tft.printf("Rotation %d", i);
    delay(1000);
  }
  tft.setRotation(1); // Back to default
}

void shapeDrawingTest() {
  tft.fillScreen(BLACK);
  
  // Draw lines
  for (int i = 0; i < tft.width(); i += 10) {
    tft.drawLine(0, 0, i, tft.height() - 1, GREEN);
    delay(50);
  }
  
  // Draw circles
  tft.fillCircle(64, 80, 20, RED);
  tft.fillCircle(64, 80, 10, YELLOW);
  delay(1000);
  
  // Draw rectangles
  tft.drawRect(10, 10, 108, 140, BLUE);
  tft.fillRect(20, 20, 88, 120, MAGENTA);
  delay(1000);
}

void colorBarsTest() {
  // Draw vertical color bars
  int barWidth = tft.width() / 8;
  uint16_t colors[] = {BLACK, BLUE, RED, MAGENTA, GREEN, CYAN, YELLOW, WHITE};
  
  for (int i = 0; i < 8; i++) {
    tft.fillRect(i * barWidth, 0, barWidth, tft.height(), colors[i]);
  }
  delay(2000);
}