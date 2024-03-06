#include <iostream>
using namespace std;
#define line(msg) cout << "-----------------" #msg "---------------\n";

// void Greet(string name, string sep, string msg)
// {
//     cout << msg << sep << name << "\n";
// }

auto Greet(string name)
{
    return [name](string sep)
    {
        return [name, sep](string msg)
        {
            cout << msg << sep << name << "\n";
        };
    };
}
int main1()
{
    // Greet("Rajnikanth")( "----->")( "Happy Diwali");
    // Greet("Rahul Dravid")( "----->")( "Happy Diwali");
    // Greet("Sachin Tendulkar")( "----->")( "Happy Diwali");
    // line();
    // Greet("VVS")("----->")( "Happy Deepavali");
    // Greet("Chiranjeevi ")( "----->")( "Happy Deepavali");
    // Greet("NTR")( "----->")( "Happy Deepavali");
    // line();
    // Greet("Karthick")( "----->")( "Happy Deebawali");
    // Greet("KSK ")( "----->")( "Happy Deebawali");
    // Greet("Ravi Ashwin")( "----->")( "Happy Deebawali");
    return 0;
}

int main(){
    /* Currying below*/
    auto f1 = Greet("Rajnikanth");
    auto f2 = f1("-------->");

    f2("Happy Diwali");
    f2("Happy new year");
    f2("Happy onam");
    f2("Happy Pongal");
    f2("Happy sankranthi");
    return 0;
}