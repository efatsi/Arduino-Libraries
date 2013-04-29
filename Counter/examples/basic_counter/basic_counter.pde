#include <Counter.h>

const int serialPin        = 8;
const int registerClockPin = 9;
const int serialClockPin   = 10;

Counter counter(serialPin, registerClockPin, serialClockPin);

void setup(){
  counter.init();
}

void loop(){
  for (int i = 0; i < 10; i++) {
    counter.draw(i);
    delay(1000);
  }
}
