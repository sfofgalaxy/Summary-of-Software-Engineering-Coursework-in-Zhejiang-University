#include <iostream>
using namespace std;

int main()
{
  cout << "Enter a number in pounds: ";
  double pounds;
  cin >> pounds;

  double kilograms = pounds * 0.454;

  cout << "The kilograms is " << kilograms << endl;

  return 0;
}
