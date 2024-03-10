#include<iostream>
#include<string>
#include<string_view>
#include<chrono>
using namespace std;
#define line(msg) cout<<"___________________"#msg"____________________\n"

namespace nm111
{
	void f1(string str)
	{
		cout << str.substr(7, 6) << endl;
	}
	void f2(const string& str)
	{
		cout << str.substr(7, 6) << endl;
	}
	void f3(std::string_view str)
	{
		cout << str.substr(7, 6) << endl;

	}

	int main1()
	{
		string st = "Sachin Ramesh Tendulkar";
		f1(st);
		f2(st);
		f3(st);
		line();
		string my_str = "0123456789-0123456789-0123456789-0123456789-0123456789";
		cout << my_str << '\n';
		std::string_view st_view{ my_str.c_str(),my_str.size() };
		st_view.remove_prefix(5);
		cout << my_str << '\n';
		cout << st_view << '\n';
		cout << my_str << '\n';

		return 0;
	}


	int main()
	{
		string my_str = "0123456789-Sachin-0123456789-0123456789-0123456789";
		cout << my_str << '\n';

		std::string_view st_view{ my_str.c_str(),my_str.size() };
		st_view.remove_prefix(5);
		const size_t count = 1000000;
		auto start = std::chrono::steady_clock::now();
		for (size_t i = 0; i < count; i++)
		{
			auto s = my_str.substr(11, 6);
		}
		std::chrono::duration<double> duration_taken = std::chrono::steady_clock::now() - start;

		auto start1 = std::chrono::steady_clock::now();
		for (size_t i = 0; i < count; i++)
		{
			auto s = st_view.substr(11, 6);
		}
		std::chrono::duration<double> duration_taken1 = std::chrono::steady_clock::now() - start1;

		cout << "duration taken : " << duration_taken.count() << " second\n";
		cout << "duration taken 1 : " << duration_taken1.count() << " second\n";

		return 0;
	}
}