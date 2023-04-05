#include "game.hpp"
#include <algorithm>
#include <iostream>
#include "../doctest.h"

namespace ariel
{

  using namespace std;

  Game::Game(Player &player1, Player &player2) : m_player1(player1), m_player2(player2)
  {
    this->m_draws = 0;
    this->m_rounds = 0;
    if (&player1 == &player2)
    {
      this->m_isSame = true;
    }
    else
    {
      this->m_isSame = false;
    }
    /*
     * 1. Create a deck of cards (spades, hearts, diamonds, clubs - 13 cards each = 52 cards)
     * 2. Shuffle the deck
     * 3. Deal 26 cards each to both players
     */

    vector<Card> deck;
    for (int i = 1; i <= 13; i++)
    {
      deck.push_back(Card(i, SPADES));
      deck.push_back(Card(i, HEARTS));
      deck.push_back(Card(i, DIAMONDS));
      deck.push_back(Card(i, CLUBS));
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);

    for (unsigned long int i = 0; i < 26; i++)
    {
      player1.pushCard(deck[i]);
      player2.pushCard(deck[i + 26]);
    }
  }

  void Game::playTurn()
  {
    if (this->m_isSame)
    {
      throw "no games against yourself";
    }
    if (m_player1.stacksize() == 0 || m_player2.stacksize() == 0)
    {
      throw "no more cards to play";
    }
    // init vars for the turn
    std::string log = "";
    bool round_complete = true;
    int winCards = 0; // for updating the stats

    while (round_complete)
    {
      this->m_rounds += 1;
      round_complete = false;
      // get the cards played by each player
      Card dlc1 = this->m_player1.dealCard();
      Card dlc2 = this->m_player2.dealCard();
      // update the number of cards won by each player
      winCards += 2;
      // add the cards to the log
      log += m_player1.printTurns(dlc1) + " " + m_player2.printTurns(dlc2) + ". ";
      // determine the winner

      if (dlc1.getNumber() == dlc2.getNumber()) // draw case
      {
        round_complete = true;
        log += "Draw.";
        //

        this->m_player1.dealCard();
        this->m_player2.dealCard();
        winCards += 2;      // for updating the stats
        this->m_draws += 1; // update the number of draws
      }
      //  Ace wins against all except for 2 cases
      else if (dlc1.getNumber() == 1 && dlc2.getNumber() != 2)
      {
        log += this->m_player1.getName() + " wins.";
        m_player1.updateStatsForRound(winCards);
        m_player2.updateStatsForRound(0);
      }
      else if (dlc1.getNumber() != 2 && dlc2.getNumber() == 1)
      {
        log += this->m_player2.getName() + " wins.";
        m_player2.updateStatsForRound(winCards);
        m_player1.updateStatsForRound(0);
      }

      // default case by value
      else if (dlc1.getNumber() > dlc2.getNumber())
      {
        log += this->m_player1.getName() + " wins.";
        m_player1.updateStatsForRound(winCards);
        m_player2.updateStatsForRound(0);
      }
      else if (dlc2.getNumber() > dlc1.getNumber())
      {
        log += this->m_player2.getName() + " wins.";
        m_player2.updateStatsForRound(winCards);
        m_player1.updateStatsForRound(0);
      }
    }
    log += "\n"; // round end
    this->m_roundsLogs.push_back(log);
  }

  void Game::printLastTurn()
  {
    cout << this->m_roundsLogs.back();
    cout << this->m_roundsLogs.back();
  }

  void Game::playAll()
  {
    while (this->m_player1.stacksize() > 0 && this->m_player2.stacksize() > 0)
    {
      playTurn();
    }
  }

  void Game::printWiner()
  {
    if (m_player1.cardesTaken() > m_player2.cardesTaken())
    {
      cout << m_player1.getName() + " won";
    }
    else if (m_player1.cardesTaken() < m_player2.cardesTaken())
    {
      cout << m_player1.getName() + " won";
    }
    else
      throw "no winner";
  }

  void Game::printLog()
  {
    for (std::string log : this->m_roundsLogs)
    {
      cout << log;
    }
  }

  void Game::printStats()
  {
    this->m_player1.printStats();
    this->m_player2.printStats();
    // Calculate and print draw rate and draws amount
    double draw_rate = m_draws;
    draw_rate /= m_rounds;
    cout << "--------------------------------" << endl;
    cout << "game stats" << endl;
    cout << "--------------------------------" << endl;
    cout << "draw rate:" << draw_rate << "\n";
    cout << "draws amount:" << this->m_draws << "\n";
  }

}
