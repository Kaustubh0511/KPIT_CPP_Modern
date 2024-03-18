#include "ScientistList.hpp"

ostream &operator<<(ostream &os, ScientistList &scientistList)
{
    for (auto scientist : scientistList)
    {
        os << *scientist << '\n';
    }
    return os;
}