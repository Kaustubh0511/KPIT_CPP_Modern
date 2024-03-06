#include <iostream>
#include <tuple>
#include <string>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

class CComplex
{
    int real{0};
    int imaginary{0};

public:
    CComplex() {}
    CComplex(int r, int i) : real(r), imaginary(i) {}
    CComplex operator+(const CComplex &cc)
    {
        CComplex temp;
        temp.real = this->real + cc.real;
        temp.imaginary = this->imaginary + cc.imaginary;
        return temp;
    }
    CComplex operator+(int &&i) const
    {
        CComplex temp;
        temp.real = this->real + i;
        temp.imaginary = this->imaginary + i;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CComplex &c)
    {
        os << "(" << c.real << ", " << c.imaginary << ")"
           << "\n";
        return os;
    }
    friend CComplex operator+(int &&i, const CComplex &j);
};

CComplex operator+(int &&i, const CComplex &j)
{
    CComplex temp((i + j.real), (i + j.imaginary));
    return temp;
}

template <typename... T>
int sum1(T... ts)
{
    return (ts + ...);
}
void ShowAll()
{
}
template <typename... T1>
void ShowAll(T1... t1)
{
    ((cout << t1 << "\t"), ... );
    cout << "\n";
}
int main()
{
    auto res = sum1(10, 20, 30, 40, 50, 60);
    cout << res << "\n";
    ShowAll(1.2, "sachin", 3.14f, 'c', 1, 2, 3);

    CComplex c1(10, 20);
    CComplex c2(30, 40);

    CComplex c3 = c1 + c2;
    CComplex c4 = c1 + 10;
    CComplex c5 = 10 + c1;

    cout << c1 << c2 << c3 << c4 << c5;
    return 0;
}
