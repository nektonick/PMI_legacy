#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;


void student(const std::string& id)
{
	cout << "студент " << id << " к курсовой работе по Языкам программирования приступил!" << endl;
  
  this_thread::sleep_for(chrono::seconds(1));

	cout << "студент " << id << " курсовую работу сделал!" << endl;
}

int main()
{
	future<void> f1 = async(launch::async,    student, "Батарейкин");
	future<void> f2 = async(launch::deferred, student, "Догоняев");

	this_thread::sleep_for(chrono::seconds(5));

	cout << "Сессия на носу! Студенты, имеющие хвосты и не сдавшие языки, будут повешены у деканата!" << endl;

	f1.get();
	f2.get();

	return 0;
}



