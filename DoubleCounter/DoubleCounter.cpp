/*
DoubleCounter.cpp - Library for a 7-segment LED and a shift register
Created by Elias S. Fatsi, April 29th, 2013.
Released into the public domain.
*/

#include "Arduino.h"
#include "DoubleCounter.h"

DoubleCounter::DoubleCounter(int serialPin, int registerClockPin, int serialClockPin)
{
  _serialPin        = serialPin;
  _serialClockPin   = serialClockPin;
  _registerClockPin = registerClockPin;

  _numberOfPins = 16;

  bool _registers[_numberOfPins];
}

void DoubleCounter::init() {
  pinMode(_serialPin, OUTPUT);
  pinMode(_registerClockPin, OUTPUT);
  pinMode(_serialClockPin, OUTPUT);

  clearRegisters();
  writeRegisters();
}

void DoubleCounter::clearRegisters()
{
  for(int i = _numberOfPins - 1; i >=  0; i--) {
     _registers[i] = LOW;
  }
}

void DoubleCounter::draw(int number)
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

  for (int i = 0; i < 8; i++) {
    setRegisterPin(i, directory[(number % 100) / 10][i] == '1');
    setRegisterPin(i + 8, directory[number % 10][i] == '1');
  }

  writeRegisters();
}

void DoubleCounter::setRegisterPin(int index, int value)
{
  _registers[index] = value;
}

void DoubleCounter::writeRegisters()
{
  digitalWrite(_registerClockPin, LOW);

  for(int i = _numberOfPins - 1; i >=  0; i--){
    digitalWrite(_serialClockPin, LOW);

    int val = _registers[i];

    digitalWrite(_serialPin, val);
    digitalWrite(_serialClockPin, HIGH);
  }

  digitalWrite(_registerClockPin, HIGH);
}
