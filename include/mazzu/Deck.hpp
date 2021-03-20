#pragma once

#include <vector>
#include "mazzu/Card.hpp"

using std::vector;

namespace mazzu
{
    class Deck
    {
    private:
        vector<Card *> m_Deck;
        vector<Card *> m_DiscardPile;
        vector<Suit> m_Suits;

    public:
        static const int MAX_CARDS = 40;
        Deck();

        int getCardsLeft();
        int getDiscarded();

        void shuffle();
        vector<Card *> draw(int);
        void discard(Card *);
    };
}