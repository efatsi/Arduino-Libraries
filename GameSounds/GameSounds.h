/*
  GameSounds.h - Library for the sound sequence to start a game.
  Created by Elias S. Fatsi, April 12th, 2012.
  Released into the public domain.
*/

#ifndef GameSounds_h
#define GameSounds_h

#include "Arduino.h"

class GameSounds
{
  public:
    GameSounds(int pin);
    void start();
    void stop();
  private:  
    int frequency(char note);
    int _pin;
};

#endif
