#include <Servo.h>
#include <ShotPour.h>

const int servoPin = 3;
const int blue = 4;
const int red = 8;
const int yellow = 6;
const int green = 5;

ShotPour pourer(servoPin, blue, red, yellow, green);

void setup()
{
  pourer.initialize();
}

void loop()
{
  delay(3000);
  pourer.pour();
}
