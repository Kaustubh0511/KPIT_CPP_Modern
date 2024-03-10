#include<iostream>
#include<any>
#include<optional>
#include<functional>
using namespace std;

namespace nm111
{
	class DB
	{
	public:
		virtual void OpenDB() = 0;
		virtual void CloseDB() = 0;
		operator DB* ()
		{
			return this;
		}
	};

	template<typename T>
	class Account
	{
		DB* db{ nullptr };
	public:
		void setDB(DB* db)
		{
			this->db = db;
		}
		void DoJob(int Accid, int amount)
		{
			db->OpenDB();
			((T*)this)->DoDbit(Accid, amount);
			db->CloseDB();
		}
		//virtual void DoDbit(int Accid, int amount) = 0;
	};

	class Savings :public Account<Savings>
	{
	public:
		void DoDbit(int Accid, int amount)
		{
			cout << "Debit Savings\n";
		}
	};
	class Current :public Account<Current>
	{
	public:
		void DoDbit(int Accid, int amount)
		{
			cout << "Debit Current\n";
		}
	};

	class Mongo :public DB
	{
	public:
		void OpenDB() override
		{
			cout << "open Mongo db\n";
		}
		void CloseDB() override
		{
			cout << "close Mongo db\n";
		}
	};

	class Sql :public DB
	{
	public:
		void OpenDB() override
		{
			cout << "open Sql db\n";
		}
		void CloseDB() override
		{
			cout << "close Sql db\n";
		}
	};

	int main()
	{
		Mongo mongo;
		Savings sa;
		sa.setDB(mongo);
		sa.DoJob(101, 2000);

		Current curr;
		curr.setDB(new Sql());
		curr.DoJob(101, 1000);
		return 0;
	}
}