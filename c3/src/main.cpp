#include <Arduino.h>
#include <ESP32Servo.h>

Servo serv;

bool reversed = false;

void setup() {
    serv.attach(10);
    serv.write(90);
    pinMode(3, INPUT); // trigger
    pinMode(4, OUTPUT); // echo
}
void loop() {
    if (reversed) {
        
    }
}   