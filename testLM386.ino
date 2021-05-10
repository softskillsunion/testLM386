#include <Adafruit_NeoPixel.h>
int ledPin = D5;
int pixels = 8;
int soundVolume = 0;
int counter = 0;
int times = 3;

Adafruit_NeoPixel strip(pixels, ledPin, NEO_RGB + NEO_KHZ800);

void setup()
{
  Serial.begin(115200);
  strip.begin();
  strip.show();
  strip.setBrightness(255);
}

void loop()
{
  soundVolume = analogRead(A0);
  // soundVolume = map(soundVolume, 0, 1024, 0, 10);
  // soundVolume = map(soundVolume, 100, 850, 0, 10);
  soundVolume = map(soundVolume, 50, 300, 0, 10); // WDA藍瓶
  if (soundVolume == 0)
  {
    counter++;
    if (counter >= times)
    {
      strip.clear();
      strip.show();
      // clearPixel(soundVolume);
      Serial.println(0);
    }
  }
  if (soundVolume == 1)
  {
    if (counter < times)
    {
      strip.setPixelColor(0, strip.Color(255, 0, 255));
      clearPixel(soundVolume);
      strip.show();
      Serial.println(1);
    }
    counter = 0;
  }
  if (soundVolume == 2)
  {
    if (counter < times)
    {
      strip.setPixelColor(0, strip.Color(255, 0, 255));
      strip.setPixelColor(1, strip.Color(0, 255, 255));
      clearPixel(soundVolume);
      strip.show();
      Serial.println(2);
    }
    counter = 0;
  }
  if (soundVolume == 3)
  {
    if (counter < times)
    {
      strip.setPixelColor(0, strip.Color(255, 0, 255));
      strip.setPixelColor(1, strip.Color(0, 255, 255));
      strip.setPixelColor(2, strip.Color(0, 0, 255));
      clearPixel(soundVolume);
      strip.show();
      Serial.println(3);
    }
    counter = 0;
  }
  if (soundVolume == 4)
  {
    if (counter < times)
    {
      strip.setPixelColor(0, strip.Color(255, 0, 255));
      strip.setPixelColor(1, strip.Color(0, 255, 255));
      strip.setPixelColor(2, strip.Color(0, 0, 255));
      strip.setPixelColor(3, strip.Color(0, 255, 0));
      clearPixel(soundVolume);
      strip.show();
      Serial.println(4);
    }
    counter = 0;
  }
  if (soundVolume == 5)
  {
    if (counter < times)
    {
      strip.setPixelColor(0, strip.Color(255, 0, 255));
      strip.setPixelColor(1, strip.Color(0, 255, 255));
      strip.setPixelColor(2, strip.Color(0, 0, 255));
      strip.setPixelColor(3, strip.Color(0, 255, 0));
      strip.setPixelColor(4, strip.Color(255, 209, 5));
      clearPixel(soundVolume);
      strip.show();
      Serial.println(5);
    }
    counter = 0;
  }
  if (soundVolume == 6)
  {
    if (counter < times)
    {
      strip.setPixelColor(0, strip.Color(255, 0, 255));
      strip.setPixelColor(1, strip.Color(0, 255, 255));
      strip.setPixelColor(2, strip.Color(0, 0, 255));
      strip.setPixelColor(3, strip.Color(0, 255, 0));
      strip.setPixelColor(4, strip.Color(255, 209, 5));
      strip.setPixelColor(5, strip.Color(255, 88, 10));
      clearPixel(soundVolume);
      strip.show();
      Serial.println(6);
    }
    counter = 0;
  }
  if (soundVolume == 7)
  {
    if (counter < times)
    {
      strip.setPixelColor(0, strip.Color(255, 0, 255));
      strip.setPixelColor(1, strip.Color(0, 255, 255));
      strip.setPixelColor(2, strip.Color(0, 0, 255));
      strip.setPixelColor(3, strip.Color(0, 255, 0));
      strip.setPixelColor(4, strip.Color(255, 209, 5));
      strip.setPixelColor(5, strip.Color(255, 88, 10));
      strip.setPixelColor(6, strip.Color(255, 97, 176));
      clearPixel(soundVolume);
      strip.show();
      Serial.println(6);
    }
    counter = 0;
  }
  if (soundVolume == 8)
  {
    if (counter < times)
    {
      strip.setPixelColor(0, strip.Color(255, 0, 255));
      strip.setPixelColor(1, strip.Color(0, 255, 255));
      strip.setPixelColor(2, strip.Color(0, 0, 255));
      strip.setPixelColor(3, strip.Color(0, 255, 0));
      strip.setPixelColor(4, strip.Color(255, 209, 5));
      strip.setPixelColor(5, strip.Color(255, 88, 10));
      strip.setPixelColor(6, strip.Color(255, 97, 176));
      strip.setPixelColor(7, strip.Color(255, 0, 0));
      // clearPixel(soundVolume);
      strip.show();
      Serial.println(6);
    }
    counter = 0;
  }

  delay(60);
}

void clearPixel(int startPixel)
{
  for (int i = startPixel; i < pixels; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
}