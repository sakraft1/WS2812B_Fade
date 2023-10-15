#include <FastLED.h>

#define LED_PIN         25    // Use pin 25 or 26 for data
#define NUM_LEDS        696
#define LED_TYPE        WS2812B
#define COLOR_ORDER     GRB
#define BRIGHTNESS      125  // Set maximum brightness (0 to 255)
#define FRAMES_PER_SECOND  120
#define FADE_TIME_MS    1000  // Fade time in milliseconds

CRGB leds[NUM_LEDS];

// Define an array of the colors you want to use
CRGB colors[] = {
  CRGB(128, 0, 64),    // Dark Pink
  CRGB::Cyan,
  CRGB(230, 130, 255), // Lavender
};

void setup() {
  delay(3000); // Delay for 3 seconds before starting the animation
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // Set the color and brightness of LEDs alternately
  for (uint16_t i = 0; i < NUM_LEDS; i++) {
    // Alternate colors and brightness based on the LED's index
    uint8_t colorIndex = i % sizeof(colors);
    CRGB color = colors[colorIndex];
    
    if (i % 2 == 0) {
      color.nscale8_video(64);  // Adjust brightness for even-indexed LEDs
    } else {
      color.nscale8_video(125); // Adjust brightness for odd-indexed LEDs
    }
    
    leds[i] = color;
  }
  FastLED.show();
  delay(FADE_TIME_MS); // Delay before changing colors and brightness again
}
