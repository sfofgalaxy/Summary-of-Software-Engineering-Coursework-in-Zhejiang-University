#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void ftoa(double f, char s[]);

int main()
{
  char s[80];
  cout << "Enter a double value: ";
  double value;
  cin >> value;
  ftoa(value, s);

  for (int i = 0; i < strlen(s); i++)
    cout << s[i] << " ";

  return 0;
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

void ftoa(double f, char s[]) 
{
  // Convert f to an integer
  int count = 0;
  while (abs(f - static_cast<int>(f)) > 0.000001)
  {
    f *= 10;
    count++;
  }
  
  int value = f;
  // Extract the digits in value to s
  int i = 0;
  while (i < count)
  {
    s[i] = value % 10 + '0';
    value /= 10;
    i++;
  }

  s[i++] = '.';
  while (value != 0)
  {
    s[i] = value % 10 + '0';
    value /= 10;
    i++;
  }

  s[i] = '\0';

  reverse(s);
}