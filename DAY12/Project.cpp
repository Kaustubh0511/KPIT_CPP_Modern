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

class Singleton
{
public:
    Singleton()
    {
        cout << "Singleton Class Constructor\n";
    }
    Singleton(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    void operator=(const Singleton &) = delete;
    ~Singleton()
    {
        cout << "Singleton Class Destructor\n";
    }
};

int main()
{
    return 0;
}