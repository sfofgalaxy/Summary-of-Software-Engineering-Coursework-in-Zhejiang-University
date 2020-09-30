#include <iostream>
using namespace std;

int main()
{
  cout << "Enter a decimal value (0 to 15): ";
  int decimal;
  cin >> decimal;
  
  if (decimal > 15 || decimal < 0)
    cout << decimal << " is invalid input" << endl;
  else if (decimal < 10)
    cout << "The hex value is " << decimal << endl;
  else 
    cout << "The hex value is " << static_cast<char>('A' + decimal - 10) << endl;

  return 0;
}