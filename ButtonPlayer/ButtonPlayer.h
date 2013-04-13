/*
ButtonPlayer.h - Library for a button pressing player
Created by Elias S. Fatsi, April 12th, 2012.
Released into the public domain.
*/

#ifndef ButtonPlayer_h
#define ButtonPlayer_h

#include "Arduino.h"

class ButtonPlayer
{
  public:
    ButtonPlayer(int pin);
    bool isPressed();
    void increment();
    int score();
  private:
    int  _pin;
    int  _score;
    int  _buttonState;
    long _lastButtonPress;
    int  _bounceBuffer;
};

#endif
