#include <iostream>
#include <cstdlib>
#include <ctime>

#include <exception>
#include <stdexcept>

#include <future>


using namespace std;


int cast_a_dice()
{
	return rand() % 6 + 1;
}


int main() try
{
	future<int> dice = async(cast_a_dice);

	cout << "You've got a " << dice.get() << endl;
	cout << "As I said, you got a " << dice.get() << endl;

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
