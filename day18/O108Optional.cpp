#include<iostream>
#include<functional>
#include<string>
#include<vector>
#include<optional>
using namespace std;
#define line(msg) cout<<"___________________"#msg"____________________\n"

namespace nm108
{
	std::optional<std::string> GetValForFun(int par)
	{
		if (10 == par)
		{
			return "kunal";
		}
		else if (20 == par)
		{
			return {};//nullopt
		}
		return nullopt;
	}


	int main1()
	{
		cout << GetValForFun(10).value_or("Dere1") << '\n';
		cout << GetValForFun(20).value_or("Dere2") << '\n';
		cout << GetValForFun(30).value_or("Dere3") << '\n';

		std::optional<std::string> res = GetValForFun(10);
		if (res.has_value())
		{
			cout << "Has value " << res.value() << '\n';
		}


		return 0;
	}


	auto ChangeVal(int par)
	{
		static string name = "shubam";
		return par == 10 ? std::optional<std::reference_wrapper<std::string>>{name} : std::nullopt;
	}

	int main()
	{
		auto res = ChangeVal(10);

		cout << res->get() << '\n';
		res->get() = "Das";
		auto res1 = ChangeVal(10);
		cout << res1->get() << '\n';

		return 0;
	}
}