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
    ~CB() noexcept
    {
        cout << "CB D-tor\n";
    }
};
template <typename T>
struct Handle
{
    T *pt;
    int count;
    Handle(T *pt) : pt(pt), count(1)
    {
    }

    ~Handle()
    {
        delete pt;
    }
};

template <typename T>
class Smart
{
    Handle<T> *handle{nullptr};

public:
    explicit Smart(T *pt = nullptr)
    {
        if (pt != nullptr)
        {
            handle = new Handle<T>(pt);
        }
    }

    Smart(Smart &&par) noexcept : handle(par.handle)
    {
        par.handle = nullptr;
    }

    Smart(const Smart &par) : handle(par.handle)
    {
        if (handle != nullptr)
        {
            handle->count++;
        }
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
        std::swap(handle, temp.handle);
    }
    T &operator*() const
    {
        return *(handle->pt);
    }
    T *operator->() const
    {
        return handle->pt;
    }
    int use_count() const
    {
        return (handle == nullptr) ? 0 : handle->count;
    }
    operator bool() const
    {
        return handle->pt != NULL;
    }

    ~Smart() noexcept
    {
        if (handle != nullptr && (--handle->count) == 0)
        {
            delete handle;
        }
    }
};

template <typename T, typename... PCK>
Smart<T> make_smart(PCK &&...pck)
{
    return Smart<T>(new T(std::forward<PCK>(pck)...));
}

void My_Smart()
{
    line();
    Smart<CB> smt1 = make_smart<CB>();
    line();
    Smart<CB> smt2;
    line();
    Smart<CB> smt3;
    line();
    Smart<CB> smt4 = smt1;
    line();
    smt3 = smt1;
    cout << smt1.use_count() << "\n";
    cout << smt2.use_count() << "\n";
    cout << smt3.use_count() << "\n";

    line();
}

int main()
{
    My_Smart();
    return 0;
}