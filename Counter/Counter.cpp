/*
Counter.cpp - Library for a 7-segment LED and a shift register
Created by Elias S. Fatsi, April 29th, 2013.
Released into the public domain.
*/

#include "Arduino.h"
#include "Counter.h"

Counter::Counter(int serialPin, int registerClockPin, int serialClockPin)
{
  _serialPin        = serialPin;
  _serialClockPin   = serialClockPin;
  _registerClockPin = registerClockPin;

  boolean _registers[7];
}

void Counter::init() {
  pinMode(_serialPin, OUTPUT);
  pinMode(_registerClockPin, OUTPUT);
  pinMode(_serialClockPin, OUTPUT);

  clearRegisters();
  writeRegisters();
}

void Counter::clearRegisters()
{
  for(int i = 7 - 1; i >=  0; i--) {
     _registers[i] = LOW;
  }
}

void Counter::draw(int number)
{
  char* directory[]= {
    "11111100", // 0
    "01100000", // 1
    "11011010", // 2
    "11110010", // 3
    "01100110", // 4
    "10110110", // 5
    "10111110", // 6
    "11100000", // 7
    "11111110", // 8
    "11100110"  // 9
  };

  for (int i = 0; i < 7; i++) {
    setRegisterPin(i, directory[number][i] == '1');
  }

  writeRegisters();
}

void Counter::setRegisterPin(int index, int value)
{
  _registers[index] = value;
}

void Counter::writeRegisters()
{
  digitalWrite(_registerClockPin, LOW);

  for(int i = 7; i >=  0; i--){
    digitalWrite(_serialClockPin, LOW);

    int val = _registers[i];

    digitalWrite(_serialPin, val);
    digitalWrite(_serialClockPin, HIGH);

  }
  digitalWrite(_registerClockPin, HIGH);
  
}
