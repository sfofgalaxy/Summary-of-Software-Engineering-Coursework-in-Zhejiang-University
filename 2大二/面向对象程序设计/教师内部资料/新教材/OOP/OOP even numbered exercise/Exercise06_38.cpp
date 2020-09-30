#include <iostream>
#include <string>
using namespace std;

int bin2Dec(const string &binaryString)
{
  int value = binaryString[0] - '0';
  for (int i = 1; i < binaryString.length(); i++)
  {
    value = value * 2 + binaryString[i] - '0';
  }

  return value;
}

string dec2Hex(int decimal)
{
  // Convert decimal to hex
  string hex = "";
    
  while (decimal != 0)
	{
    int hexValue = decimal % 16; 
      
    // Convert a decimal value to a hex digit 
    char hexChar = (hexValue <= 9 && hexValue >= 0) ?
      static_cast<char>(hexValue + '0') : 
			static_cast<char>(hexValue - 10 + 'A');
      
    hex = hexChar + hex;
    decimal = decimal / 16;
  }
    
  return hex;
}

string bin2Hex(const string& binaryString)   
{
  int decimal = bin2Dec(binaryString);
  return dec2Hex(decimal);
}

int main()
{
  cout << "Enter a bianry number as a string: ";
  string bianryString;
  cin >> bianryString;

  cout << bin2Hex(bianryString) << endl;

  return 0;
}
