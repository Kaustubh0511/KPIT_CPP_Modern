#include <iostream>
#include <memory>
using namespace std;
#define line(msg) cout << "________________" #msg "______________________\n"

class CA
{
public:
    CA()
    {
        cout << "Default \n";
    }
    CA(const CA &par)
    {
        cout << "Copy\n";
    }
    CA(CA &&par) noexcept
    {
        cout << "Move\n";
    }
    ~CA() noexcept
    {
        cout << "D-tor\n";
    }
};
class CB
{
public:
    CB()
    {
        cout << "CB Ctor\n";
    }
    CB(int)
    {
        cout << "CB(int)\n";
    }
    CB(int, int)
    {
        cout << "CB(int,int)\n";
    }
    void fun()
    {
    }
    CB(CA par)
    {
        cout << "CB(CA)\n";
    }
    ~CB()
    {
        cout << "CB D-tor\n";
    }
};

template <typename T>
class Smart
{
    T *pt;
    int *count;

public:
    explicit Smart(T *pt = NULL) : pt(pt), count(new int(1))
    {
    }

    Smart(Smart &&par) noexcept : pt(par.pt), count(par.count)
    {
        ++(*count);
        par.pt = NULL;
    }

    Smart(const Smart &par) : pt(par.pt), count(par.count)
    {
        ++(*count);
    }
    Smart &operator=(const Smart &par)
    {
        if (this == &par)
            return *this;
        Smart temp(par);
        this->Swap(temp);
        return *this;
    }
    void Swap(Smart &temp)
    {
        swap(this->pt, temp.pt);
        swap(this->count, temp.count);
    }
    T &operator*() const
    {
        return *pt;
    }
    T *operator->() const
    {
        return pt;
    }
    int use_count() const
    {
        return *count;
    }
    operator bool() const
    {
        return pt != NULL;
    }

    ~Smart() noexcept
    {
        --(*count);
        if ((*count) == 0)
        {
            delete pt;
            delete count;
        }
    }
};

template <typename T, typename... PCK>
Smart<T> make_smart(PCK &&...pck)
{
    return Smart<T>(new T(std::forward<PCK>(pck)...));
}

// template<typename T, typename... PCK>
// Smart<T> make_smart1(PCK&&... pck)
//{
//   T* tmp = new T(std::forward<PCK>(pck)...);
//   return Smart<T>(tmp);
//   //return Smart<T>(new T(std::forward<PCK>(pck)...));
// }

void My_Smart()
{
    line();
    Smart<CB> smt1 = make_smart<CB>();
    line();
    Smart<CB> smt2;
    line();

    Smart<CB> smt3 = smt2;
    line();
    smt3 = smt1;
    cout<<smt1.use_count()<<"\n";
    cout<<smt2.use_count()<<"\n";
    cout<<smt3.use_count()<<"\n";

    line();
}

int main()
{
    My_Smart();

    return 0;
}