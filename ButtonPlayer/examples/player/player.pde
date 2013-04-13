#include <ButtonPlayer.h>

ButtonPlayer player1(2);

const int start = millis();
const int duration = 5000; // five seconds

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (player1.isPressed()) {
    player1.increment();
  }

  if (millis() - start > duration) {
    Serial.print("Final Score: ");
    Serial.println(player1.score());
    while(true) {
    }
  }
}