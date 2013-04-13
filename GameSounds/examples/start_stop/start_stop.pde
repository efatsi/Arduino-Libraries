#include <GameSounds.h>

GameSounds buzzer(9);

void setup()
{
}

void loop()
{
  buzzer.start();
  delay(5000);
  buzzer.stop();
  while(true){
  }
}