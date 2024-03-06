#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <functional>
#include <mutex>
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

int AddFun(int x, int y)
{
    cout << "\t\tAddFun started x = " + to_string(x) + " , y = " + to_string(y) + "\n";
    for (size_t i = 0; i < 10; i++)
    {
        string st = "\t\tAddfun started i = " + to_string(i) + "\n";
        cout << st;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "\t\tAddFun Completed\n";
    return x + y;
}

int main()
{
    future<int> fut = std::async(AddFun, 100, 200);
    // future<int> fut = std::async(std::launch::async,AddFun, 100, 200);
    // future<int> fut = std::async(std::launch::deferred, AddFun, 10, 20);
    for (size_t i = 0; i < 4; i++)
    {
        cout << "Main Job\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
    int result = fut.get();
    cout << "Result = " + to_string(result) + "\n";
    return 0;
}