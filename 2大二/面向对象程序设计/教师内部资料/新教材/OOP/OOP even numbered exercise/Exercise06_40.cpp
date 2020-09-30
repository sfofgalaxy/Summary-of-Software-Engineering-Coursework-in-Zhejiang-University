#include <iostream>
#include <string>
using namespace std;

char convertToHex(int number)
{
  if (number == 10)
    return 'A';
  else if (number == 11)
    return 'B';
  else if (number == 12)
    return 'C';
  else if (number == 13)
    return 'D';
  else if (number == 14)
    return 'E';
  else if (number == 15)
    return 'F';

  return (char)(number + '0');
}

string reverse(string s)
{
  string result(s);
  int i = 0;

  for (int i = 0, j = s.length() - 1; i < s.length(); i++, j--)
    result[i] = s[j];

  return result;
}

string dec2Hex(int value)
{
  string s;

  while (value != 0)
  {
    int number = value % 16;
    char ch = convertToHex(number);
    s += ch; // or s.append(1, ch);
    value = value / 16;
  }

  return reverse(s);
}

int main()
{
  cout << "Enter a decimal number: ";
  int number;
  cin >> number;
  cout << dec2Hex(number) << endl;

  return 0;
}
