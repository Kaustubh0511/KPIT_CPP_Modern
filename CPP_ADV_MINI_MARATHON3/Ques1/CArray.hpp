#ifndef CARRAY_HPP
#define CARRAY_HPP

#include <iostream>
using namespace std;
#define line(msg) cout << "-----------" #msg "------------\n";
class CArray
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

public:
    class Helper
    {
        int index1;
        CArray *pt;

    public:
        Helper(int idx, CArray *pt) : index1(idx), pt(pt)
        {
        }
        class InnerHelper
        {
            int index2;
            Helper *hlp;

        public:
            InnerHelper(int idx, Helper *hp) : index2(idx), hlp(hp)
            {
            }
            operator int();
            InnerHelper operator=(int val);
            InnerHelper &operator=(const InnerHelper &par);
        };
        InnerHelper operator[](int index) { return InnerHelper(index, this); }
    };
    Helper operator[](int index) { return Helper(index, this); }
    friend ostream &operator<<(ostream &os, CArray &par);
};

#endif // CARRAY_HPP
