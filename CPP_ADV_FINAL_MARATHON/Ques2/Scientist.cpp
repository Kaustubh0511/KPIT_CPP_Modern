#include "Scientist.hpp"

ostream &operator<<(ostream &os, Scientist &sc)
{
    os << "\t\t\t" << sc.name;
    return os;
}