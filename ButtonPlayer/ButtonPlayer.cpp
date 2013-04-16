/*
ButtonPlayer.cpp - Library for a button pressing player
Created by Elias S. Fatsi, April 12th, 2012.
Released into the public domain.
*/

#include "Arduino.h"
#include "ButtonPlayer.h"

ButtonPlayer::ButtonPlayer(int pin, int number)
{
  pinMode(pin, INPUT);
  _pin    = pin;
  _number = number;
  _score  = 0;
  _reacted = false;

  _lastButtonPress = millis();
  _bounceBuffer    = 20;
}

bool ButtonPlayer::isPressed()
{
  _buttonState = digitalRead(_pin);
  if (_buttonState == LOW) {
    if (millis() - _lastButtonPress > _bounceBuffer) {
      Serial.println(millis() - _lastButtonPress);
      _lastButtonPress = millis();
      return true;
    }
    else {
      _lastButtonPress = millis();
    }
  }
  return false;
}

void ButtonPlayer::increment()
{
  _score++;
}

void ButtonPlayer::increment(int score)
{
  _score += score;
}

int ButtonPlayer::score()
{
  return _score;
}

int ButtonPlayer::number()
{
  return _number;
}

bool ButtonPlayer::reacted()
{
  return _reacted;
}

void ButtonPlayer::setReaction(bool reacted)
{
  _reacted = reacted;
}
