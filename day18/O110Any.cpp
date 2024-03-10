#include<iostream>
#include<any>

using namespace std;

//Any: typesafe single value container

namespace nm11
{

	int main()
	{
		//auto x = 10;
		//x = "sachin";

		std::any a = 10;
		a = "sachin";

		cout << a.type().name() << " : " << std::any_cast<const char*>(a) << '\n';

		a = 100;

		cout << a.type().name() << " : " << std::any_cast<int>(a) << '\n';

		a = 3.141;
		try
		{
			cout << a.type().name() << " : " << std::any_cast<int>(a) << '\n';
		}
		catch (std::bad_any_cast& exp)
		{
			cout << exp.what() << '\n';
		}
		a.reset();
		if (!a.has_value())
		{
			cout << "no value\n";
		}
		return 0;
	}
}