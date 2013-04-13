/*
  ShotPour.h - Library for controlling alcohol servo.
  Created by Elias S. Fatsi, April 19, 2013.
  Released into the public domain.
*/

#include "Arduino.h"
#include "ShotPour.h"
#include <Servo.h>
#include <stdio.h>

ShotPour::ShotPour(int servoPin, int blue, int red, int yellow, int green)
{
  _servoPin = servoPin;
  _blue     = blue;
  _red      = red;
  _yellow   = yellow;
  _green    = green;

  _bottom = 145;
  _top = 45;

  pinMode(_blue,   OUTPUT);
  pinMode(_red,    OUTPUT);
  pinMode(_yellow, OUTPUT);
  pinMode(_green,  OUTPUT);
}


void ShotPour::initialize()
{
  _servo.attach(_servoPin);
  _servo.write(_bottom);
  
  digitalWrite(_yellow, LOW);
  digitalWrite(_green,  HIGH);
  digitalWrite(_blue,   HIGH);
}

void ShotPour::pour()
{
  int position;

  digitalWrite(_green, LOW);
  digitalWrite(_blue,  LOW);
  digitalWrite(_red,   HIGH);

  for(position = _bottom; position >= _top; position -= 5) {
    _servo.write(position);
    delay(15);
  }

  delay(3000);

  digitalWrite(_red,    LOW);
  digitalWrite(_yellow, HIGH);

  for(position = _top; position <= _bottom; position += 10) {
    _servo.write(position);
    delay(15);
  }

  delay(2300);
  digitalWrite(_yellow, LOW);
  digitalWrite(_green,  HIGH);
  digitalWrite(_blue,   HIGH);
}
