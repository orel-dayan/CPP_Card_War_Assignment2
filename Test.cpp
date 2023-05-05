#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
using namespace ariel;

TEST_CASE(" Player cannot play with himself")
{
  Player p1("Alice");
  Game g(p1, p1);
  CHECK_THROWS(g.playTurn()); // in playTurn() function we check if the players are the same and throw an exception
}

TEST_CASE("the name of the player cannot be null") // the name of the player cannot be null
{
  CHECK_THROWS(Player(NULL));
}

TEST_CASE("cards taken and stack test")
{
  Player p1("p1");
  Player p2("p2");
  Game game(p1, p2);
  for (int i = 0; i < 5; i++) // 5 turns
  {
    game.playTurn(); // play turn
  }
  CHECK((p1.cardesTaken() != 0 || p2.cardesTaken() != 0)); // at least one card was taken by one of the players
  CHECK(p1.stacksize() <= 21);                             // at least 5 cards were taken by one of the players
}

TEST_CASE("Checking that at end of game both players have same number of cards")
{
  Player p1("Aviya");
  Player p2("Yael");
  Game game(p1, p2);
  game.playAll();
  CHECK(p1.stacksize() == p2.stacksize()); // The number of cards in each stack is the same at the end of the game
}

TEST_CASE("player test - checking different cases")
{
  Player p1("Sarah");
  Player p2("Yael");
  CHECK(p1.stacksize() == 0); // check the stack size of the player before the game
  CHECK(p2.stacksize() == 0);
  CHECK(p1.cardesTaken() == 0); // check the number of cards taken by the player before the game
  CHECK(p2.cardesTaken() == 0);
  Game game(p1, p2);
  CHECK(p1.stacksize() == 26); // check the stack size of the player after the game
  CHECK(p2.stacksize() == 26);
  game.playTurn();
  bool flag = (p1.stacksize() < 26) && (p2.stacksize() < 26); // The number of cards in each stack is less than 26
  CHECK(flag);
  flag = (2 <= p1.cardesTaken()) || (2 <= p2.cardesTaken()); // 2 cards are taken in each turn
  CHECK(flag);
  CHECK(p1.stacksize() == p2.stacksize());     // The number of cards in each stack is the same
  CHECK(p1.cardesTaken() != p2.cardesTaken()); // The number of cards taken by each player is different
}

TEST_CASE("print stats test")
{
  Player p1("Alice");
  Player p2(" Bob");
  Game game(p1, p2);
  CHECK_NOTHROW(game.printStats()); // print stats before the game
  for (int i = 0; i < 5; i++)
  {
    game.playTurn();
  }
  CHECK_NOTHROW(game.printStats()); // print stats after 5 turns
  game.playAll();
  CHECK_NOTHROW(game.printStats()); // print stats after the game
}

TEST_CASE("Get the winner before game is done")
{

  Player p1("Hod");
  Player p2("Aviv");
  Game game(p1, p2);
  game.playTurn();
  game.playTurn();
  game.playTurn();
  game.playTurn();                  // 4 turns played
  CHECK_NOTHROW(game.printWiner()); // print winner before game is done
  game.playAll();                   // play all the game
  CHECK_NOTHROW(game.printWiner()); // print winner
}

TEST_CASE("print log test")
{
  Player p1("Aviv");
  Player p2("Hod");
  Game game(p1, p2);              // game created
  CHECK_NOTHROW(game.printLog()); // print log before playing
}

TEST_CASE("number of cards in the game is 52 after the game is done ")
{
  Player p1("Shir");
  Player p2("Oren");
  Game game(p1, p2);
  game.playAll();
  CHECK(p1.cardesTaken() + p1.stacksize() + +p2.cardesTaken() + +p2.stacksize() == 52); // The number of cards in the game is 52
}
