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
  setAlternateBrightness(64, 125);
  delay(FADE_TIME_MS); // Delay before next fade
  setAlternateBrightness(125, 64);
  delay(FADE_TIME_MS); // Delay before next fade
}

void setAlternateBrightness(uint8_t brightness1, uint8_t brightness2) {
  for (uint16_t i = 0; i < NUM_LEDS; i++) {
    if (i % 2 == 0) {
      leds[i].setRGB(leds[i].r * brightness1 / 255, leds[i].g * brightness1 / 255, leds[i].b * brightness1 / 255);
    } else {
      leds[i].setRGB(leds[i].r * brightness2 / 255, leds[i].g * brightness2 / 255, leds[i].b * brightness2 / 255);
    }
  }
  FastLED.show();
}
