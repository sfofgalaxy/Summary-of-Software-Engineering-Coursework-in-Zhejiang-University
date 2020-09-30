#include <iostream>
#include <string>
using namespace std;

void reverseDisplay(const string& s, int high)
{
  if (high >= 0)
  {
    cout << s[high];
    reverseDisplay(s, high - 1);
  }
}

void reverseDisplay(const string& s)
{
  reverseDisplay(s, s.size() - 1);
}

int main()
{
  cout << "Enter a string: ";
  string s;
  cin >> s;

  reverseDisplay(s);

  return 0;
}
