#pragma once

#include <string>
namespace mazzu
{
    enum Suit
    {
        DENARI,
        SPADE,
        MAZZE,
        COPPE
    };
    /* C99 syntax :(
    constexpr std::string_view suitNames[] = {
        [DENARI] = "Denari",
        [SPADE] = "Spade",
        [MAZZE] = "Mazze",
        [COPPE] = "Coppe"
    };
    */

   constexpr std::string_view suitNames[] = {"Denari", "Spade", "Mazze", "Coppe"};
}