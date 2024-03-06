#include <iostream>
#include <map>
using namespace std;
#define line(msg) cout << "---------------" #msg "------------\n";

struct MSP
{
    string m_make;
    string m_series;
    string m_processor;

    MSP(string make, string series, string processor) : m_make(make), m_series(series), m_processor(processor)
    {
        count++;
    }
    static int count;
    static map<string, MSP *> repo;

    static MSP *make_msp(string make, string series, string processor)
    {
        string key = make + series + processor;
        if (repo.find(key) == repo.end())
        {
            repo[key] = new MSP(make, series, processor);
        }
        return repo[key];
    }

    static void release()
    {
        for (auto &rng : repo)
        {
            delete rng.second;
        }
        repo.clear;
    }
};

int MSP::count = 0;
map<string, MSP *> MSP::repo;

class Computer
{
    string m_ram;
    string m_hd;
    string m_mon;
    MSP *msp;

public:
    Computer(string make, string series, string processor, string ram, string hd, string mon) : m_ram(ram),m_hd(hd),m_mon(mon),msp()
    {
    }
};
int main()
{
    return 0;
}