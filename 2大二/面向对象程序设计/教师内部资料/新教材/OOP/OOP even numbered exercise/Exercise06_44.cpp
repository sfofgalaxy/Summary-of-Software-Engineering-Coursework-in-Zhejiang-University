#include <iostream>
#include <string>
using namespace std;

int count(const string& s, char a)
{
  int count = 0;

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == a) count++;
  }

  return count;
}

int main()
{
  // Prompt the user to enter a string
  cout << "Enter a string: ";
  string s;
  getline(cin, s);

  // Prompt the user to enter a character
  cout << "Enter a character: ";
  char a;
  cin >> a;

  cout << count(s, a) << endl;

  return 0;
}
