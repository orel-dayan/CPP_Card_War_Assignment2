#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unistd.h>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

int main()
{

  Player p1("Alice");
  Player p2("Bob");
  cout << "--------------------------------" << endl;
  cout << " p1 stack size: before " << p1.stacksize() << endl;
  cout << " p2 stack size before: " << p2.stacksize() << endl;
  Game game(p1, p2);
  cout << " p1 stack size after : " << p1.stacksize() << endl;
  cout << " p2 stack size after : " << p2.stacksize() << endl;
  for (int i = 0; i < 5; i++)
  {
    game.playTurn();
  }
  game.playAll();
  game.printLastTurn();
  game.printLog();
  game.printStats();
  game.printWiner();
  cout << "--------------------------------" << endl;

  Game game2(p1, p2);
  int maxTurns = 26;
  int i = 0;
  for (; i < 26 && p1.stacksize() > 0; i++)
  {
    game.playTurn();
  }
  if (maxTurns >= i)
  {
    cout << "The game ended after " << i << " turns" << endl;
  }
  cout << "--------------------------------" << endl;
  cout << " p1 stack size: " << p1.stacksize() << endl;
  cout << " p2 stack size: " << p2.stacksize() << endl;

  return 0;
}
