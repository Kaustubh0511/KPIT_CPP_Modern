#ifndef CARRAY_H
#define CARRAY_H

#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

class CArray
{
    int row{2};
    int col{3};
    int arr[2][3] = {{10, 20, 30}, {40, 50, 60}};

public:
    CArray()
    {
    }

    // Nested class is implicitly friend for the CArray class-----------------------------------
    class Helper
    {
        int index1;
        CArray *ptr;

    public:
        Helper(int i, CArray *p) : index1(i), ptr(p)
        {
        }

        //---------------------------------------
        class InnerHelper
        {
            Helper *hlp;
            int index2;

        public:
            InnerHelper(int index2, Helper *hlp) : index2(index2), hlp(hlp)
            {
            }
            operator int(); // casting overloading

            InnerHelper &operator=(int val); // operator = overloading

            InnerHelper &operator=(const InnerHelper &par);
        };

        //---------------------------------------
        InnerHelper operator[](int index)
        {
            return InnerHelper(index, this);
        }
    };
    // Nested class is over -----------------------------------

    Helper operator[](int index)
    {
        return Helper(index, this);
    }

    friend ostream &operator<<(ostream &os, const CArray &par);
    ~CArray()
    {
    }
};

#endif // CARRAY_H
