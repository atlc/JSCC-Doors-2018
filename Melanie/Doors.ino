#include <Adafruit_NeoPixel.h>  // Adafruit.com's library for using Neopixels

#define PIN    6        // Data is transmitted from Data Pin #6 on the Arduino board
Adafruit_NeoPixel headlightStrip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800); // Initialize the Neopixel strip cut into pieces
Adafruit_NeoPixel warningLightStrip = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800); // Initialize the Neopixel "strip" of 2 rings


void setup() {
    headlightStrip.begin();
    warningLightStrip.begin();
}

void loop() {
    headlights();
    warningLights();
}

static void headlights() {
    for(int index = 0; index < 12; index++) {
        headlightStrip.setPixelColor(index, 50,50,40); // Might be too bright for power source, will test after getting boards
    }
    headlightStrip.show();
}

static void warningLights() {
    // Lights up the first ring
    for(int index = 0; index < 12; index++) {
        warningLightStrip.setPixelColor(index, 64,0,0); // Might be too bright for power source, will test after getting boards
    }
    warningLightStrip.show();
    delay(250);
    
    // Lights up the second ring
    for(int index = 12; index < 24; index++) {
        warningLightStrip.setPixelColor(index, 64,0,0); // Might be too bright for power source, will test after getting boards
    }
    warningLightStrip.show();
    delay(250);
}