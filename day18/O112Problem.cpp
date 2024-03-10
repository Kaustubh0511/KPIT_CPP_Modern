#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;
#define line(msg) cout<<"___________________"#msg"____________________\n"

using FPTR = void(*)(string);
class Interpreter
{
	map<string, string> repo;
	FPTR client;
public:
	Interpreter(FPTR client) :client(client)
	{
	}
	void Register(string key, string value)
	{
		repo[key] = value;
		repo[value] = key;
	}
	string GetValue(string key)
	{
		return repo[key];
	}
	void Send(string key)
	{
		cout << "Sending " << key << '\t';
		client(GetValue(key));
	}
};

//---------------------

void Reciever(string msg)
{
	cout << "\t\t : " << msg << '\n';
}

int main1()
{
	string msg1 = "hi";
	string msg1_1 = "Namaste";


	string msg2 = "how are you";
	string msg2_1 = "kaise ho app";


	string msg3 = "your name";
	string msg3_1 = "aap ka naam";


	string msg4 = "I won't reveal";
	string msg4_1 = "mein nahien bolun";
	Interpreter inter(&Reciever);
	
	vector<pair<reference_wrapper<string>, reference_wrapper<string>>> vec{ pair{ref(msg1),ref(msg1_1)}, pair{ref(msg2),ref(msg2_1)}, pair{ref(msg3),ref(msg3_1)}, pair{ref(msg4),ref(msg4_1)} };
	for (auto [k, v] : vec)
	{
		inter.Register(k.get(), v.get());
	}
	
	
	/*
	pair p1{ msg1,msg1_1 };
	pair p2{ msg2,msg2_1 };
	pair p3{ msg3,msg3_1 };
	pair p4{ msg4,msg4_1 };
	vector<reference_wrapper<pair<string,string>>> vec{ p1,p2,p3,p4 };
	for (auto rng : vec)
	{
		auto [k, v] = rng.get();
		inter.Register(k, v);
	}
	*/

	inter.Send(msg1);
	inter.Send(msg2);
	inter.Send(msg3_1);
	inter.Send(msg4_1);

	return 0;
}


int main()
{
	Interpreter inter(&Reciever);
	string msg1 = "hi";
	string msg1_1 = "Namaste";
	inter.Register(msg1, msg1_1);

	string msg2 = "how are you";
	string msg2_1 = "kaise ho app";
	inter.Register(msg2, msg2_1);

	string msg3 = "your name";
	string msg3_1 = "aap ka naam";
	inter.Register(msg3, msg3_1);


	string msg4 = "I won't reveal";
	string msg4_1 = "mein nahien bolun";
	inter.Register(msg4, msg4_1);

	inter.Send(msg1);
	inter.Send(msg2);
	inter.Send(msg3_1);
	inter.Send(msg4_1);

	return 0;
}