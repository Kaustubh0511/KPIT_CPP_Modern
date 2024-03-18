#ifndef START_HPP
#define START_HPP

#include "Functions.hpp"
void start(string msg, vector<string>& infoPile)
{
    promise<string> prom;
    shared_future<string> fut = prom.get_future();

    thread sender_thread(&Sender, msg, std::move(prom));
    thread reciever1_thread(&Reciver1, ref(infoPile), (fut));
    thread reciever2_thread(&Reciver2, ref(infoPile), (fut));
    thread reciever3_thread(&Reciver3, ref(infoPile), (fut));

    sender_thread.join();
    reciever1_thread.join();
    reciever2_thread.join();
    reciever3_thread.join();
}

#endif // START_HPP
