#include <iostream>
#include <tuple>
#include <string>
#include <functional>
#include <list>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <string_view>
#include <map>
#include <vector>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

using FPTR = std::function<void(string)>;

class Interpreter
{
    std::map<string, string> repo;

public:
    FPTR client;
    Interpreter(FPTR client) : client(client)
    {
    }
    void Register(string key, string value)
    {
        repo[key] = value;
        repo[value] = key;
    }

    string getValue(string key)
    {
        return repo[key];
    }
    void Send(string key)
    {
        cout << "Sennding " << key << '\t';
        client(getValue(key));
    }
};

//---------------------------------------------------------
void Reciever(string msg)
{
    cout << "\t\t : " << msg << '\n';
}

int main()
{
    string msg1 = "hi";
    string msg1_1 = "Namaste";

    string msg2 = "how are you";
    string msg2_1 = "kaise ho aap";

    string msg3 = "your name";
    string msg3_1 = "aap ka naam";

    string msg4 = "I won't reveal";
    string msg4_1 = "mein nahi bolun";

    vector<pair<reference_wrapper<string>, reference_wrapper<string>>> vec{{ref(msg1), ref(msg1_1)}, {ref(msg2), ref(msg2_1)}, {ref(msg3), ref(msg3_1)}, {ref(msg4), ref(msg4_1)}};

    Interpreter inter(&Reciever);
    for (auto [k, v] : vec)
    {
        inter.Register(k.get(), v.get());
    }

    inter.Send(msg1);
    inter.Send(msg2);
    inter.Send(msg3_1);
    inter.Send(msg4_1);
}