#include "CArray.h"

CArray::Helper::InnerHelper::operator int()
{
    cout << "Reading\n";
    return hlp->ptr->arr[hlp->index1][index2];
}

CArray::Helper::InnerHelper &CArray::Helper::InnerHelper::operator=(int val)
{
    cout << "Writing\n";
    hlp->ptr->arr[hlp->index1][index2] = val;
    return *this;
}

CArray::Helper::InnerHelper &CArray::Helper::InnerHelper::operator=(const InnerHelper &par)
{
    cout << "Reading/Writing\n";
    hlp->ptr->arr[hlp->index1][index2] = par.hlp->ptr->arr[par.hlp->index1][par.index2];
    return *this;
}

ostream &operator<<(ostream &os, const CArray &par)
{
    for (int i = 0; i < par.row; i++)
    {
        for (int j = 0; j < par.col; j++)
        {
            os << par.arr[i][j] << "\n";
        }
    }
    return os;
}