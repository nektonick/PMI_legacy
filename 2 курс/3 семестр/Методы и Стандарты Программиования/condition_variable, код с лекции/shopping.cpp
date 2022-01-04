#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

#include <vector>
#include <string>

using namespace std;

mutex m;
condition_variable producer_cv, consumer_cv;
string product;

void production(const string& id, vector<string> goods)
{
  while(!goods.empty())
	{
		unique_lock<mutex> lk(m);
		producer_cv.wait(lk, [](){return product.empty();});
		product = goods.back();
		cout << id << " selling " << product << endl;
		consumer_cv.notify_one();
		lk.unlock();
		goods.pop_back();
	}
	cout << id << " is finished and going home" << endl;
}

void consumption(const string& id)
{
	while(true)
	{
	 	unique_lock<mutex> lk(m);
		consumer_cv.wait(lk, [](){ return !product.empty(); });
		if(product == "Closed")
		{ 
			cout << id << " is going home" << endl;
			consumer_cv.notify_one();
			lk.unlock();
			break;
		}
		else
		{
			cout << id << " buy " << product << endl;
			product.clear();
			producer_cv.notify_one();
			lk.unlock();
		}
	}
}


int main()
{
	vector<thread> producers;
 
  vector<string> apple_products;
	apple_products.push_back("IPhone");
	apple_products.push_back("IPad");
	apple_products.push_back("Mac Book");

	producers.push_back(thread(production, "Apple", apple_products));

  vector<string> horse_shop_products;
	horse_shop_products.push_back("Rainbow Dash");
	horse_shop_products.push_back("Lasy Cow");
	horse_shop_products.push_back("Swift");
	horse_shop_products.push_back("Pinkypie");
	horse_shop_products.push_back("Horse X");

	producers.push_back(thread(production, "Lucky Horseshoe", horse_shop_products));

	vector<thread> consumers;
	consumers.push_back(thread(consumption, "Tania"));
	consumers.push_back(thread(consumption, "Vania"));

  for(auto& t : producers) t.join();

	cout << "All producers are gone" << endl;
	{
	  unique_lock<mutex> lk(m);
		product = "Closed";
		consumer_cv.notify_all();
	}

	for(auto& t : consumers) t.join();

	cout << "========= Shop is Closed" << endl;

	return 0;
}


