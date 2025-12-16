#include <Adafruit_NeoPixel.h>
#include <AMY-Arduino.h>
#include "UsbMidi.h"

#define PIN 48
#define NUMPIXELS 1

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
UsbMidi usbMidi;

void onMidiMessage(const uint8_t (&data)[4]) {
    Serial.println("MIDI Message Received:");

    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
    pixels.show();

    delay(500);

    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();          
}

void onDeviceConnect() {
    Serial.println("MIDI Device Connected");
}

void setup() {
    Serial.begin(115200);
    
    pixels.begin();
    pixels.setBrightness(5);

    amy_config_t amy_config = amy_default_config();
    amy_start(amy_config);
    amy_live_start();

    usbMidi.onMidiMessage(onMidiMessage);
    usbMidi.onDeviceConnected(onDeviceConnect);
    usbMidi.begin();
}

void loop() {
    usbMidi.update();
    amy_update();
}