/*
  ShotPour.h - Library for controlling alcohol servo.
  Created by Elias S. Fatsi, April 19, 2013.
  Released into the public domain.
*/

#ifndef ShotPour_h
#define ShotPour_h

#include "Arduino.h"
#include <Servo.h>

class ShotPour
{
  public:
    ShotPour(int servoPin, int blue, int red, int yellow, int green);
    void pour();
    void initialize();
  private:  
    int _servoPin;
    int _blue;
    int _red;
    int _yellow;
    int _green;
    int _bottom;
    int _top;
    Servo _servo;
};

#endif
