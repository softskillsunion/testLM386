#include <Adafruit_NeoPixel.h>
int ledPin = D5;
int soundVolume = 0;
int counter = 0;
int times = 3;

Adafruit_NeoPixel strip(1, ledPin, NEO_RGB + NEO_KHZ800);

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
  soundVolume = map(soundVolume, 0, 350, 0, 10); // soundVolume = map(soundVolume, 0, 1024, 0, 10);
  if (soundVolume == 0)
  {
    counter++;
    if (counter >= times)
    {
      strip.setPixelColor(0, strip.Color(0, 0, 0));
      strip.show();
      // strip.clear();
      Serial.println(0);
    }
  }
  if (soundVolume == 1)
  {
    if (counter < times)
    {
      strip.setPixelColor(0, strip.Color(0, 255, 255));
      strip.show();
      Serial.println(1);
    }
    counter = 0;
  }
  if (soundVolume == 2)
  {
    if (counter < times)
    {
      strip.setPixelColor(0, strip.Color(0, 255, 0));
      strip.show();
      Serial.println(2);
    }
    counter = 0;
  }
  if (soundVolume == 3)
  {
    if (counter < times)
    {
      strip.setPixelColor(0, strip.Color(0, 0, 255));
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
      strip.show();
      Serial.println(4);
    }
    counter = 0;
  }
  if (soundVolume == 5)
  {
    if (counter < times)
    {
      strip.setPixelColor(0, strip.Color(255, 255, 0));
      strip.show();
      Serial.println(5);
    }
    counter = 0;
  }
  if (soundVolume >= 6)
  {
    if (counter < times)
    {
      strip.setPixelColor(0, strip.Color(255, 0, 0));
      strip.show();
      Serial.println(6);
    }
    counter = 0;
  }

  delay(60);
}
