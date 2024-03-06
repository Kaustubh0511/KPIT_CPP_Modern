#include <iostream>
#include <vector>
using namespace std;
#define line(msg) cout << "--------------" #msg "------------\n";

template<typename T>
class My_Vector : private vector<T>
{
public:
    using vector<T>::push_back;
    using vector<T>::pop_back;
    void PushAll()
    {
    }
    template <typename T1, typename... T2>
    void PushAll(T1 x, T2... pck)
    {
        this->push_back(x);
        PushAll(pck...);
    }
    friend ostream &operator<<(ostream &os, My_Vector &v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            os << v[i] << '\t';
        }
        os << '\n';
        return os;
    }
};

int main()
{
    My_Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    cout << vec << '\n';
    line();

    vec.PushAll(50, 60, 70, 80, 90, 100);
    cout << vec << "\n";
    line();
    vec.pop_back();
    cout << vec << "\n";
    line();
    return 0;
}
