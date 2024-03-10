// #include<iostream>
// #include<map>
// #include<thread>
// using namespace std;

// void Origin(string msg)
// {
// 	msg = "Origin - " + msg + "--Origin";
// }
// void Target1(int key, map<int, string> &repo)
// {
// 	msg = "t1-" + msg + "-t1";
// }
// void Target2(int key, map<int, string>& repo)
// {
// 	msg = "t2-" + msg + "-t2";
// }
// void Target3(int key, map<int, string>& repo)
// {
// 	msg = "t3-" + msg + "-t3";

// }
// int main()
// {
// 	string msg = "Kill him not let him live";
// 	map<int, string> repo;
// 	thread t1(&Origin);
// 	thread t2(&Target1);
// 	thread t3(&Target2);
// 	thread t4(&Target3);


// 	t1.join();
// 	t2.join();
// 	t3.join();
// 	t4.join();
// 	for (auto& [k, v] : repo)
// 	{
// 		cout << k <<'\t' << v << '\n';
// 	}
// 	return 0;
// }