#ifndef CCOMPLEX_HPP
#define CCOMPLEX_HPP

#include <iostream>
#include <tuple>
using namespace std;
class CComplex
{

public:
    int real;
    int imag;
    CComplex() {}
    CComplex(int r, int i) : real(r), imag(i) {}
    CComplex operator+(const CComplex &cc)
    {
        CComplex temp;
        temp.real = this->real + cc.real;
        temp.imag = this->imag + cc.imag;
        return temp;
    }
    CComplex operator+(int &&i) const
    {
        CComplex temp;
        temp.real = this->real + i;
        temp.imag = this->imag + i;
        return temp;
    }
    operator double()
    {
        return real + imag;
    }
    friend ostream &operator<<(ostream &os, const CComplex &c)
    {
        os << "Real : " << c.real << " Imaginary :  " << c.imag << ""
           << "\n";
        return os;
    }
    friend CComplex operator+(int &&i, const CComplex &j);
    operator tuple<double, double>()
    {
        return {real, imag};
    }
};

CComplex operator+(int &&i, const CComplex &j)
{
    CComplex temp((i + j.real), (i + j.imag));
    return temp;
}

#endif // CCOMPLEX_HPP
