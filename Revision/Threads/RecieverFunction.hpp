#ifndef RECIEVERFUNCTION_HPP
#define RECIEVERFUNCTION_HPP

#include <iostream>
#include <string>
#include <map>
#include <future>
#include <mutex>
#include <thread>
#include <functional>
using namespace std;

mutex mute;
void Target1(int key, map<int, string> &repo, shared_future<string> &fut)
{
    string msg = fut.get();
    msg = "t1 - " + msg + " - t1";
    std::lock_guard<std::mutex> lg(mute);
    repo[key] = msg;
    
}

void Target2(int key, map<int, string> &repo, shared_future<string> &fut)
{
    string msg = fut.get();
    msg = "t2 - " + msg + " - t2";
    std::lock_guard<std::mutex> lg(mute);
    repo[key] = msg;
    
}

void Target3(int key, map<int, string> &repo, shared_future<string> &fut)
{
    string msg = fut.get();
    msg = "t3 - " + msg + " - t3";
    std::lock_guard<std::mutex> lg(mute);
    repo[key] = msg;
    
}

#endif // RECIEVERFUNCTION_HPP
