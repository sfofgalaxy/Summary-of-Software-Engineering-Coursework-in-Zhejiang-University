#include <iostream>
using namespace std;

int main()
{
  int value1, value2;
  cout << "Enter two integers: ";
  cin >> value1 >> value2;
  
  if (value1 % value2 == 0)
    cout << value1 << " is divisible by " << value2 << endl;
  else 
    cout << value1 << " is not divisible by " << value2 << endl;
  
  return 0;
}