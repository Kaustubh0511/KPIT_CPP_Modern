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
            CArray *pt;
            int index2;
            int index1;

        public:
            InnerHelper(int index2, CArray *pt, int index1) : index2(index2), pt(pt), index1(index1)
            {
            }
            operator int() // casting overloading
            {
                cout << "Reading\n";
                return pt->arr[index1][index2];
            }
            InnerHelper &operator=(int val) // operator = overloading
            {
                cout << "Writing\n";
                pt->arr[index1][index2] = val;
                return *this;
            }

            InnerHelper &operator=(InnerHelper par)
            {
                cout << "Reading/Writing\n";
                pt->arr[index1][index2] = par.pt->arr[par.index1][par.index2];
                return *this;
            }
        };

        //---------------------------------------
        InnerHelper operator[](int index)
        {
            return InnerHelper(index, ptr, index1);
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
// Main function to test the code
int main()
{
    CArray obArr;
    int k = obArr[0][1];       // read
    obArr[0][1] = 999;         // write
    obArr[1][1] = obArr[0][1]; // read and write
    cout << "k = " << k << "\n";
    cout << obArr << "\n";
    return 0;
}
