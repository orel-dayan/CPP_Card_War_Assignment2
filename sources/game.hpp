#ifndef WAR_GAME_HPP
#define WAR_GAME_HPP
#include "player.hpp"
#include "card.hpp"
#include <random>

namespace ariel
{
  class Game
  {
  private:
    Player &m_player1;
    Player &m_player2;
    /**
     * @brief A vector of strings representing the game's log.
     *
     */
    std::vector<std::string> m_roundsLogs;
    int m_draws;
    int m_rounds;
    /**
     * @brief A boolean representing if the players are the same.
     */
    bool m_isSame;

  public:
    /**
     * Constructs a new Game object with the given players.
     *
     * @param player1 a reference to the first player object
     * @param player2 a reference to the second player object
     */
    Game(Player &player1, Player &player2);
    /**
     * @brief Returns the number of rounds played in the game.
     *
     * @return The number of rounds played in the game.
     */
    void playTurn();
    /**
     * @brief Returns the number of draws in the game.
     *
     * @return The number of draws in the game.
     */

    void printLastTurn();
    /**
     * @brief Returns the number of rounds played in the game.
     *
     * @return The number of rounds played in the game.
     */
    void playAll();
    /**
     * @brief Returns the number of draws in the game.
     *
     * @return The number of draws in the game.
     */
    void printWiner();
    /**
     * @brief Returns the number of rounds played in the game.
     *
     * @return The number of rounds played in the game.
     */
    void printLog();
    /**
     * @brief the statistics of the game, including the number of draws, draw rate,
     * and the statistics for each player (number of wins, losses, and remaining cards).
     */

    void printStats();
  };
} // namespace ariel
#endif
