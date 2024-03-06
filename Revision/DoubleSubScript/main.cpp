#include"CArray.h"

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