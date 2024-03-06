#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <functional>
#include <mutex>
#include <sstream>
using namespace std;
#define line(msg) cout << "--------------" #msg "------------\n";

string get_tid(std::thread::id id)
{
    stringstream sst;
    sst << id;
    return sst.str();
}

class CA
{
public:
    
    void fun1()
    {
        for (int x = 1; x <= 10; x++)
        {
            string str = "CA::fun1 x = " + to_string(x) + " Tid = [" + get_tid(this_thread::get_id()) + "]\n";
            cout << str;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
    void fun2(int x1, int y1)
    {
        for (int x = 1; x <= 10; x++)
        {
            string str = "CA::fun2 x = " + to_string(x1) + " Tid = [" + get_tid(this_thread::get_id()) + "] x1 = " + to_string(x1) + " y1 = " + to_string(y1) + "\n";
            cout << str;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};

int main()
{
    CA obj;
    // std::thread t1(&CA::fun1, obj);
    // std::thread t2(&CA::fun1, std::ref(obj));
    // std::thread t2(&CA::fun2, obj, 10, 20);
    std::thread t2(&CA::fun2, std::ref(obj), 10, 20);
    for (int i = 1; i <= 5; i++)
    {
        string str = "\t\t\tMain x = " + to_string(i) + " Tid = [" + get_tid(this_thread::get_id()) + "]\n";
        cout << str;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "Main Waiting\n";
    t2.join();
    cout << "Main done\n";
    return 0;
}