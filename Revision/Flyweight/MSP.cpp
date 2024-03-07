#include "MSP.hpp"
int MSP::count = 0;
std::map<string, MSP *> MSP::repo;
MSP::MSP(
    string make,
    string series,
    string processor) : m_make(make),
                        m_series(series),
                        m_processor(processor) { count++; }

MSP *MSP::make_msp(string make,
                   string series,
                   string processor)
{

    string key = make + series + processor;
    if (repo.find(key) == repo.end())
    {
        repo[key] = new MSP(make, series, processor);
    }
    return repo[key];
}

void MSP::release()
{
    for (auto &ele : repo)
    {
        delete ele.second;
    }
    repo.clear();
}