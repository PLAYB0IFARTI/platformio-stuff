/*
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define MPU_ADDR 0x68

const float ACCEL_SCALE = 16384.0;
const float GYRO_SCALE  = 131.0;
const float FPS = 16.66666666667; // time between frames 60 fps
const float FPS_TIME = 0.01666666666666667;

int rotation_x = 0, rotation_y = 0, rotation_z = 0;

void calibrate() {
  int samples = 500;
  for (int i = 0; i > samples; i++) {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x43);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_ADDR, 6, true);

    int16_t GyX = (Wire.read() << 8) | Wire.read();
    int16_t GyY = (Wire.read() << 8) | Wire.read();
    int16_t GyZ = (Wire.read() << 8) | Wire.read();

    float gx = GyX / GYRO_SCALE;
    float gy = GyY / GYRO_SCALE;
    float gz = GyZ / GYRO_SCALE;

    rotation_x += gx;

  }

  rotation_x /= samples;
}

void setup() {
  Serial.begin(115200);
  Wire.begin();

  pinMode(25, OUTPUT);

  // Init OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Wake up MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission(true);

  calibrate();

  display.println("beboop");
}

void loop() {
  // --- Read accelerometer ---
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6, true);

  int16_t AcX = (Wire.read() << 8) | Wire.read();
  int16_t AcY = (Wire.read() << 8) | Wire.read();
  int16_t AcZ = (Wire.read() << 8) | Wire.read();

  float ax = AcX / ACCEL_SCALE;
  float ay = AcY / ACCEL_SCALE;
  float az = AcZ / ACCEL_SCALE;

  // --- Read gyroscope ---
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x43);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6, true);

  int16_t GyX = (Wire.read() << 8) | Wire.read();
  int16_t GyY = (Wire.read() << 8) | Wire.read();
  int16_t GyZ = (Wire.read() << 8) | Wire.read();

  float gx = GyX / GYRO_SCALE;
  float gy = GyY / GYRO_SCALE;
  float gz = GyZ / GYRO_SCALE;

  // --- Print to Serial ---
  Serial.print("Accel X="); Serial.print(ax);
  Serial.print(" Y="); Serial.print(ay);
  Serial.print(" Z="); Serial.print(az);
  Serial.print(" | Gyro X="); Serial.print(gx);
  Serial.print(" Y="); Serial.print(gy);
  Serial.print(" Z="); Serial.println(gz);

  // --- Display on OLED ---
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Accel:");
  display.print("X: "); display.print(ax, 2);
  display.print(" Y: "); display.println(ay, 2);
  display.print("Z: "); display.println(az, 2);

  display.println(); // empty line

  display.println("Gyro:");
  display.print("X: "); display.print(gx, 1);
  display.print(" Y: "); display.println(gy, 1);
  display.print("Z: "); display.println(gz, 1);

  float offset = (gx - rotation_x) * FPS;

  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Gyro offset");
  display.print("X offset: "); display.print(offset);
  display.println();
  display.print("X change: "); display.print(gx);

  if (-25 > rotation_x or rotation_x < 100) {digitalWrite(25, LOW);}
  else {digitalWrite(25, HIGH);}
  display.display();
  delay(FPS);
}

*/
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define MPU_ADDR 0x68

const float ACCEL_SCALE = 16384.0;
const float GYRO_SCALE  = 131.0;
const float FPS = 16.66666666667; // time between frames 60 fps
const float FPS_TIME = 0.01666666666666667;

int rotation_x = 0, rotation_y = 0, rotation_z = 0;

void calibrate() {
  int samples = 500;
  for (int i = 0; i > samples; i++) {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x43);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_ADDR, 6, true);

    int16_t GyX = (Wire.read() << 8) | Wire.read();
    int16_t GyY = (Wire.read() << 8) | Wire.read();
    int16_t GyZ = (Wire.read() << 8) | Wire.read();

    float gx = GyX / GYRO_SCALE;
    float gy = GyY / GYRO_SCALE;
    float gz = GyZ / GYRO_SCALE;

    rotation_x += gx;

  }

  rotation_x /= samples;
}

void setup() {
  Serial.begin(115200);
  Wire.begin();

  pinMode(25, OUTPUT);

  // Init OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Wake up MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission(true);

  calibrate();

  display.println("beboop");
}

void loop() {
  // --- Read accelerometer ---
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6, true);

  int16_t AcX = (Wire.read() << 8) | Wire.read();
  int16_t AcY = (Wire.read() << 8) | Wire.read();
  int16_t AcZ = (Wire.read() << 8) | Wire.read();

  float ax = AcX / ACCEL_SCALE;
  float ay = AcY / ACCEL_SCALE;
  float az = AcZ / ACCEL_SCALE;

  // --- Read gyroscope ---
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x43);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6, true);

  int16_t GyX = (Wire.read() << 8) | Wire.read();
  int16_t GyY = (Wire.read() << 8) | Wire.read();
  int16_t GyZ = (Wire.read() << 8) | Wire.read();

  float gx = GyX / GYRO_SCALE;
  float gy = GyY / GYRO_SCALE;
  float gz = GyZ / GYRO_SCALE;

  // --- Print to Serial ---
  Serial.print("Accel X="); Serial.print(ax);
  Serial.print(" Y="); Serial.print(ay);
  Serial.print(" Z="); Serial.print(az);
  Serial.print(" | Gyro X="); Serial.print(gx);
  Serial.print(" Y="); Serial.print(gy);
  Serial.print(" Z="); Serial.println(gz);

  // --- Display on OLED ---
 /* display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Accel:");
  display.print("X: "); display.print(ax, 2);
  display.print(" Y: "); display.println(ay, 2);
  display.print("Z: "); display.println(az, 2);

  display.println(); // empty line

  display.println("Gyro:");
  display.print("X: "); display.print(gx, 1);
  display.print(" Y: "); display.println(gy, 1);
  display.print("Z: "); display.println(gz, 1);*/

  float offset = (gx - rotation_x) * FPS;

  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Gyro offset");
  display.print("X offset: "); display.print(offset);
  display.println();
  display.print("X change: "); display.print(gx);

  if (-25 > rotation_x or rotation_x < 100) {digitalWrite(25, LOW);}
  else {digitalWrite(25, HIGH);}
  display.display();
  delay(FPS);
}

/*
#include <Arduino.h>
#include <Wire.h>



// Gyro base offsets
float gyroBaseX = 0, gyroBaseY = 0, gyroBaseZ = 0;

// Rotation angles
float rotX = 0, rotY = 0, rotZ = 0;

unsigned long lastTime = 0;

void readGyroRaw(int16_t &gx, int16_t &gy, int16_t &gz) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x43); // Starting register for gyro data
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6, true); // Read 6 bytes

  gx = (Wire.read() << 8) | Wire.read();
  gy = (Wire.read() << 8) | Wire.read();
  gz = (Wire.read() << 8) | Wire.read();
}

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Wake up MPU6050 (clear sleep bit)
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission(true);

  // --- Calibrate gyro ---
  Serial.println("Calibrating gyroscope... keep still!");
  const int samples = 500;
  for (int i = 0; i < samples; i++) {
    int16_t gx, gy, gz;
    readGyroRaw(gx, gy, gz);
    gyroBaseX += gx;
    gyroBaseY += gy;
    gyroBaseZ += gz;
    delay(5);
  }
  gyroBaseX /= samples;
  gyroBaseY /= samples;
  gyroBaseZ /= samples;

  Serial.println("Calibration done!");
  lastTime = micros();
}

void loop() {
  unsigned long currentTime = micros();
  float dt = (currentTime - lastTime) / 1000000.0; // seconds
  lastTime = currentTime;

  int16_t gx_raw, gy_raw, gz_raw;
  readGyroRaw(gx_raw, gy_raw, gz_raw);

  // Subtract baseline
  float gx = gx_raw - gyroBaseX;
  float gy = gy_raw - gyroBaseY;
  float gz = gz_raw - gyroBaseZ;

  // Convert to deg/sec (131 LSB = 1°/s at ±250°/s range)
  gx /= 131.0;
  gy /= 131.0;
  gz /= 131.0;

  // Integrate to get rotation
  rotX += gx * dt;
  rotY += gy * dt;
  rotZ += gz * dt;

  Serial.print("Rot X: "); Serial.print(rotX); Serial.print("°\t");
  Serial.print("Y: "); Serial.print(rotY); Serial.print("°\t");
  Serial.print("Z: "); Serial.print(rotZ); Serial.println("°");

  delay(50);
}
*/