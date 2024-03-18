#ifndef SQL_HPP
#define SQL_HPP

#include "DB.hpp"
class SQL : public DB
{
public:
    void OpenDB() override;
    void CloseDB() override;
};

#endif // SQL_HPP
