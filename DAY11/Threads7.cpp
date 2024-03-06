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

void Sender1(promise<int> &&prm)
{
    for (int x = 1; x <= 10; x++)
    {
        string str = "\t\t\t\tfun x = " + to_string(x) + " Tid [" + get_tid(this_thread::get_id()) + "]\n";
        cout << str;
        this_thread::sleep_for(chrono::seconds(1));
        if (7 == x)
        {
            prm.set_value(999);
        }
    }
}

void Reciver1(shared_future<int> fut)
{
    cout << "Reciver1 started\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Reciver1 on \n";
    int res = fut.get();
    cout << "Result = " << res << "\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Reciver1 done\n";
}

void Reciver2(shared_future<int> fut)
{
    cout << "\t\tReciver2 started\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\t\tReciver2 on \n";
    int res = fut.get();
    cout << "Result = " << res << "\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\t\tReciver2 done\n";
}

void Reciver3(shared_future<int> fut)
{
    cout << "\t\t\t\tReciver3 started\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\t\t\t\tReciver3 on \n";
    int res = fut.get();
    cout << "Result = " << res << "\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\t\t\t\tReciver3 done\n";
}

int main()
{
    promise<int> prom;
    shared_future<int> fut = prom.get_future();
    thread t1(&Sender1, std::move(prom));
    thread t2(&Reciver1, fut);
    thread t3(&Reciver2, fut);
    thread t4(&Reciver3, fut);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}