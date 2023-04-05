#ifndef WAR_PLAYER_HPP
#define WAR_PLAYER_HPP
#include <string>
#include <vector>
#include "card.hpp"
namespace ariel
{
  class Player
  {
  private:
    std::vector<Card> m_stack;
    std::string m_name;
    int m_wonRounds;
    int m_rounds;
    int m_cardsTaken;

  public:
    /**
     * @brief Construct a new Player object
     *
     * @param name  The name of the player
     */

    Player(std::string name);

    /**
     * @brief Get the name of the player
     *
     * @return std::string  The name of the player
     */

    std::string getName() const { return this->m_name; };

    /**
     * @brief Return the amount of cards left to the player
     *
     * @return amount of cards
     */

    int stacksize();

    /**
     * @brief Return the amount of cards the player has won
     *
     * @return  amount of cards
     */

    int cardesTaken();
    /**
     * @brief Add a card to the player's stack
     *
     * @param card  The card to add
     */
    void pushCard(Card card);

    /**
     * @brief Adds a round to the player's record and updates the player's stats.
     *
     * This function increments the player's round count and updates the player's stats
     * based on the number of cards won during the round. If the number of cards won is
     * greater than zero, the player's total cards won and rounds won are incremented.
     *
     * @param cards  The number of cards won by the player during the round.
     */

    void updateStatsForRound(int cards);

    /**
     * @brief Removes the top card from the player's stack of cards and returns it.
     *
     * This function removes the top card from the player's stack of cards and returns it.
     *
     * @return The top card from the player's stack of cards.
     */
    Card dealCard();

    /**
     * @brief Returns a string representation of the player's turn.
     *
     * @param card The card that the player played on their turn.
     * @return A string in the format "[player name] played [card]".
     */

    std::string printTurns(Card card);

    /**
     * @brief Print the player's stats
     *
     */

    void printStats();
  };
} // namespace ariel
#endif // WAR_PLAYER_HPP
