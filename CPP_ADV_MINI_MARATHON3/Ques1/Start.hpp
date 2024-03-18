#ifndef START_HPP
#define START_HPP

#include "CArray.hpp"
void Start(CArray &arr)
{
    int x = arr[1][2];     // is read operatrion so print reading
    arr[0][1] = 78;        // is write operation so print writing
    arr[1][1] = arr[0][1]; // is read/write operation so print read/write

    cout << arr << "x = " << x << "\n";
}

#endif // START_HPP
