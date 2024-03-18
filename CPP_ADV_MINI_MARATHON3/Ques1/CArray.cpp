#include "CArray.hpp"

CArray::Helper::InnerHelper::operator int()
{
    cout << "reading\n";
    return hlp->pt->arr[hlp->index1][index2];
}

CArray::Helper::InnerHelper CArray::Helper::InnerHelper::operator=(int val)
{
    cout << "writing\n";
    hlp->pt->arr[hlp->index1][index2] = val;
    return *this;
}

CArray::Helper::InnerHelper &CArray::Helper::InnerHelper::operator=(const InnerHelper &par)
{
    cout << "read/write\n";
    hlp->pt->arr[hlp->index1][index2] = par.hlp->pt->arr[par.hlp->index1][par.index2];
    return *this;
}

ostream &operator<<(ostream &os, CArray &par)
{
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            os << par.arr[i][j] << "\t";
        }
        cout << "\n";
    }
    return os;
}