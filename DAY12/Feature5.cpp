#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <functional>
#include <mutex>
#include <sstream>
#include <future>
#include <tuple>
#include <set>
using namespace std;
#define line(msg) cout << "--------------" #msg "------------\n";

enum Signal // unscoped enum
{
    red,
    yellow,
    green
};

enum class Color // scoped enum
{
    pink,
    blue,
    black
};

enum class Mood // scoped enum
{
    hungry,
    dipress,
    happy
};

int main()
{
    switch (Signal sg = Signal::red; sg)
    {
    case red:
        break;
    case yellow:
        break;
    case green:
        break;
    }

    
    return 0;
}
