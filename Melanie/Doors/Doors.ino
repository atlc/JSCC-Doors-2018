#include <Adafruit_NeoPixel.h>  // Adafruit.com's library for using Neopixels

#define PIN    6        // Data is transmitted from Data Pin #6 on the Arduino board
Adafruit_NeoPixel warningLightStrip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    warningLightStrip.begin();
}

void loop() {
     flashWarningLights();
}

 static void flashWarningLights() {
     for(int index = 0; index < 12; index++) {
         warningLightStrip.setPixelColor(index, 255,0,0);
     }
     warningLightStrip.show();
     delay(400);
     for(int index = 0; index < 12; index++) {
         warningLightStrip.setPixelColor(index, 0);
     }
     warningLightStrip.show();
     delay(400);
 }
