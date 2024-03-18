#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <future>
#include <mutex>
using namespace std;

mutex mut;
void Sender(string msg, promise<string> &&prm)
{
    prm.set_value(msg);
}

void Reciver1(vector<string> &vec, shared_future<string> fut)
{
    string msg = fut.get();
    msg = "Reciever1 -" + msg + "- Reciever1";
    mut.lock();
    vec.push_back(msg);
    mut.unlock();
}

void Reciver2(vector<string> &vec, shared_future<string> fut)
{
    string msg = fut.get();
    msg = "Reciever2 -" + msg + "- Reciever2";
    mut.lock();
    vec.push_back(msg);
    mut.unlock();
}

void Reciver3(vector<string> &vec, shared_future<string> fut)
{
    string msg = fut.get();
    msg = "Reciever3 -" + msg + "- Reciever3";
    mut.lock();
    vec.push_back(msg);
    mut.unlock();
}


#endif // FUNCTIONS_HPP
