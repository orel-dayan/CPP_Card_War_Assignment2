#include "player.hpp"
#include "card.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "../doctest.h"
using namespace std;

namespace ariel
{

  Player::Player(std::string name)
  {
    this->m_name = name;
    this->m_stack.clear(); // clear the stack
    this->m_cardsTaken = 0;
    this->m_rounds = 0;
    this->m_wonRounds = 0;
  }

  int Player::stacksize()
  {
    return m_stack.size();
  }

  int Player::cardesTaken()
  {
    return this->m_cardsTaken;
  }

  void Player::addCard(Card card)
  {
    this->m_stack.push_back(card);
  }

  void Player::updateStatsForRound(int cards)
  {
    this->m_rounds++;
    if (cards > 0)
    {
      this->m_cardsTaken += cards;
      this->m_wonRounds++;
    }
  }
  Card Player::dealCard()
  {
    Card card = Player::m_stack.back();
    Player::m_stack.pop_back();
    return card;
  }

  std::string Player::printTurns(Card card)
  {
    return this->m_name + " played " + card.toString();
  }

  void Player::printStats()
  {
    cout << "--------------------------------" << endl;
    cout << this->m_name << " stats report" << endl;
    cout << "--------------------------------" << endl;
    cout << "Cards taken: " << this->m_cardsTaken << endl;
    cout << "Rounds won: " << this->m_wonRounds << endl;
    cout << "Rounds played: " << this->m_rounds << endl;
    double win_rate = this->m_wonRounds;
    win_rate /= this->m_rounds;
    cout << "Win rate: " << win_rate << "\n";
    cout << "Cards won: " << this->m_cardsTaken << "\n";
  }
}
