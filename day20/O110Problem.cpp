#include<iostream>
#include<any>
#include<optional>
#include<functional>
using namespace std;

namespace nm110
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
			DoDbit(Accid, amount);
			db->CloseDB();
		}
		virtual void DoDbit(int Accid, int amount) = 0;
	};

	class Savings :public Account
	{
	public:
		void DoDbit(int Accid, int amount) override
		{
			cout << "Debit Savings\n";
		}
	};
	class Current :public Account
	{
	public:
		void DoDbit(int Accid, int amount) override
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