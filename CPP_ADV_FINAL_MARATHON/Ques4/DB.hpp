#ifndef DB_HPP
#define DB_HPP
#include <iostream>
#include <string>
using namespace std;
#define line(msg) cout << "---------------" #msg "------------\n";

class DB
{
public:
    virtual void OpenDB() = 0;
    virtual void CloseDB() = 0;
    operator DB *()
    {
        return this;
    }
};

#endif // DB_HPP
