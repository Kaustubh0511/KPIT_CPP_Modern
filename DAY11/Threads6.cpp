#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <functional>
// #include <mutex>
#include <sstream>
#include <future>
using namespace std;
#define line(msg) cout << "--------------" #msg "------------\n";

string get_tid(std::thread::id id)
{
    stringstream sst;
    sst << id;
    return sst.str();
}

void fun11(promise<int> &&prm)
{
    for (int x = 1; x <= 10; x++)
    {
        string str = "\t\t\t\tfun x = " + to_string(x) + " Tid [" + get_tid(this_thread::get_id()) + "]\n";
        cout << str;
        this_thread::sleep_for(chrono::seconds(1));
        if (4 == x)
        {
            prm.set_value(9876);
        }
    }
}

void fun22(future<int> &&fut)
{
    cout << "fun2 started\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "fun2 on \n";
    int res = fut.get();
    cout << "Result = " << res << "\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "fun2 done\n";
}

int main()
{
    promise<int> prom;
    future<int> fut = prom.get_future();
    thread t1(fun11, std::move(&prom));
    thread t2(fun22, std::move(&fut));

    t1.join();
    t2.join();

    return 0;
}