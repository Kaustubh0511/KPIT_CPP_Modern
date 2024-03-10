#include "Senderfunction.hpp"
#include "RecieverFunction.hpp"

int main()
{

    map<int, string> repo;
    string msg = "Kaustubh is a good boy";
    promise<string> prom;
    shared_future<string> fut = prom.get_future();
    thread t1(&Origin, std::ref(prom), msg);
    thread t2(&Target1, 10, ref(repo), ref(fut));
    thread t3(&Target2, 20, ref(repo), ref(fut));
    thread t4(&Target3, 30, ref(repo), ref(fut));

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