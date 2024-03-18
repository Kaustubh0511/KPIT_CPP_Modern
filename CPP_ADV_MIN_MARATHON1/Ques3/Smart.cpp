
#include <iostream>
using namespace std;

template <typename T>
class Smart
{
public:
    // Heap construction prohibited.
    static void *operator new(size_t) = delete;
    static void *operator new[](size_t) = delete;
    void operator delete(void *) = delete;
    void operator delete[](void *) = delete;
    using FPTR = void (T::*)();
    Smart(T *pt = nullptr) : pt(pt)
    {
    }
    // Ownership transfer capabilities.
    Smart(const Smart &obj)
    {
    }
    Smart(Smart &&par) noexcept : pt(par.pt) // Move Constructor.
    {
        par.pt = nullptr;
    }
    Smart &operator=(const Smart &par) // Overloaded Assgniment operator with copy and swap functionality.
    {
        Smart temp(par);
        this->Swap(temp);
        return *this;
    }
    operator bool()
    {
        return pt != nullptr;
    }
    T *operator->()
    {
        return pt;
    }
    T &operator*()
    {
        return *pt;
    }
    Smart &operator->*(FPTR fp)
    {
        this->fp = fp;
        return *this;
    }
    void operator()()
    {
        (pt->*fp)();
    }
    void Swap(Smart &tmp)
    {
        std::swap(this->pt, tmp.pt);
    }
    ~Smart() noexcept
    {
        delete pt;
    }

private:
    T *pt{nullptr};
    FPTR fp{nullptr};
};

