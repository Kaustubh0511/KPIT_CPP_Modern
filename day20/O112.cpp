#include<iostream>
#include<any>
#include<optional>
#include<functional>
using namespace std;


namespace nm112
{
	class Base
	{
		int count;
	public:
		Base(int count) :count(count)
		{
		}
	};

	template<typename T, int size>
	class CA :public Base
	{
		int arr[size];
	public:
		CA() :Base(size)
		{

			cout << " T= [ " << typeid(T).name() << " ]\n";
		}
		void AddFun(T obj)
		{
		}
	};


	template<int size>
	class CA<int, size> :public Base
	{
		int arr[size];
	public:
		CA() :Base(size)
		{

			cout << " Specialized for Integer \n";
		}
		void AddFun(int obj)
		{
		}
	};


	template<typename T, int size>
	class CA<T*, size> :public Base
	{
		int arr[size];
	public:
		CA() :Base(size)
		{

			cout << "partial Specialized for pointers  T= [ " << typeid(T).name() << " ]\n";
		}
		void AddFun(int obj)
		{
		}
	};

	int main()
	{
		CA<int, 10> obj1;
		cout << "________________________________\n";
		CA<double, 10> obj2;
		CA<float, 10> obj3;
		cout << "________________________________\n";
		CA<int*, 10> obj11;
		CA<double*, 10> obj21;
		CA<float*, 10> obj31;
		return 0;
	}
}