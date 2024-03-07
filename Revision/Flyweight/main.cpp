#include"dummy.hpp"
#include "computer.hpp"
#include "iostream"
int main()
{
    computer c1("dell", "lattitude", "intel", "32gb", "1.5tb", "11inch");
		computer c2("dell", "lattitude", "intel", "16gb", "2tb", "13inch");
		computer c3("dell", "lattitude", "intel", "16gb", "1.5tb", "15inch");
		computer c4("hp", "flash", "cellron", "32gb", "0.5tb", "11inch");
		computer c5("dell", "lattitude", "cellron", "64gb", "0.5tb", "15inch");
		computer c6("dell", "lattitude", "intel", "16gb", "2tb", "11inch");

		std::cout << c1 << c2 << c3 << c4 << c5 << c6 << '\n';
		std::cout << "Total computer Ordered : " << computer::count << '\n';
		// std::cout << "Total MSP      Used    : " << MSP::count << '\n';
		return 0;
}