#include <ButtonPlayer.h>
#include <ReactionPlayer.h>

ReactionPlayer player1(2, 1);
ReactionPlayer player2(3, 2);

ReactionPlayer players[] = {
  player1, player2};
const int playerCount = 2;

int last           = millis();
int rounds         = 0;
int randomInterval = 2000 + random(3000);
const int totalRounds = 4;

void setup()
{
  Serial.begin(9600);
  Serial.println("begin");
}

void loop()
{
  if (millis() - last > randomInterval) {
    Serial.println("NOW");

    while (notAllPlayersPressed()) {
      for(int i = 0; i < playerCount; i++) {
        checkForReaction(i);
      }
    }
    rounds++;
    last           = millis();
    randomInterval = 2000 + random(2000);
    resetReactions();
  }
  else {
    checkForPenalties();
  }

  if (rounds >= totalRounds) {
    printScores();
    while(true) {
    }
  }
}

boolean notAllPlayersPressed()
{
  for(int i = 0; i < playerCount; i++) {
    if (players[i].reacted() == false) {
      return true;
    }
  }
  return false;
}

void checkForReaction(int i)
{
  if (players[i].isPressed() && players[i].reacted() == false) {
    Serial.print("Player ");
    Serial.print(players[i].number());
    Serial.print(": ");
    Serial.println((millis() - last - randomInterval) / 1000.0);
    players[i].increment(millis() - last - randomInterval);
    players[i].setReaction(true);
  }
}

void resetReactions()
{
  for(int i = 0; i < playerCount; i++) {
    players[i].setReaction(false);
  }
}

void checkForPenalties()
{
  for(int i = 0; i < playerCount; i++) {
    if (players[i].isPressed()) {
      Serial.print("PENALTY. Adding 200 milliseconds to Player ");
      Serial.println(players[i].number());
      players[i].increment(200);
    }
  }  
}

void printScores()
{
  Serial.println("Game Over");
  Serial.println("Scores:");
  for(int i = 0; i < playerCount; i++) {
    Serial.print("Player ");
    Serial.print(players[i].number());
    Serial.print(": ");
    Serial.println(players[i].score() / 1000.0);
  }
}
