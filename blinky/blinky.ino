#include <Adafruit_NeoPixel.h>
#include <AMY-Arduino.h>


#define PIN 48
#define NUMPIXELS 1

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    Serial.begin(115200);
    
    pixels.begin();
    pixels.setBrightness(5);

    amy_config_t amy_config = amy_default_config();
    amy_start(amy_config);
}

void loop() {
    Serial.println("Hello World");

    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.show();
    
    delay(500);

    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.show();
    
    delay(500);
}