#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "MSP.hpp"
#include <string>
#include <ostream>
using std::string;

class computer
{

public:
    computer() = default;

    computer(
        string make,
        string series,
        string processor,
        string ram,
        string hd,
        string mon);

    friend std::ostream &operator<<(std::ostream &os, const computer &rhs);
    ~computer() = default;
    static int count;

private:
    string m_ram;
    string m_hdd;
    string m_mon;
    MSP *msp;
};



#endif // COMPUTER_HPP
