#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

/* Question :
    We have to identify read write without touching the main function do only in the class.
    Important qeustion, similar questions can be expected in marathon.
*/

class CArray
{
    int size;
    int *arr;

public:
    CArray(int par) : size(par), arr(new int[size])
    {
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;
    }

    // Nested class is implicitly friend for the CArray class-----------------------------------
    class Helper
    {
        int index;
        // int *ptr; // only passing the array
        CArray *ptr;

    public:
        Helper(int i, CArray *p) : index(i), ptr(p) // ptr(p)
        {
        }
        operator int() // casting overloading
        {
            cout << "Reading\n";
            // return ptr[index];
            return ptr->arr[index];
        }
        Helper &operator=(int val) // operator = overloading
        {
            cout << "Writing\n";
            // ptr[index] = val;
            ptr->arr[index] = val;
            return *this;
        }

        Helper &operator=(Helper par)
        {
            cout << "Reading/Writing\n";
            // ptr[index] = par.ptr[par.index];
            ptr->arr[index] = par.ptr->arr[par.index];
            return *this;
        }

        // Nested Helper class started -------------------------
        class NestedHelper
        {
            int index;
            Helper *h;

        public:
            NestedHelper(int n, Helper *H) : index(n), h(H)
            {
            }
            operator int() // casting overloading
            {
                cout << "Reading\n";
                // return ptr[index];
                return h->ptr->arr[index];
            }
            Helper &operator=(int val) // operator = overloading
            {
                cout << "Writing\n";
                // ptr[index] = val;
                h->ptr->arr[index] = val;
                return *this;
            }

            Helper &operator=(Helper par)
            {
                cout << "Reading/Writing\n";
                // ptr[index] = par.ptr[par.index];
                // h->arr[index] = par.ptr->arr[par.index];
                h->ptr->arr[index] = par.ptr->arr[index];
                return *this;
            }
        };
        // Nested Helper class over ----------------------------
        NestedHelper operator[](int index)
        {
            return NestedHelper(index, this);
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
        delete[] arr;
    }
};

ostream &operator<<(ostream &os, const CArray &par)
{
    for (int i = 0; i < par.size; i++)
    {
        os << "arr [" << i << "] = " << par.arr[i] << "\n";
    }
    return os;
}
// Main function to test the code
int main()
{
    CArray obArr(5);
    int k = obArr[1];    // read
    obArr[0] = 999;      // write
    obArr[1] = obArr[0]; // read and write
    cout << obArr << "k = " << k << "\n";
    return 0;
}
