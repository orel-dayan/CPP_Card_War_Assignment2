#include "card.hpp"
#include <string>
namespace ariel
{
  Card::Card(int number, Suit suit)
  {
    this->m_suit = suit;
    this->m_number = number;
  }

  std::string Card::getNumberString()
  {
    if (this->m_number == 1)
    {
      return "Ace";
    }
    if (this->m_number == 11)
    {
      return "Prince";
    }
    if (this->m_number == 12)
    {
      return "Queen";
    }
    if (this->m_number == 13)
    {
      return "King";
    }
    // default case
    return std::to_string(this->m_number);
  }

  std::string Card::getSuitString()
  {
    switch (this->m_suit)
    {
    case DIAMONDS:
      return "Diamonds";
    case SPADES:
      return "Spades";
    case HEARTS:
      return "Hearts";
    default:
      return "Clubs";
    }
  }

  std::string Card::toString()
  {
    return getNumberString() + " of " + getSuitString();
  }

  int Card::getNumber()
  {
    return this->m_number;
  }
}
