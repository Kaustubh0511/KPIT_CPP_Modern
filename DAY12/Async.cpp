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

void AddWrapper(promise<int> &&prm, int x, int y)
{
    int res = AddFun(x, y);
    prm.set_value(res);
}
int main()
{
    promise<int> addprom;
    future<int> addfut = addprom.get_future();
    cout << "Main Tid [" + get_tid(this_thread::get_id()) + "]\n";
    // int result = AddFun(10, 20);
    // thread t1(AddFun, 100, 200);
    thread t1(AddWrapper, std::move(addprom), 100, 200);
    for (size_t i = 0; i < 10; i++)
    {
        cout << "Main Job\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
    t1.join();
    int result = addfut.get();
    cout << "Result = " + to_string(result) + "\n";
    return 0;
}