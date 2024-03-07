#include "functionality.h"
int main()
{
    CareTaker r;
    std::vector<CProduct*> data;
    CreatObjectPoduct(data);
    TestProduct(data,r);
    DeleteObj(data);
    return 0;
}