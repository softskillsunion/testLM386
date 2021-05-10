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
  soundVolume = map(soundVolume, 100, 850, 0, 10);
  // soundVolume = map(soundVolume, 50, 300, 0, 10); // WDA藍瓶
  if (soundVolume == 0)
  {
    counter++;
    if (counter >= times)
    {
      strip.clear();
      strip.show();
      Serial.println(0);
    }
  }
  if (soundVolume == 1)
  {
    if (counter < times)
    {
      setColor(soundVolume, 255, 0, 255);
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
      setColor(soundVolume, 0, 255, 255);
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
      setColor(soundVolume, 0, 0, 255);
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
      setColor(soundVolume, 0, 255, 0);
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
      setColor(soundVolume, 255, 209, 5);
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
      setColor(soundVolume, 255, 88, 10);
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
      setColor(soundVolume, 255, 97, 176);
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
      setColor(soundVolume, 255, 0, 0);
      // clearPixel(soundVolume);
      strip.show();
      Serial.println(6);
    }
    counter = 0;
  }

  delay(60);
}

void setColor(int endPixel, int R, int G, int B)
{
  for (int i = 0; i < endPixel; i++)
  {
    strip.setPixelColor(i, strip.Color(R, G, B));
  }
}

void clearPixel(int startPixel)
{
  for (int i = startPixel; i < pixels; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
}