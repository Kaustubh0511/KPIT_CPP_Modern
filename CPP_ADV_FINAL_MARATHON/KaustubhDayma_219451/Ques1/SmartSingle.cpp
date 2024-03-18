#include "SmartSingle.hpp"

GatewaySecurity *GatewaySecurity::head = nullptr;
GatewaySecurity *GatewaySecurity::Register()
{
    if (head == nullptr)
    {
        head = new GatewaySecurity();
    }
    return head;
}
void GatewaySecurity::Release()
{
    delete head;
    head = nullptr;
}
int SmartSingle::count = 0;
SmartSingle::SmartSingle()
{
    try
    {
        gws = GatewaySecurity::Register();
        if (nullptr == gws)
        {
            throw CustomException("Null pointer");
        }
        else
        {
            count++;
        }
    }
    catch (CustomException ce)
    {
        cout << ce.what() << "\n";
    }
}

GatewaySecurity *SmartSingle::operator->()
{
    if (gws == nullptr)
    {
        throw CustomException("Could Not overload");
    }
    return gws;
}

int SmartSingle::use_count()
{
    return count;
}

GatewaySecurity &SmartSingle::operator*()
{
    return *gws;
}

SmartSingle &SmartSingle::operator->*(FPTR fp)
{
    this->fp = fp;
    return *this;
}

SmartSingle::~SmartSingle()
{
    count--;
    if (0 == count)
    {
        GatewaySecurity::Release();
    }
}
