#include <iostream>
#include <string>
#include <map>
#include <thread>
#include <mutex>
#include <future>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

mutex mute;
void Origin(string msg, promise<string> &&prm)
{
    msg = "Origin- " + msg + "-Origin";
    prm.set_value(msg);
}

void Target1(int key, map<int, string> &repo, shared_future<string> fut)
{

    string msg = fut.get();
    msg = "t1- " + msg + "-t1";
    mute.lock();
    repo[key] = msg;
    mute.unlock();
}

void Target2(int key, map<int, string> &repo, shared_future<string> fut)
{

    string msg = fut.get();
    msg = "t2- " + msg + "-t2";
    mute.lock();
    repo[key] = msg;
    mute.unlock();
}

void Target3(int key, map<int, string> &repo, shared_future<string> fut)
{

    string msg = fut.get();
    msg = "t3- " + msg + "-t3";
    mute.lock();
    repo[key] = msg;
    mute.unlock();
}

int main()
{
    string msg = "Kill him not let him live";
    promise<string> prom;
    shared_future<std::string> fut = prom.get_future();
    map<int, string> repo;

    thread t1(&Origin, msg, std::move(prom));
    thread t2(&Target1, 10, ref(repo), fut);
    thread t3(&Target2, 20, ref(repo), fut);
    thread t4(&Target3, 30, ref(repo), fut);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    for (auto &[k, v] : repo)
    {
        cout << k << " " << v << "\n";
    }

    return 0;
}