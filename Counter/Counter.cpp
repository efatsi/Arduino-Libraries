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
  int values[] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW };

  if (number == 0) {
    values[0] = HIGH;
    values[1] = HIGH;
    values[2] = HIGH;
    values[3] = HIGH;
    values[4] = HIGH;
    values[6] = HIGH;
  }
  else if (number == 1) {
    values[0] = HIGH;
    values[1] = HIGH;
  }
  else if (number == 2) {
    values[1] = HIGH;
    values[2] = HIGH;
    values[3] = HIGH;
    values[4] = HIGH;
    values[5] = HIGH;
  }
  else if (number == 3) {
    values[0] = HIGH;
    values[1] = HIGH;
    values[2] = HIGH;
    values[3] = HIGH;
    values[5] = HIGH;
  }
  else if (number == 4) {
    values[0] = HIGH;
    values[1] = HIGH;
    values[5] = HIGH;
    values[6] = HIGH;
  }
  else if (number == 5) {
    values[0] = HIGH;
    values[2] = HIGH;
    values[3] = HIGH;
    values[5] = HIGH;
    values[6] = HIGH;
  }
  else if (number == 6) {
    values[0] = HIGH;
    values[2] = HIGH;
    values[3] = HIGH;
    values[4] = HIGH;
    values[5] = HIGH;
    values[6] = HIGH;
  }
  else if (number == 7) {
    values[0] = HIGH;
    values[1] = HIGH;
    values[2] = HIGH;
  }
  else if (number == 8) {
    values[0] = HIGH;
    values[1] = HIGH;
    values[2] = HIGH;
    values[3] = HIGH;
    values[4] = HIGH;
    values[5] = HIGH;
    values[6] = HIGH;
  }
  else if (number == 9) {
    values[0] = HIGH;
    values[1] = HIGH;
    values[2] = HIGH;
    values[5] = HIGH;
    values[6] = HIGH;
  }

  for (int i = 0; i < 7; i++) {
    setRegisterPin(i+1, values[i]);
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
