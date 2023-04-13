#include "card.hpp"
#include <string>
namespace ariel
{
  Card::Card(int number, Suit suit)
  {
    this->m_suit = suit;
    this->m_number = number;
  }

  std::string Card::getNumberRepresentation()
  {
    if (this->m_number == 1)
      return "Ace";

    if (this->m_number == 11)
      return "Prince";

    if (this->m_number == 12)
      return "Queen";

    if (this->m_number == 13)
      return "King";

    return std::to_string(this->m_number); // default case
  }

  std::string Card::getSuit()
  {
    switch (this->m_suit)
    {
    case DIAMONDS:
      return "Diamonds";
    case HEARTS:
      return "Hearts";
    case SPADES:
      return "Spades";
    default:
      return "Clubs";
    }
  }

  std::string Card::to_string()
  {
    return getNumberRepresentation() + " of " + getSuit();
  }

  int Card::getNumber()
  {
    return this->m_number;
  }
}
