#include "lacu/helpers.hpp"

#include "mazzu/Card.hpp"
#include "mazzu/Suit.hpp"
#include "mazzu/Deck.hpp"

#include <vector>
#include <iostream>

using std::vector;

int main()
{
  lacu::cls(std::cout);
  mazzu::Deck deck;
  deck.shuffle();

  std::cout << "cards in deck: " << deck.getCardsLeft() << std::endl;
  vector<mazzu::Card *> hand = deck.draw(4);

  std::cout << "hand:" << std::endl;
  for (mazzu::Card *c : hand)
  {
    std::cout << "\t" << c->toString() << std::endl;
  }
  std::cout << "\ncards left: " << deck.getCardsLeft() << std::endl;

  return EXIT_SUCCESS;
}
