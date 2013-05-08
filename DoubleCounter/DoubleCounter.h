/*
DoubleCounter.h - Library for a 7-segment LED and a shift register
Created by Elias S. Fatsi, April 29th, 2013.
Released into the public domain.
*/

#ifndef DoubleCounter_h
#define DoubleCounter_h

#include "Arduino.h"

class DoubleCounter
{
  public:
    DoubleCounter(int serialPin, int registerClockPin, int serialClockPin);
    void init();
    void draw(int number);
  protected:
    int _registerClockPin;
    int _serialClockPin;
    int _serialPin;
    int _numberOfPins;
    bool _registers[16];
    void setRegisterPin(int index, int value);
    void clearRegisters();
    void writeRegisters();
  
};

#endif
