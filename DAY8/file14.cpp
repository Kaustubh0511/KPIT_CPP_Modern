#include <iostream>
#include <map>
using namespace std;
#define line(msg) cout << "-----------------" #msg "---------------\n";

class Employee
{
public:
    virtual void DoJob() = 0;
};
class Developer : public Employee
{
public:
    Developer()
    {
        cout << "Developer\n";
    }
    void DoJob() override
    {
        cout << "Developer : DoJob\v";
    }
};

class Manager : public Employee
{
public:
    Manager()
    {
        cout << "Manager\n";
    }
    void DoJob() override
    {
        cout << "Manager : DoJob\v";
    }
};

class Tester : public Employee
{
public:
    Tester()
    {
        cout << "Tester\n";
    }
    void DoJob() override
    {
        cout << "Tester : DoJob\n";
    }
};
using FPTR = Employee *(*)();
class Repository
{
    static map<int, FPTR> repo;

public:
    static void Register(int key, FPTR fp)
    {
        repo[key] = fp;
    }
    static Employee *GetEmp(int key)
    {
        // return repo[key]();
        FPTR fp = repo[key];
        Employee *ep = fp();
        return ep;
    }
};

map<int, FPTR> Repository::repo;

class Dummy
{
public:
    Dummy()
    {
        Repository::Register(10, []() -> Employee *
                             { return new Developer(); });
        Repository::Register(20, []() -> Employee *
                             { return new Manager(); });
        Repository::Register(30, []() -> Employee *
                             { return new Tester(); });
    }
} dummy;

Employee *Factory(int par)
{
    return Repository::GetEmp(par);
}

int main()
{
    Employee *ep = Factory(30);
    ep->DoJob();
    return 0;
}
