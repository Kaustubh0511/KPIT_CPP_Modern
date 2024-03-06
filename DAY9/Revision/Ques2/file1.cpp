#include <iostream>
#include <map>
using namespace std;
#define line(msg) "----------------------" #msg "--------------------\n"
class Broker
{
    string m_name;
    double m_charges;

public:
    Broker(string name, double charge) : m_name(name), m_charges(charge)
    {
    }

    double get_charges() const
    {
        return m_charges;
    }
    operator string()
    {
        return m_name;
    }
};

class BrokerRepository
{
    static map<string, Broker *> repo;

public:
    static void Register(Broker *broker)
    {
        repo[*broker] = broker;
    }
    static Broker *Retrive(string broker_name)
    {
        return repo[broker_name];
    }
    static bool isAvail(string b_name)
    {
        return repo.find(b_name) != repo.end();
    }
};
map<string, Broker *> BrokerRepository ::repo;

class Dummy
{
public:
    Dummy()
    {
        BrokerRepository::Register(new Broker("Bharat", 2000));
        BrokerRepository::Register(new Broker("TelMat", 4000));
        BrokerRepository::Register(new Broker("MarMat", 6000));
        BrokerRepository::Register(new Broker("ShaadiMat", 3000));
    }
} dummy;

class NoBrokerException : public exception
{
    string s;

public:
    NoBrokerException(string s) : s(s)
    {
    }
    string what() { return s; }
};
class Human
{
    int m_id{0};
    string m_name;
    Broker *broker;

public:
    Human(int id, string name, string b_name) : m_id(id), m_name(name)
    {
        if (BrokerRepository::isAvail(b_name))
        {
            broker = BrokerRepository::Retrive(b_name);
        }
        else
        {
            throw NoBrokerException("Broker does not exist");
        }
    }
    operator double()
    {
        return broker->get_charges();
    }
    string broker_name()
    {
        return *broker;
    }
    int get_id()
    {
        return m_id;
    }
    string get_name()
    {
        return m_name;
    }
};

class Transaction
{
    map<int, Human *> repo;

public:
    void Subscribe(int id, string name, string b_name)
    {
        try 
        {
            Human *human = new Human(id, name, b_name);
            repo[human->get_id()] = human;
        }
        catch (const exception &e)
        {
            cout << "Exception: " << e.what() << "\n";
        }
    }
    void unSubscribe(int id)
    {
        delete repo[id];
        repo.erase(id);
    }

    void listRepo()
    {
        for (auto rng : repo)
        {
            Human *human = rng.second;
            cout << human->get_id() << " " << human->get_name() << " " << human->broker_name() << "\n";
        }
    }
};

int main()
{
    Transaction trans;
    trans.Subscribe(101, "Kaustubh", "TelMat");
    trans.Subscribe(102, "Aman", "Bharat");
    trans.Subscribe(103, "Akshit", "ShaadiMat");
    trans.Subscribe(104, "Vardaan", "MarMat");

    trans.listRepo();
    line();
    trans.unSubscribe(102);
    line();
    // trans.listRepo("TelMat");
    return 0;
}