#include <iostream>
#include <string> 
using namespace std;

int hexCharToDecimal(char ch)
{
  if (ch >= 'A' && ch <= 'F')
    return 10 + ch - 'A';
  else 
    return ch - '0';
}

int hexToDecimal(const string& hexString, int low, int high)
{
  if (high < low)
    return 0;
  else
    return hexToDecimal(hexString, low, high - 1) * 16
      + hexCharToDecimal(hexString[high]);
}

int hexToDecimal(const string& hexString)
{
  return hexToDecimal(hexString, 0, hexString.length() - 1);
}
  
int main()
{
  cout << "Enter a hex number: ";
  string hex;
  cin >>hex;
  cout << hex << " is decimal " << hexToDecimal(hex) << endl;

  return 0;
}