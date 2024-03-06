#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <functional>
#include <mutex>
using namespace std;
#define line(msg) cout << "--------------" #msg "------------\n";

mutex mute;
class CA
{
    int x{0};
    int y{0};

public:
    void AddFun()
    {
        for (x = 1; x <= 5; x++)
        {
            string str = "AddFun x = " + to_string(x) + '\n';
            cout << str;
            this_thread::sleep_for(chrono::seconds(1));
        }
        // mute.lock();
        for (y = 1; y <= 10; y++)
        {
            string str = "AddFun y = " + to_string(y) + '\n';
            cout << str;
            this_thread::sleep_for(chrono::seconds(1));
        }
        // mute.unlock();
    }
    void SubFun()
    {
        mute.lock();
        for (y = -1; y > -10; y--)
        {
            string str = "\t\tSubFun y = " + to_string(y) + '\n';
            cout << str;
            this_thread::sleep_for(chrono::seconds(1));
        }
        mute.unlock();
        for (x = -1; x > -5; x--)
        {
            string str = "\t\tSubFun x = " + to_string(x) + '\n';
            cout << str;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};

int main()
{
    CA obj;
    std::thread t1(std::bind(&CA::AddFun, std::ref(obj)));
    std::thread t2(std::bind(&CA::SubFun, std::ref(obj)));

    for (int k = 1; k <= 5; k++)
    {
        string str = "\t\t\t\tMain k = " + to_string(k) + '\n';
        cout << str;
        this_thread::sleep_for(chrono::seconds(1));
    }

    t1.join();
    t2.join();

    return 0;
}

//