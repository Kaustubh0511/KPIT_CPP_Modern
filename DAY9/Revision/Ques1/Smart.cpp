#include <iostream>
using namespace std;
template <typename T>

class smart
{
private:
    T *pt{nullptr};
    FPTR fp{nullptr};

public:
    using FPTR =void(T::*)();
    static void *operator new(size_t) = delete;
    static void *operator new[](size_t) = delete;
    void operator delete(void *) = delete;
    void operator delete[](void *) = delete;
    smart(T *pt = nullptr) : pt(pt)
    {
    }
    smart(const smart &par) : pt(par.pt)
    {
        smart &smRef = const_cast<smart &>(par);
        smRef.pt = NULL;
    }
    smart(smart &&par) noexcept : pt(par.pt)
    {
        cout << "Move\n";
        smart &smRef = const_cast<smart &>(par);
        smRef.pt = NULL;
    }
    T *operator->() const
    {
        return pt;
    }
    T &operator*()
    {
        return *pt;
    }
    smart &operator=(const smart &obj)
    {
        // Ownership transfer
        if (this == &obj)
        {
            return *this;
        }
        smart temp(obj);
        this->Swap(temp);
        return *this;
    }

    smart &operator=(smart &&obj)
    {
        // Ownership transfer
        if (this == &obj)
        {
            return *this;
        }
        smart temp(obj);
        this->Swap(temp);
        return *this;
    }
    smart &operator->*(FPTR fp)
    {
        this->fp=fp;
        return *this;
    }
    void operator() ()
    {
        (pt->*fp)();
    }
    void Swap(smart &tmp)
    {
        std::swap(this->pt, tmp.pt);
    }
    ~smart()
    {
        delete pt;
    }
};