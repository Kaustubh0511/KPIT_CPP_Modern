#include <iostream>
#include <memory>
using namespace std;
#define line(msg) cout << "--------------" #msg "------------\n"

// Overloading two operators ->* and also overloading () operator.
class CA
{
    int x;

public:
    CA(int x) : x(x)
    {
    }

    void f1()
    {
        cout << "Apple x : " << x << "\n";
    }
    void f2()
    {
        cout << "Orange x : " << x << "\n";
    }
};

using FPTR = void (CA::*)();

class Smart
{
    CA *pt{nullptr};
    FPTR fp{nullptr};

public:
    Smart(CA *pt = NULL) : pt(pt)
    {
    }
    CA &operator*() const
    {
        return *pt;
    }
    CA *operator->() const
    {
        return pt;
    }
    Smart &operator->*(FPTR fpt)
    {
        this->fp = fpt;
        return *this;
    }

    void operator()()
    {
        (pt->*fp)();
    }
    ~Smart()
    {
        delete pt;
    }
};

void Buisness(FPTR fp, CA *smt)
{
    cout << "Start\n";
    (smt->*fp)();
    cout << "End\n";
}

void Buisness1(FPTR fp, Smart &smt)
{
    cout << "Start\n";
    /* Working
    Smart& temp = smt->*fp; Furthur working of this ******** Smart& tmp = obj.operator->*(fp), which then calls tmp.operator() ********
    temp();
    */
    (smt->*fp)();
    cout << "End\n";
}

int main1()
{
    CA *ptr1 = new CA(10);
    CA *ptr2 = new CA(10);
    FPTR fp1 = &CA::f1;
    FPTR fp2 = &CA::f2;
    Buisness(fp1, ptr1);
    Buisness(fp1, ptr1);
    return 0;
}

int main()
{
    Smart ptr1 = new CA(10);
    // Smart ptr2 = new CA(100);
    FPTR fp1 = &CA::f1;
    // FPTR fp2 = &CA::f2;
    Buisness1(fp1, ptr1);
    // Buisness1(fp2, ptr2);
}