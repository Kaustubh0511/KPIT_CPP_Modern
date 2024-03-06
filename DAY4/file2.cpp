#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

class CA
{
    bool isOnHeap;
    static bool globalHeap; // made this to switch the value of isOnHeap
    static int size;        // made this to count the number of objects created on heap using [] operator

public:
    CA() : isOnHeap(globalHeap)
    {
        if (size <= 0) // wriiten this to print "on heap" for array of objects.
        {
            cout << "Constructor\n";
            globalHeap = false;
        }
        size--;
    }
    static void *operator new(size_t size)
    {
        cout << "Operator new\n";
        globalHeap = true; // Whenever an heap memory is made this new method is called and the value of static function changes to true
        return malloc(size);
    }
    static void *operator new[](size_t size)
    {
        cout << "Operator new[]\n";
        // cout << size << "\n";
        size = size / sizeof(CA); // getting the size of the array of objects.
        globalHeap = true;        // Whenever an heap memory is made this new method is called and the value of static function changes to true
        return malloc(size);
    }
    static void operator delete(void *pt)
    {
        cout << "Operator delete\n";
        free(pt);
    }
    static void operator delete[](void *pt)
    {
        cout << "Operator delete[]\n";
        free(pt);
    }
    void Location()
    {
        if (true == isOnHeap)
        {
            cout << "I am on heap\n";
        }
        else if (false == isOnHeap)
        {
            cout << "I am (not on) heap\n";
        }
    }
    ~CA()
    {
        cout << "Destructor\n";
    }
};

bool CA::globalHeap = false; // initializing the static variable.
int CA::size = 0;
int main()
{
    CA obj1;
    line();
    CA *obj2 = new CA();
    line();
    CA obj3;
    line();
    CA *obj4 = new CA();
    line();
    CA *obj5 = new CA[5];
    line(NotOnHeap);
    obj1.Location();
    obj3.Location();
    line(On_Heap);
    obj2->Location();
    obj4->Location();
    line(On_Heap_for_array_object);
    for (size_t i = 0; i < 5; i++)
    {
        (obj5 + i)->Location();
    }
    // cout<<sizeof(obj5)<<"\n";
    return 0;
}