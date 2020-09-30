#include <iostream>
using namespace std;

int main()
{
  cout << "Enter weight and price for package 1: ";
	double weight1, price1, weight2, price2;
	cin >> weight1 >> price1;

  cout << "Enter weight and price for package 2: ";
	cin >> weight2 >> price2;

	
  if (price1 / weight1 >= price2 / weight2)
    cout << "Package 2 has the best price." << endl;
  else
    cout << "Package 1 has the best price." << endl;

  return 0;
}