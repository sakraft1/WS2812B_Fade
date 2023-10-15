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
  fadeToColor(CRGB(128, 0, 64), CRGB::Cyan, FADE_TIME_MS);         // Fade from Dark Pink to Cyan
  fadeToColor(CRGB::Cyan, CRGB(230, 130, 255), FADE_TIME_MS);  // Fade from Cyan to Lavender
  fadeToColor(CRGB(230, 130, 255), CRGB(128, 0, 64), FADE_TIME_MS);  // Fade from Lavender to Dark Pink
}

void fadeToColor(CRGB fromColor, CRGB toColor, uint16_t fadeTime) {
  uint32_t startTime = millis();
  uint32_t endTime = startTime + fadeTime;

  while (millis() < endTime) {
    float progress = (float)(millis() - startTime) / (float)fadeTime;

    CRGB targetColor;
    targetColor.red = fromColor.red + (toColor.red - fromColor.red) * progress;
    targetColor.green = fromColor.green + (toColor.green - fromColor.green) * progress;
    targetColor.blue = fromColor.blue + (toColor.blue - fromColor.blue) * progress;

    for (uint16_t i = 0; i < NUM_LEDS; i++) {
      leds[i] = targetColor;

      // Reduce brightness for every other pixel
      if (i % 2 == 0) {
        leds[i].fadeToBlackBy(192);  // Adjust brightness for even-indexed LEDs
      }
    }

    FastLED.show();
    delay(1000 / FRAMES_PER_SECOND);
  }
}
