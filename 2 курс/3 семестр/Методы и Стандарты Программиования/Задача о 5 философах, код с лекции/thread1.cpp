#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

int res = 0;

void add(size_t n) 
{ 
	for(size_t i = 0; i < n; ++i)
	{
		++res; 
		cout << "+1" << flush;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

void sub(size_t n) 
{ 
	for(size_t i = 0; i < n; ++i)
	{
		--res; 
		cout << "-1" << flush;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

void mul2(size_t n) 
{ 
	for(size_t i = 0; i < n; ++i) 
	{
		res *=2; 
		cout << "*2" << flush;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

void div2(size_t n) 
{ 
	for(size_t i = 0; i < n; ++i) 
	{
		res/=2; 
		cout << "/2" << flush;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

int main()
{
  cout << "0" << flush;
	vector<thread> threads;
  threads.push_back(thread(add,  10));
  threads.push_back(thread(sub,  10));
  threads.push_back(thread(mul2, 10));
  threads.push_back(thread(div2, 10));

	for(auto &t : threads) t.join();

	cout << "=" << res << endl;

	return 0;
}


