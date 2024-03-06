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

int main1()
{
    // this_thread::sleep_for(chrono::milliseconds(1));
    promise<int> prom;
    future<int> fut = prom.get_future();
    // cout << "\n";
    prom.set_value(190);
    int result = fut.get();
    cout << "Result : " << result << "\n";
    return 0;
}

void fun1(promise<int> *prm)
{
    for (int x = 1; x <= 10; x++)
    {
        string str = "\t\t\t\tfun x = " + to_string(x) + " Tid [" + get_tid(this_thread::get_id()) + "]\n";
        cout << str;
        this_thread::sleep_for(chrono::seconds(1));
        if (4 == x)
        {
            prm->set_value(9876);
        }
    }
}

void fun2(future<int> *fut)
{
    cout << "fun2 started\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "fun2 on \n";
    int res = fut->get();
    cout << "Result = " << res << "\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "fun2 done\n";
}

int main()
{
    promise<int> prom;
    future<int> fut = prom.get_future();
    thread t1(fun1, &prom);
    thread t2(fun2, &fut);

    t1.join();
    t2.join();

    return 0;
}