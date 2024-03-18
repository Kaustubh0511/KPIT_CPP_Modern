#ifndef MONGO_HPP
#define MONGO_HPP

#include "DB.hpp"
class Mongo : public DB
{
public:
    void OpenDB() override
    {
        cout << "Open Mongo DB\n";
    }
    void CloseDB() override
    {
        cout << "Close Mongo DB\n";
    }
};
#endif // MONGO_HPP
