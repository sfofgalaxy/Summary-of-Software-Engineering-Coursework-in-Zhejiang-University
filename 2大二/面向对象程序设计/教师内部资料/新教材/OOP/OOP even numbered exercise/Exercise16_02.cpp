#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void validate(const string& binaryString) 
{
  for (unsigned i = 0; i < binaryString.size(); i++)
  {
    if (binaryString[i] != '0' && binaryString[i] != '1')
      throw invalid_argument("Binary number format error");
  }
}

int bin2Dec(const string& binaryString)
{
  validate(binaryString);

  int value = binaryString[0] - '0';
  for (unsigned i = 1; i < binaryString.size(); i++)
  {
    value = value * 2 + binaryString[i] - '0';
  }

  return value;
}

int main()
{
  try
  {
    cout << "Enter a binary number: ";
    string binaryString;
    cin >> binaryString;
    cout << bin2Dec(binaryString) << endl;
  }
  catch (invalid_argument& ex)
  {
    cout << ex.what() << endl;
  }

  return 0;
}
