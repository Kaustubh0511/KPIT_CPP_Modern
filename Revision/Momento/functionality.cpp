#include "functionality.h"

void CreatObjectPoduct(std::vector<CProduct *> &data)
{
    data.push_back(new CProduct(101, "Nail Polish", 150));
}

void TestProduct(std::vector<CProduct *> &data, CareTaker &r)
{
    for (auto ele : data)
    {
        ele->Display();
        ele->SetCareTaker(r);
        ele->Hyderate();
        ele->setName("face polish");
        ele->setPrice(301);
        ele->Display();
        ele->Dehyderate();
        ele->Display();
    }
}

void DeleteObj(std::vector<CProduct *> &data)
{
    for (auto ele : data)
    {
        delete (ele);
    }
}
