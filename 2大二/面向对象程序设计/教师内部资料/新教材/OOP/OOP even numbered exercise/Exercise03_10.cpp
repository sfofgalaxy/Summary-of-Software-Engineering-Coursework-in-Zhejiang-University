#include <iostream>
using namespace std;

int main()
{
  cout << "Enter the exchange rate from dollars to RMB: ";
  double rate;
  cin >> rate;
  
  cout << "Enter 0 to convert dollars to RMB and 1 vice versa: ";
  int conversionType;
  cin >> conversionType;
  
  if (conversionType == 0) 
  {
	cout << "Enter the dollar amount: ";
	double dollars;
	cin >> dollars;
	double RMB = dollars * rate;
	cout << "$" << dollars << " is " << RMB << "Yuan" << endl;
  }
  else 
  {
	cout << "Enter the RMB amount: ";
	double RMB;
	cin >> RMB;
	double dollars = RMB * (1 / rate);
	cout << RMB << " Yuan" << " is " << "$" << dollars << endl;
  }

  return 0;
}