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
void fun()
{
    for (int x = 1; x <= 10; x++)
    {
        string str = "fun x = " + to_string(x) + " Tid = [" + get_tid(this_thread::get_id()) + "]\n";
        cout << str;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main1()
{
std:
    thread t1(&fun);
    for (int i = 1; i <= 5; i++)
    {
        string str = "\t\t\tMain x = " + to_string(i) + " Tid = [" + get_tid(this_thread::get_id()) + "]\n";
        cout << str;
        this_thread::sleep_for(chrono::seconds(1));
    }
    t1.join();
    return 0;
}

void MyFun(int x1, int y)
{
    for (int x = 1; x <= 10; x++)
    {
        string str = "myfun x = " + to_string(x1) + " Tid = [" + get_tid(this_thread::get_id()) + "] x1 = " + to_string(x1) + " y1 = " + to_string(y) + "\n";
        cout << str;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main()
{
std:
    thread t1(std::bind(&MyFun, 10, 20)); // start a seperate context in which function executes
    thread t2(&MyFun, 10, 20);            // when constraints were a bit relaxed.
    for (int i = 1; i <= 5; i++)
    {
        string str = "\t\t\tMain x = " + to_string(i) + " Tid = [" + get_tid(this_thread::get_id()) + "]\n";
        cout << str;
        this_thread::sleep_for(chrono::seconds(1));
    }
    t1.join();
    t2.join();
    return 0;
}