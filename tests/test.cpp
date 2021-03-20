#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "mazzu/Card.hpp"
#include "mazzu/Suit.hpp"

using mazzu::Card;
using mazzu::Suit;

TEST_CASE("Card Class toString", "[single-file]")
{
    Card card(1, Suit::SPADE);
    REQUIRE(card.toString() == "1, Spade");
}
