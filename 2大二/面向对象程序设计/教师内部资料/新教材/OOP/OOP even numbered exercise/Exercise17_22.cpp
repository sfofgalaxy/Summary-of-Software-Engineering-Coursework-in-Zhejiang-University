#include <iostream>
#include <string> 
using namespace std;

char decimalToHexChar(int value)
{
  if (value == 10)
    return 'A';
  else if (value == 11)
    return 'B';
  else if (value == 12)
    return 'C';
  else if (value == 13)
    return 'D';
  else if (value == 14)
    return 'E';
  else if (value == 15)
    return 'F';
  else 
    return (char)('0' + value);
}

string decimalToHex(int value)
{
  if (value == 0)
    return "";
  else
  {
    return decimalToHex(value / 16) + decimalToHexChar(value % 16);  
  }
}

int main()
{
  cout << "Enter a decimal integer: ";
  int decimal;
  cin >> decimal;
  cout << decimal << " is hex " << decimalToHex(decimal) << endl;

  return 0;
}