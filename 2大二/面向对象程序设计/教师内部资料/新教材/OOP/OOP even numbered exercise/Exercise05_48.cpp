#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
  int count = 0;
  string s;

  cout << "Enter a string: ";
  cin >> s;

  for (int i = 0; i < s.size(); i++)
  {
    if (isupper(s[i]))
      count++;
  }

  cout << "The number of uppercase letter in " << s << " is " << count << endl;

  return 0;
}
