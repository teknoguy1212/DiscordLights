#include <FastLED.h>

#define LEDPIN     7
#define NUMOFLEDS    50

CRGB leds[NUMOFLEDS];


void setup() {

  FastLED.addLeds<WS2812, LEDPIN, GRB>(leds, NUMOFLEDS);
  LEDS.setBrightness(255);
  Serial.begin(9600);
}

void loop() {
  delay(20);
  int sound = analogRead(2);
  FastLED.clear();
  FastLED.show();
  if (sound < 400) {
    Serial.println(sound);
    int r = random(0,128);
    int g = random(r,255);
    int b = random(0,r);
    for (int i = 0; i <= NUMOFLEDS; i++) {
      leds[i] = CRGB ( r,g,b);
      FastLED.show();
      delay(20);
    }
    //r = random(0,128);
    //g = random(r,255);
    //b = random(0,r);
    for (int i = NUMOFLEDS; i >= 0; i--) {
     leds[i] = CRGB ( b,r,g);
      FastLED.show();
      delay(20);
    }
  }
}
