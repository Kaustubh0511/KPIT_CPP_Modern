#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

class CA
{
public:
    CA()
    {
        cout << "CA Constructor\n";
    }
    void fun()
    {
        cout << "CA fun\n";
    }
    ~CA()
    {
        cout << "CA Destructor\n";
    }
};
void DoBuisness(CA *caPtr)
{
    cout << "Business started\n";
    caPtr->fun();
    cout << "Business ended\n";
}

class Smart_Ptr
{
    static void *operator new(size_t) = delete;   // To avoid creating the pointer of smart pointer because
    static void *operator new[](size_t) = delete; // then we will have to mange that also and not add in the heap.
    static void operator delete(void *) = delete; // Same for the delete operator also.
    static void operator delete[](void *) = delete;
    CA *ptr; // hold the address of CA
public:
    Smart_Ptr(CA *pt = NULL) : ptr(pt) // Constructor to assign the value to CA.
    {
    }
    Smart_Ptr(const Smart_Ptr &par) : ptr(par.ptr)
    {
        Smart_Ptr &smpRef = const_cast<Smart_Ptr &>(par);
        smpRef.ptr = NULL;
        cout << "Smart_Ptr shallow copy.\n";
    }
    Smart_Ptr &operator=(const Smart_Ptr &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        cout << "Shallow Assignment\n";
        Smart_Ptr temp(rhs);
        this->Swap(temp);
        return *this;
    }
    void Swap(Smart_Ptr &tmp)
    {
        std::swap(this->ptr, tmp.ptr);
    }
    CA *operator->() // This is overloaded becuase we have to use the function class CA.
    {
        return ptr;
    }
    // CA &operator*() // This is overloaded because we have to derefernece the pointer for class CA
    // {
    //     cout<<"* operator\n";
    //     return *ptr;
    // }
    operator CA *()
    {
        cout<<"CA* casting operator\n";
        return ptr;
    }
    ~Smart_Ptr() // destructor to manage memory leak for class CA pointer.
    {
        delete ptr;
    }
};

void MyBusiness(Smart_Ptr smpt)
{
    cout << "Apple\n";
    smpt->fun();
    cout << "Oranges\n";
}

void MyBusiness1(Smart_Ptr& smpt)
{
    cout << "Apple1\n";
    (*smpt).fun();
    cout << "Oranges1\n";
}

int main()
{
    Smart_Ptr sm1 = new CA(); // conversion constructor. // TO mange the memory and to use class CA's pointer we use a smart pointer.
    Smart_Ptr sm1_1 = new CA();
    // sm1->fun();
    //(*sm1).fun(); // The dot operator  cannot be overloaded.
    line(CA*);
    DoBuisness(sm1);
    line();
    MyBusiness(sm1); // Here a shallow copy is made using copy constructor where we are doing ownership transfer in the copy constructor.
    line();
    Smart_Ptr sm2;
    sm2 = sm1_1; // Here we are using copy and swap method and overload the assignment operator.
    line(operator*);
    MyBusiness1(sm2);
    line();
    return 0;
}