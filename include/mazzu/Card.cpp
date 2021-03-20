#include "mazzu/Card.hpp"
#include "mazzu/Suit.hpp"

#include <sstream>

namespace mazzu
{

  Card::Card(int value, Suit suit) : m_Value(value), m_Suit(suit) {}
  std::string Card::toString()
  {
    std::stringstream ss;
    ss << m_Value << ", " << Card::suitToString(m_Suit);

    return ss.str();
  }

  std::string Card::suitToString(Suit suit)
  {
    switch (suit)
    {
    case Suit::DENARI:
      return "Denari";
    case Suit::SPADE:
      return "Spade";
    case Suit::MAZZE:
      return "Mazze";
    case Suit::COPPE:
      return "Coppe";
    default:
      break;
    }

    return "No Suit";
  }

}
