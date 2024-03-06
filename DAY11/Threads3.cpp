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

class Func
{
public:
    Func()
    {
    }
    Func(int, int)
    {
    }
    void operator()()
    {
        for (int x = 1; x <= 7; x++)
        {
            string str = "Func::operator x = " + to_string(x) + " Tid = [" + get_tid(this_thread::get_id()) + "]\n";
            cout << str;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
    void operator()(int x, int y)
    {
        for (int x = 1; x <= 7; x++)
        {
            string str = "Func::operator x = " + to_string(x) + " Tid = [" + get_tid(this_thread::get_id()) + "]\n";
            cout << str;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};

int main()
{
    Func fnc;
    // std::thread t2(fnc);
    // std::thread t2(std::ref(fnc));
    // std::thread t2(fnc, 111, 222);
    // std::thread t2(std::ref(fnc), 111, 222);
    // std::thread t2(Func(11, 22), 111, 222);
    std::thread t2((Func()), 111, 222);
    for (int i = 1; i <= 4; i++)
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