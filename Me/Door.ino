#include <Adafruit_NeoPixel.h>  // Adafruit.com's library for using Neopixels

#define PIN    6        // Data is transmitted from Data Pin #6 on the Arduino board
#define NUM_LEDs 26     // 26 LEDs, one per letter
#define BRIGHTNESS 64   // Out of 255, this is used to adjust light level since 26 LEDs will all be drawing power at once
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDs, PIN, NEO_GRB + NEO_KHZ800); // Initialize the Neopixel strip

/* In Stranger Things, the lights running across the letters are placed in a 'Z' pattern
 * 
 * Letters    | Indices |  Quantity LEDs 
 * --------------------------------------
 *  A - H     [  0 - 7  ]       8
 *  Q - I     [  8 - 16 ]       9
 *  R - Z     [ 17 - 25 ]       9
 * --------------------------------------
 * 
 * This means the alphabet is laid out with the second row flipped like:
 *          A   B   C   D   E   F   G   H 
 *        Q   P   O   N   M   L   K   J   I 
 *        R   S   T   U   V   W   X   Y   Z
*/

void setup() {
    strip.begin();
    randomSeed(analogRead(0));
}

void loop() {
    clearAll();
    randomizeLights();
    delay(10000);
    clearAll();
    spellJeffState();
    delay(5000);
}

static void randomizeLights() {
    for(int index = 0; index < NUM_LEDs; index++) {
        int r = random(BRIGHTNESS);
        int g = random(BRIGHTNESS);
        int b = random(BRIGHTNESS);
        strip.setPixelColor(index, r, g, b);
    }
    strip.show();
}

static void spellJeffState() {
    // These are the indexes of the array where each letter used to spell "Jeff State" is located
    int J = 15, E = 4, F = 5, S = 18, T = 19, A = 0;
    int jeffState[9] = { J, E, F, F, S, T, A, T, E };

    for(int index = 0; index < sizeof(jeffState)/sizeof(jeffState[0]); index++) {
        strip.setPixelColor(jeffState[index], 255, 0, 0);
        strip.show();
        delay(95);
    }
}

static void clearAll() {
    int index = 0;
    while(index++ < NUM_LEDs) {
        strip.setPixelColor(index, 0);
    }
}