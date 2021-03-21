#include <vector>
#include <algorithm>
#include <random>

#include "mazzu/Deck.hpp"
#include "mazzu/Card.hpp"

using std::vector;

namespace mazzu
{
    Deck::Deck()
    {
        m_Suits = {Suit::DENARI, Suit::SPADE, Suit::MAZZE, Suit::COPPE};
        int cardsPerSuit = Deck::MAX_CARDS / m_Suits.size();
        for (Suit &s : m_Suits)
        {
            for (int i = 1; i <= cardsPerSuit; i++)
            {
                Card *c = new Card(i, s);

                m_Deck.push_back(c);
            }
        }
    }

    void Deck::shuffle()
    {
        std::random_device rd;
        std::default_random_engine rng(rd());
        std::shuffle(m_Deck.begin(), m_Deck.end(), rng);
    }

    vector<Card *> Deck::draw()
    {
        return draw(1);
    }

    vector<Card *> Deck::draw(int cards = 1)
    {
        vector<Card *> drawnCards;
        if (m_Deck.size() < cards)
            return drawnCards;

        for (int i = 0; i < cards; i++)
        {
            Card *c = m_Deck.back();
            m_Deck.pop_back();

            drawnCards.push_back(c);
        }

        return drawnCards;
    }

    void Deck::discard(Card *card)
    {
        m_DiscardPile.push_back(card);
    }

    int Deck::getCardsLeft()
    {
        return m_Deck.size();
    }

    int Deck::getDiscarded()
    {
        return m_DiscardPile.size();
    }

}