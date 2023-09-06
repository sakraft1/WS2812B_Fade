#include <FastLED.h>

#define LED_PIN         3   // Use pin 3 for data
#define NUM_LEDS        300
#define LED_TYPE        WS2812B
#define COLOR_ORDER     GRB
#define BRIGHTNESS      255  // Set maximum brightness (0 to 255)
#define FRAMES_PER_SECOND  120
#define FADE_TIME_MS    4000  // Fade time in milliseconds

CRGB leds[NUM_LEDS];

void setup() {
  delay(3000); // Delay for 3 seconds before starting the animation
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  fadeToColor(CRGB::White, CRGB::Cyan, FADE_TIME_MS);         // Fade from White to Cyan
  fadeToColor(CRGB::Cyan, CRGB(230, 130, 255), FADE_TIME_MS);  // Fade from Cyan to Lavender
  fadeToColor(CRGB(230, 130, 255), CRGB(128, 0, 64), FADE_TIME_MS);  // Fade from Lavender to Dark Pink
  fadeToColor(CRGB(128, 0, 64), CRGB::White, FADE_TIME_MS);  // Fade from Dark Pink to White
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
    }

    FastLED.show();
    delay(1000 / FRAMES_PER_SECOND);
  }
}
