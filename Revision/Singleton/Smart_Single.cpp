#include "Smart_Single.h"

Single *Single::head = nullptr;

Single *Single::make_single()
{
    if (head == nullptr)
    {
        head = new Single();
    }
    return head;
    // return nullptr;
}
void Single::release()
{
    delete head;
    head = nullptr;
}
int Smart_Single::count = 0;

Smart_Single::Smart_Single()
{
    try
    {
        s = Single::make_single();
        if (nullptr == s)
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

Single *Smart_Single::operator->()
{
    if (s == nullptr)
    {
        throw CustomException("Could Not overload because of null pointer");
    }
    return s;
}
Single &Smart_Single::operator*()
{
    return *s;
}
int Smart_Single::use_count()
{
    return count;
}
Smart_Single::~Smart_Single()
{
    count--;
    if (0 == count)
    {
        Single::release();
    }
}