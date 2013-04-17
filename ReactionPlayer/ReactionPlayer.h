/*
ReactionPlayer.h - Library for a button pressing reaction player
Created by Elias S. Fatsi, April 12th, 2012.
Released into the public domain.
*/

#ifndef ReactionPlayer_h
#define ReactionPlayer_h

#include "Arduino.h"
#include "ButtonPlayer.h"

class ReactionPlayer : public ButtonPlayer {
public:
  ReactionPlayer(int pin, int number);
  bool reacted();
  void setReaction(bool reacted);
protected:
  bool _reacted;
};

#endif
