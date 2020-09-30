#include <iostream>
#include <cstring>
using namespace std;

int count(const char str[], char a)
{
  int count = 0;
  for (int i = 0; i < strlen(str); i++)
  {
    if (str[i] == a) count++;
  }
  return count;
}

int main()
{
  // Prompt the user to enter a string
  cout << "Enter a string: ";
  char s[80];
  cin.getline(s, 80);

  // Prompt the user to enter a character
  cout << "Enter a character: ";
  char a;
  cin >> a;

  cout << a << " appears in " << s << " " <<
    count(s, a) << " times " << endl;

  return 0;
}
