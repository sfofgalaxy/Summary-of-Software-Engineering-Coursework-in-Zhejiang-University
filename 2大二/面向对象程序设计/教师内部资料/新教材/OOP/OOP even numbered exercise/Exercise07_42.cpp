#include <iostream>
#include <cstring>
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

void reverse(char s[]) 
{
  for (int i = 0, j = strlen(s) - 1; i < strlen(s) / 2; i++, j--)
  {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}

void dec2Hex(int value, char hexString[]) 
{
  int i = 0;
  while (value != 0)
  {
    int number = value % 16;
    char ch = convertToHex(number);
    hexString[i++] = ch; 
    value = value / 16;
  }

  hexString[i] = '\0';
  reverse(hexString);
}

int main()
{
  cout << "Enter a decimal number: ";
  int number;
  cin >> number;
  char hex[40];
  dec2Hex(number, hex);
  cout << hex << endl;

  return 0;
}
