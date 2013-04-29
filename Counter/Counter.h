/*
Counter.h - Library for a 7-segment LED and a shift register
Created by Elias S. Fatsi, April 29th, 2013.
Released into the public domain.
*/

#ifndef Counter_h
#define Counter_h

#include "Arduino.h"

class Counter
{
  public:
    Counter(int serialPin, int registerClockPin, int serialClockPin);
    void init();
    void draw(int number);
  protected:
    int _registerClockPin;
    int _serialClockPin;
    int _serialPin;
    bool _registers[7];
    void setRegisterPin(int index, int value);
    void clearRegisters();
    void writeRegisters();
  
};

#endif
