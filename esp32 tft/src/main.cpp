#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <String.h>

#define TFT_CS  5
#define TFT_DC  32
#define TFT_RST 15


int circlex = 80; int circley = 64; int state = 1; int circlevel = 1;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// Small offscreen buffer (fits even on small boards)
GFXcanvas16 canvas(128, 160);

void check_inbounds(int x, int y) {
  switch (state) {
    case 1: // left
      x--;
      if (x <= 0) {
        x++;
        state = 3;
      }
    case 2: // right
      x++;
      if (x >= 128) {
        x--;
        state = 4;
      }
    case 3: // up
      y--;
      if (y <= 0) {
        y++;
        state = 2;
      }
    case 4: // down
      y++;
      if (y >= 160) {
        y--;
        state = 1;
      }
  } 
  
}
void setup() {
    tft.initR(INITR_BLACKTAB);
    tft.fillScreen(ST77XX_BLACK);
}

void loop() {

    // Draw everything to RAM first
    canvas.fillScreen(ST77XX_BLACK);
    canvas.setTextColor(ST77XX_WHITE);
    canvas.setTextSize(2);
    canvas.setCursor(10, 10);
    canvas.print(circlex);
    check_inbounds(circlex, circley);
    canvas.drawCircle(circlex, circley, 3, ST7735_WHITE);

    // Push only that region to display
    tft.drawRGBBitmap(0, 60, canvas.getBuffer(), 128, 40);

    delay(100);
}