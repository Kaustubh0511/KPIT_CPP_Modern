#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

// Industry standard and norm for marathon.
class CA
{
public:
    CA() = default;
    CA(CA &&) noexcept = default;
    CA(const CA &) = delete;
    CA &operator=(const CA &) = delete;
    CA &operator=(CA &&) = default;
    ~CA() = default;
    void Display() const
    {
        cout<<"Hello Ji\n";
    }
    void setData()
    {
        cout<<"HI Ji\n";
    }
};
int main()
{
    CA obj;
    obj.Display(); // non-const object can access all member functions.
    obj.setData();
    const CA obj2;
    obj2.Display(); // const object can access const member functions only.
    return 0;
}