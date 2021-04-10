#include "mazzu/Card.hpp"
#include "mazzu/Suit.hpp"

#include <sstream>

namespace mazzu
{

  Card::Card(int value, Suit suit) : m_Value(value), m_Suit(suit) {}
  std::string Card::toString()
  {
    std::stringstream ss;
    ss << m_Value << ", " << suitNames[m_Suit];

    return ss.str();
  }

}
