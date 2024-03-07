#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H

#include <iostream>
#include "BaseMomento.h"
using std::string;

class CEmployee:public BaseMomento
{

public:
    CEmployee() = default;
    CEmployee(const CEmployee &) = delete;
    CEmployee(CEmployee &&) = delete;
    CEmployee &operator=(const CEmployee &) = delete;
    CEmployee &operator=(const CEmployee &&) = delete;
    ~CEmployee() = default;

    CEmployee(int _id, string _ename, string _dept);
    void Display() const;

    int id() const;
    void setId(int id);
    string ename() const;
    void setEname(const string &ename);
    string dept() const;
    void setDept(const string &dept);

protected:
    IMomento* clone() override;
    void ReciveState(IMomento* _recieveState) override;

private:
    int _id{0};
    string _ename{nullptr};
    string _dept{nullptr};
};

#endif // CEMPLOYEE_H
