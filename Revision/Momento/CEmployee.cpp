#include "CEmployee.h"

CEmployee::CEmployee(int _id, string _ename, string _dept) : _id(_id), _ename(_ename), _dept(_dept) {}

void CEmployee::Display() const
{
    std::cout << _id << "__________" << _ename << "__________" << _dept << "\n";
}

int CEmployee::id() const { return _id; }
void CEmployee::setId(int id) { _id = id; }

string CEmployee::ename() const { return _ename; }
void CEmployee::setEname(const string &ename) { _ename = ename; }

string CEmployee::dept() const { return _dept; }
void CEmployee::setDept(const string &dept) { _dept = dept; }

IMomento *CEmployee::clone()
{
    return new CEmployee(_id, _ename, _dept);
}

void CEmployee::ReciveState(IMomento *_recieveState)
{
    CEmployee *ce = dynamic_cast<CEmployee *>(_recieveState);
    if (nullptr != ce)
    {
        this->_id = ce->_id;
        this->_ename = ce->_ename;
        this->_dept = ce->_dept;
    }
}
