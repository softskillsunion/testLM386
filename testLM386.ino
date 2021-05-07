#include <Adafruit_NeoPixel.h>
int ledPin = D5;
int soundVolume = 0;
int lastSoundVolume = 0;

Adafruit_NeoPixel strip(1, ledPin, NEO_RGB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  strip.begin();           
  strip.show();           
  strip.setBrightness(255);
}

void loop() {
soundVolume = analogRead(A0);
Serial.println(soundVolume);
if (lastSoundVolume!=soundVolume) {
if (soundVolume=0) {
  strip.setPixelColor(0, strip.Color(0, 0, 0));
    strip.show();
}
if (soundVolume>30 && soundVolume<=60) {
  strip.setPixelColor(0, strip.Color(0, 100, 0));
    strip.show();
}
if (soundVolume>60 && soundVolume<=90) {
  strip.setPixelColor(0, strip.Color(0, 255, 0));
    strip.show();
}
if (soundVolume>90 && soundVolume<=120) {
  strip.setPixelColor(0, strip.Color(0, 100, 100));
    strip.show();
}
if (soundVolume>120 && soundVolume<=150) {
  strip.setPixelColor(0, strip.Color(0, 255, 255));
    strip.show();
}
if (soundVolume>150 && soundVolume<=180) {
  strip.setPixelColor(0, strip.Color(0, 0, 100));
    strip.show();
}
if (soundVolume>180 && soundVolume<=210) {
  strip.setPixelColor(0, strip.Color(0, 0, 255));
    strip.show();
}
if (soundVolume>210 && soundVolume<=240) {
  strip.setPixelColor(0, strip.Color(100, 0, 100));
    strip.show();
}
if (soundVolume>240 && soundVolume<=270) {
  strip.setPixelColor(0, strip.Color(255, 0, 255));
    strip.show();
}
if (soundVolume>270 && soundVolume<=300) {
  strip.setPixelColor(0, strip.Color(100, 0, 0));
    strip.show();
}
if (soundVolume>300) {
  strip.setPixelColor(0, strip.Color(255, 0, 0));
    strip.show();
}
delay(80);
}
lastSoundVolume = soundVolume;
}
