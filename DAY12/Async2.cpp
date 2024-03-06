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

int main1()
{
    std::async(std::launch::async, []()
               {this_thread::sleep_for(chrono::seconds(3)); cout<<"Apple\n"; });
    std::async(std::launch::async, []()
               {this_thread::sleep_for(chrono::seconds(5)); cout<<"Orange\n"; });
    std::async(std::launch::async, []()
               {this_thread::sleep_for(chrono::seconds(2)); cout<<"Pine\n"; });
    return 0;
}

int main2()
{
    future<void> f1 = std::async(std::launch::async, []()
                                 {this_thread::sleep_for(chrono::seconds(3)); cout<<"Apple\n"; });
    future<void> f2 = std::async(std::launch::async, []()
                                 {this_thread::sleep_for(chrono::seconds(5)); cout<<"Orange\n"; });
    future<void> f3 = std::async(std::launch::async, []()
                                 {this_thread::sleep_for(chrono::seconds(2)); cout<<"Pine\n"; });
    return 0;
}

int main3()
{
    std::async(std::launch::deferred, []()
               {this_thread::sleep_for(chrono::seconds(3)); cout<<"Apple\n"; });
    std::async(std::launch::deferred, []()
               {this_thread::sleep_for(chrono::seconds(5)); cout<<"Orange\n"; });
    std::async(std::launch::deferred, []()
               {this_thread::sleep_for(chrono::seconds(2)); cout<<"Pine\n"; });
    return 0;
}

int main()
{
    future<void> f1 = std::async(std::launch::deferred, []()
                                 {this_thread::sleep_for(chrono::seconds(3)); cout<<"Apple\n"; });
    future<void> f2 = std::async(std::launch::deferred, []()
                                 {this_thread::sleep_for(chrono::seconds(5)); cout<<"Orange\n"; });
    future<void> f3 = std::async(std::launch::deferred, []()
                                 {this_thread::sleep_for(chrono::seconds(2)); cout<<"Pine\n"; });
    return 0;
}