#include <ButtonPlayer.h>

ButtonPlayer player1(2);

const int start = millis();
const int duration = 2000; // two seconds

void setup()
{
  Serial.begin(9600);
  Serial.println("begin");
}

void loop()
{
  if (player1.isPressed()) {
    player1.increment(1);
  }

  if (millis() - start > duration) {
    Serial.print("Final Score: ");
    Serial.println(player1.score());
    while(true) {
    }
  }
}