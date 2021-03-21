#include "lacu/helpers.hpp"

#include "mazzu/Card.hpp"
#include "mazzu/Suit.hpp"
#include "mazzu/Deck.hpp"

#include <vector>
#include <iostream>

using std::vector;

void printDeckInfo(mazzu::Deck &deck)
{
  std::cout << "cards in deck: " << deck.getCardsLeft() << std::endl
            << std::endl;
}

void printCards(vector<mazzu::Card *> &cards)
{
  if (cards.size() == 0)
  {
    std::cout << "\t No Cards :(" << std::endl;
    return;
  }

  
  for (mazzu::Card *c : cards)
  {
    std::cout << "\t" << c->toString() << std::endl;
  }
}

void executeChoice(char c, mazzu::Deck &deck, vector<mazzu::Card *> &hand)
{
  switch (c)
  {
  case '\0':
    break;
  case 'h':
    std::cout << "hand:" << std::endl;
    printCards(hand);
    break;
  case 'd':
  {
    auto drawn = deck.draw();
    printCards(drawn);
    hand.insert(hand.end(), drawn.begin(), drawn.end());
    break;
  }
  default:
    std::cout << "Not a valid choice: " << c << std::endl;
    break;
  }
}

int main()
{
  const char QUIT = 'q';
  mazzu::Deck deck;
  char choice = '\0';
  deck.shuffle();
  vector<mazzu::Card *> hand;

  while (choice != QUIT)
  {
    lacu::cls();
    printDeckInfo(deck);
    executeChoice(choice, deck, hand);

    std::cout << "\n\n h) print Hand\n d) draw 1\n\n q) quit\n\n > ";
    std::cin >> choice;
  }

  std::cout << "kThxBye<3\n\n\n";

  return EXIT_SUCCESS;
}
