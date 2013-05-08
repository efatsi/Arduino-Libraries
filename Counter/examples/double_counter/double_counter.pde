#include <Counter.h>

const int serialPin1        = 4;
const int registerClockPin1 = 5;
const int serialClockPin1   = 6;

const int serialPin2        = 8;
const int registerClockPin2 = 9;
const int serialClockPin2   = 10;

Counter singlesCounter(serialPin1, registerClockPin1, serialClockPin1);
Counter tensCounter(serialPin2, registerClockPin2, serialClockPin2);

void setup()
{
  singlesCounter.init();
  tensCounter.init();
}

void loop()
{
  for (int i = 0; i < 100; i++) {
    tensCounter.draw(tensDigit(i));
    singlesCounter.draw(singlesDigit(i));
    delay(100);
  }
}

int singlesDigit(int i)
{
  return i % 10;
}

int tensDigit(int i)
{
  return (i % 100) / 10;
}
