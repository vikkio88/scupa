#include "lacu/helpers.hpp"
#include <ostream>

namespace lacu
{
    void cls(std::ostream& o)
    {
        o << CLEAR_SCREEN;
    }
}