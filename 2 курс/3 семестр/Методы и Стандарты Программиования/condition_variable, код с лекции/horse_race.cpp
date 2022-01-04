#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

mutex m;
condition_variable event;

bool start = false;

void horse(const string& id)
{
  unique_lock<mutex> barrier(m);
	event.wait(barrier, [](){return start;});
	cout << id << endl;
	barrier.unlock();
}

void begin_race()
{
  unique_lock<mutex> barrier(m);
	cout << "Race is begin!" << endl;
	start = true;
	event.notify_all();
}

int main()
{
  vector<thread> horses;
  horses.push_back(thread(horse, "Rainbow Dash"));
  horses.push_back(thread(horse, "Lasy Cow"));
  horses.push_back(thread(horse, "Swift"));
  horses.push_back(thread(horse, "Pinkypie"));
  horses.push_back(thread(horse, "Horse X"));

  begin_race();

	for(auto& h : horses) h.join();

	cout << "==============" << endl;

	return 0;
}


