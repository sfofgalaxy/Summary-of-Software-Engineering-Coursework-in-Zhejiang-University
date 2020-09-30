#include <iostream>
#include <string>
using namespace std;

// Convert a number to a string. This can be simplified later using stringstream introduced in Chapter 10
string toString(int number)
{
  string result;
  while (number != 0)
  {
    result = static_cast<char>(number % 10 + '0') + result;
    number = number / 10;
  }

  return result;
}

string format(int number, int width)
{
  string numberString = toString(number);
  string result = numberString;
     
  for (int i = 0; i < width - numberString.size(); i++)
    result = "0" + result;
      
  return result;
}

int main()
{
  int number, width;
  cout << "Enter an integer: ";
  cin >> number;
   
  cout << "Enter the width: ";
  cin >> width;
    
  cout << "The formatted number is " << format(number, width) << endl;

  return 0;
}