/*
GameSounds.cpp - Library for the sound sequence to start a game.
Created by Elias S. Fatsi, April 12th, 2012.
Released into the public domain.
*/

#include "Arduino.h"
#include "GameSounds.h"

GameSounds::GameSounds(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void GameSounds::start()
{
  tone(_pin, frequency('c'), 500);
  delay(1200);
  tone(_pin, frequency('c'), 500);
  delay(1400);
  tone(_pin, frequency('C'), 800);
}

void GameSounds::stop()
{
  tone(_pin, frequency('c'), 100);
  delay(120);
  tone(_pin, frequency('c'), 100);
  delay(120);
  tone(_pin, frequency('c'), 100);
}

int GameSounds::frequency(char note)
{
  int i;
  const int numNotes = 8;

  char names[]      = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = { 262, 294, 330, 349, 392, 440, 494, 523 };

  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);
}
