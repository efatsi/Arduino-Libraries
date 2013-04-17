/*
ReactionPlayer.cpp - Library for a button pressing player
Created by Elias S. Fatsi, April 12th, 2012.
Released into the public domain.
*/

#include "Arduino.h"
#include "ReactionPlayer.h"

ReactionPlayer::ReactionPlayer(int pin, int number) : ButtonPlayer(pin, number)
{
  _reacted = false;
}

bool ReactionPlayer::reacted()
{
  return _reacted;
}

void ReactionPlayer::setReaction(bool reacted)
{
  _reacted = reacted;
}
