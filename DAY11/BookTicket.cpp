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

std::once_flag flag;
void BookTicket(string vendor, int min_time)
{
    string st = vendor + " trying to book the ticket\n";
    cout << st;
    this_thread::sleep_for(chrono::seconds(min_time));
    std::call_once(flag, [vendor]()
                   {
                    string st = vendor + " sucessfully booked the ticket\n";
                    cout << st; });
}

int main()
{
    thread t1(BookTicket, "IRCTC", 4);
    thread t2(BookTicket, "GoIBIBO", 2);
    thread t3(BookTicket, "Yatra", 3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}