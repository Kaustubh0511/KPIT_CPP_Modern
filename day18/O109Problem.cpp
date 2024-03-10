#include<iostream>
using namespace std;

namespace nm109
{
	template<typename T>
	class Adapter
	{
		T fn;
	public:
		Adapter(T fn) :fn(fn)
		{
		}
		template<typename... PCK>
		auto operator()(PCK&&... args)
		{
			return std::invoke(fn, std::forward<PCK>(args)...);
		}
	};

	auto sum1 = [](int x, int y) {
		return x + y;
	};

	auto sum2 = [](int x, int y, int z) {
		return x + y + z;
	};

	int main1()
	{
		Adapter<decltype(sum1)>   a{ sum1 };
		Adapter   b{ sum1 };//CTAD
		std::cout << a(11, 22) << '\n';
		std::cout << b(11, 22) << '\n';
		std::cout << Adapter{ sum2 }(10, 10, 10) << '\n';
		return 0;
	}

	template<typename T>
	auto fun1(T fn)
	{
		cout << " T [ " << typeid(T).name() << " ]\n";
		cout << "Apple\t";
		return fn;
	}

	int main()
	{
		cout << Adapter{ fun1<decltype(sum1)> }(sum1)(10, 20) << '\n';
		return 0;
	}
}