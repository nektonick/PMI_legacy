#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

mutex forks[5];

mutex cout_mutex;
void print_msg(const string& msg)
{
	cout_mutex.lock();
	cout << msg << flush;
	cout_mutex.unlock();
}


void Phil(size_t idx, const string& id)
{
  mutex& left_fork  = forks[ idx==0 ? 4 : idx-1 ];
  mutex& right_fork = forks[ idx ];

	while(true)
	{
	  {
			ostringstream ostr;
			ostr << id << " is thinking about" << endl;
			print_msg(ostr.str());
		}
	  // Thinking about...
		this_thread::sleep_for(chrono::seconds(rand()%5)); 

		// Got hungry
	  {
			ostringstream ostr;
		  ostr << id << " got hungry" << endl;
			print_msg(ostr.str());
		}

		// wait for left fork
		//while(!left_fork.try_lock()) this_thread::yield();
		left_fork.lock();

	  {
			ostringstream ostr;
		  ostr << id << " got left fork! " << endl;
			print_msg(ostr.str());
		}

		// wait for left fork
		//while(!right_fork.try_lock()) this_thread::yield();
		right_fork.lock();
	  {
			ostringstream ostr;
		  ostr << id << " got right fork! " << endl;
			print_msg(ostr.str());
		}
		
		// at last! can eat
	  {
			ostringstream ostr;
		  ostr << id << " can eat!" << endl;
			print_msg(ostr.str());
		}
		this_thread::sleep_for(chrono::seconds(1)); 

		right_fork.unlock();
    left_fork.unlock();

	  {
			ostringstream ostr;
		  ostr << id << " put forks on the table" << endl;
			print_msg(ostr.str());
		}

	}
}



int main()
{
	srand(time(0));
  vector<thread> philosophers;
	philosophers.push_back(thread(Phil,0,"Socrat"));
	philosophers.push_back(thread(Phil,1,"Platon"));
	philosophers.push_back(thread(Phil,2,"Decart"));
	philosophers.push_back(thread(Phil,3,"Popper"));
	philosophers.push_back(thread(Phil,4,"Aristotel"));

	for(auto &t : philosophers) t.join();
	
	return 0;
}

