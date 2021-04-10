#pragma once

#include <string>
#include "mazzu/Suit.hpp"

namespace mazzu
{

  class Card
  {
  private:
    int m_Value;
    Suit m_Suit;

  public:
    Card(int, Suit);
    std::string toString();
  };

}
