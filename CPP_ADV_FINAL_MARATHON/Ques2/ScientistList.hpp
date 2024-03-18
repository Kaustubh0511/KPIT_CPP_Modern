#ifndef SCIENTISTLIST_HPP
#define SCIENTISTLIST_HPP

#include "Scientist.hpp"
class ScientistList : public list<Scientist *>
{
public:
    friend ostream &operator<<(ostream &os, ScientistList &scientistList);
    
};

#endif // SCIENTISTLIST_HPP
