#include <iostream>
#include <functional>
#include <map>
#include <any>
using namespace std;
#define line(msg) cout << "___________________" #msg "____________________\n"
// ostream overload for vector, tuple ,list
// uml diagram for decorator
// 

class CareTaker
{
    map<void *, std::any> repo;

public:
    operator CareTaker *()
    {
        return this;
    }
    void Store(void *key, std::any value)
    {
        repo[key] = value; // repo[e1]=new add state
    }
    std::any Retrieve(void *key) // cp1=key
    {
        std::any value = repo[key];
        repo.erase(key);
        return value;
    }
};

class BaseMomento 
{
    CareTaker *caretaker{nullptr};

public:
    void SetCareTaker(CareTaker *caretaker) { this->caretaker = caretaker; }
    void hydetrate() 
    {
        std::any state = clone();
        caretaker->Store(this, state);
    }
    void dehydetrate() 
    {
        std::any recievedSatate = caretaker->Retrieve(this);
        recieveState(recievedSatate);
    }

protected:
    virtual std::any clone() = 0;
    virtual void recieveState(std::any) = 0;
};

class CProduct : public BaseMomento
{
public:
    int category;
    string name;
    double price;
    CProduct() = default;
    CProduct(int category, string name, double price) : category(category), name(name), price(price)
    {
    }
    void Display()
    {
        cout << category << "____________" << name << "_________" << price << '\n';
    }

protected:
    std::any clone() override
    {
        return new CProduct(category, name, price);
    }
    void recieveState(std::any recieveSatate) override
    {
        CProduct *cp = any_cast<CProduct *>(recieveSatate);
        if (nullptr != cp)
        {
            this->category = cp->category;
            this->name = cp->name;
            this->price = cp->price;
        }
    }
};

class CEmployee : public BaseMomento
{
public:
    int id;
    string ename;
    string dept;
    CEmployee() = default;
    CEmployee(int id, string ename, string dept) : id(id), ename(ename), dept(dept)
    {
    }
    void Display()
    {
        cout << id << "_________" << ename << "______________" << dept << '\n';
    }

protected:
    std::any clone() override
    {
        return new CEmployee(id, ename, dept);
    }
    void recieveState(std::any recieveSatate) override
    {
        CEmployee *ce = any_cast<CEmployee *>(recieveSatate);
        if (nullptr != ce)
        {
            this->id = ce->id;
            this->ename = ce->ename;
            this->dept = ce->dept;
        }
    }
};

int main()
{
    CareTaker c1, c2;
    CProduct cp1(101, "nail polish", 150);
    CProduct cp2(103, "nail polish", 200);
    CEmployee e1(101, "sachi", "batsman");
    line(BeforeCache);
    cp1.Display();
    e1.Display();

    line(Cache);
    cp1.SetCareTaker(c1); // product.setcaretaker par repo1
    e1.SetCareTaker(c1);  // employee.setcaretaker par repo2
    cp1.hydetrate();
    e1.hydetrate();

    line(AfterChange);
    cp1.name = "face polish";
    cp1.price = 301;
    e1.dept = "AllRounder";
    cp1.Display();
    e1.Display();
    line(RetriveCache);

    cp1.dehydetrate();
    e1.dehydetrate();
    cp1.Display();
    e1.Display();
    return 0;
}
