#ifndef MSP_H
#define MSP_H

#include <string>
#include <map>
using std::string;


struct MSP
{
    string m_make;
    string m_series;
    string m_processor;
    static int count;
    static std::map<string, MSP *> repo;

    MSP(
        string make,
        string series,
        string processor);

    static MSP *make_msp(string make, 
                         string series, 
                         string processor) ;

    static void release();
};
int MSP::count=0;
std::map<string,MSP*> MSP::repo;

#endif // MSP_H
