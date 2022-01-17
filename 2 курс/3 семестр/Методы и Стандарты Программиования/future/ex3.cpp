#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

void dig(future<void>& lunch)
{
  cout << "Солдаты! Копать отсюда и до обеда! Выполнять!" << endl;
	while(lunch.wait_for(chrono::seconds(1)) == future_status::timeout)
	{
		cout << "солдаты копают" << endl;
	}
	cout << "Обед! Урааааааа!" << endl;
}



int main() try
{
	promise<void> lunch;
	future<void>  future_lunch = lunch.get_future();
	thread digging(dig, ref(future_lunch));

	cout << "(Нажмите ENTER, когда будет обед, пожалуйста)" << endl;
	string l;	getline(cin,l);
	lunch.set_value();

	digging.join();
	return 0;
}
catch(exception& e)
{
	cerr << "Exception: " << e.what() << endl;
	return 1;
}
catch(...)
{
	cerr << "Unknown exception" << endl;
	return 2;
}

