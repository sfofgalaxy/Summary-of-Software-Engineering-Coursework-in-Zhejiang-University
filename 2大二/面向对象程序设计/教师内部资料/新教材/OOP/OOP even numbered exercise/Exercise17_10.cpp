#include <iostream>
#include <string>
using namespace std;

int count(const string& s, char a)
{
  int result = 0;
  if (s.size() > 0)
    result = count(s.substr(1, s.size() - 1), a) +
      ((s[0] == a) ? 1 : 0);

  return result;
}

int main()
{
  cout << "Enter a string: ";
  string s;
  getline(cin, s);

  cout << "Enter a character: ";
  char ch;
  cin >> ch;

  cout << count(s, ch) << endl;

  return 0;
}
