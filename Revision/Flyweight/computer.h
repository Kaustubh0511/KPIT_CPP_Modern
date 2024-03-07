#ifndef COMPUTER_H
#define COMPUTER_H

#include "MSP.h"
#include<string>
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
    MSP* msp;


};

int computer::count=0;


#endif // COMPUTER_H
