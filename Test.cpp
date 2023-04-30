
#include "doctest.h"
using namespace doctest;

#include <iostream>

#include "sources/card.hpp"
#include "sources/game.hpp"
#include "sources/player.hpp"
using namespace ariel;

TEST_CASE("Player cannot play with himself")
{
  Player p1("Alice");
  CHECK_THROWS(Game(p1, p1));
}

TEST_CASE("the name of the player cannot be null")
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
    game.playTurn();
  }
  CHECK((p1.cardesTaken() != 0 || p2.cardesTaken() != 0));
  CHECK(p1.stacksize() <= 21);
}

TEST_CASE("play all and play turn test")
{
  Player p1("p1");
  Player p2("p2");
  Game game(p1, p2);
  game.playAll();
  game.playAll();
  game.playTurn();
  // The game over which means one of the stack is empty
  CHECK(p1.stacksize() == 0);
  CHECK(p2.stacksize() == 0);
}

TEST_CASE("player test")
{
  Player p1("p1");
  Player p2("p2");
  CHECK(p1.stacksize() == 26);
  CHECK(p2.stacksize() == 26);
  CHECK(p1.cardesTaken() == 0);
  CHECK(p2.cardesTaken() == 0);
  Game game(p1, p2);
  game.playTurn();
  bool flag = (p1.stacksize() < 26) && (p2.stacksize() < 26);
  CHECK(flag);
  flag = (2 <= p1.cardesTaken()) || (2 <= p2.cardesTaken()); // 2 cards are taken in each turn
  CHECK(flag);
  CHECK(p1.stacksize() == p2.stacksize());     // The number of cards in each stack is the same
  CHECK(p1.cardesTaken() != p2.cardesTaken()); // The number of cards taken by each player is different
}

TEST_CASE("game test")
{

  Player p1("p1");
  Player p2("p2");
  Game game(p1, p2);
  CHECK_THROWS(Game(p1, p2));
  CHECK_THROWS(game.printLastTurn());
  CHECK_THROWS(game.printLog());
  CHECK_NOTHROW(game.playAll());
  bool flag = (p1.stacksize() == 0) && (p2.stacksize() == 0);
  CHECK(flag);
  flag = p1.cardesTaken() + p2.cardesTaken() == 52;
  CHECK(flag);
  CHECK_THROWS(game.playTurn());
  CHECK_THROWS(game.playAll());
}
