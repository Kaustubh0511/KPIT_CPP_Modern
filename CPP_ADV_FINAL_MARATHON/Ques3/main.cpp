#include "Start.hpp"
#include "Functions.hpp"

int main()
{
    string msg_from_service = "India won the test series";
    vector<string> infoPile;
    start(msg_from_service, infoPile);
    for (auto rng : infoPile)
    {
        cout << rng << "\n";
    }
    return 0;
}