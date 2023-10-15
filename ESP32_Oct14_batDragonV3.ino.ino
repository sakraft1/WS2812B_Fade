#include <FastLED.h>

#define LED_PIN         25    // Use pin 25 or 26 for data
#define NUM_LEDS        696
#define LED_TYPE        WS2812B
#define COLOR_ORDER     GRB
#define BRIGHTNESS      125  // Set maximum brightness (0 to 255)
#define FRAMES_PER_SECOND  120
#define FADE_TIME_MS    1000  // Fade time in milliseconds

CRGB leds[NUM_LEDS];

void setup() {
  delay(3000); // Delay for 3 seconds before starting the animation
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // Set the brightness of LEDs alternately
  for (uint16_t i = 0; i < NUM_LEDS; i++) {
    if (i % 2 == 0) {
      leds[i].setRGB(64, 0, 0);  // Set even-indexed LEDs to brightness 64 (red)
    } else {
      leds[i].setRGB(0, 0, 125); // Set odd-indexed LEDs to brightness 125 (blue)
    }
  }
  FastLED.show();
  delay(FADE_TIME_MS); // Delay before changing brightness again
}
