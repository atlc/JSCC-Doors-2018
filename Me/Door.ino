#include <Adafruit_NeoPixel.h>  // Adafruit.com's library for using Neopixels

#define PIN    6        // Data is transmitted from Data Pin #6 on the Arduino board
#define NUM_LEDs 26     // 26 LEDs, one per letter
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDs, PIN, NEO_GRB + NEO_KHZ800); // Initialize the Neopixel strip

/* In Stranger Things, the lights running across the letters are placed in a 'Z' pattern
 * 
 * This means the alphabet is logically laid out with the second row flipped like:
 *  
 *  A B C D E F G H ||| Q P O N M L K J I ||| R S T U V W X Y Z
 * 
 * Letters    | Indices |  Quantity LEDs 
 * --------------------------------------
 *  A - H     [  0 - 7  ]       8
 *  Q - I     [  8 - 16 ]       9
 *  R - Z     [ 17 - 25 ]       9
 * --------------------------------------
 * 
*/

void setup() {
    strip.begin();
    randomSeed(analogRead(0));
}

void loop() {
    strip.clear();
    randomizeLights();
    delay(10000);
    strip.clear();
    spellJeffState();
    delay(5000);
}

static void randomizeLights() {
    uint32_t red = strip.Color(128,0,0);
    uint32_t blue = strip.Color(0,0,128);
    uint32_t green = strip.Color(0,128,0);
    uint32_t orange = strip.Color(90,50,0);
    uint32_t purple = strip.Color(64,0,64);

    uint32_t colors[] = { red, blue, green, orange, purple };
    
    for(int index = 0; index < NUM_LEDs; index++) {
        strip.setPixelColor(index, colors[random(5)]);
    }
    strip.show();
}

static void spellJeffState() {
    // These are the indexes of the array where each letter used to spell "Jeff State" is located
    int J = 15, E = 4, F = 5, S = 18, T = 19, A = 0, space = 27;
    // Creates an integer array where the above indexes are used to spell Jeff State
    int jeffState[] = { J, space, E, space, F, space, F, space, space, S, space, T, space, A, space, T, space, E };

    for(int index = 0; index < sizeof(jeffState)/sizeof(jeffState[0]); index++) {
        strip.setPixelColor(jeffState[index], 255, 0, 0);
        strip.show();
        delay(400);
        strip.clear();
    }
}