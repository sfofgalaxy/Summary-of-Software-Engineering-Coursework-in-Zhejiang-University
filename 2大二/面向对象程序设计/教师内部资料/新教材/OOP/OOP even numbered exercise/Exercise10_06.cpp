#include <iostream>
#include <string>
using namespace std;

int countLetters(const string& s)
{
  int count = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (isalpha(s[i])) count++;
  }

  return count;
}

int main()
{
  cout << "Enter a string: ";
  string s;
  getline(cin, s);

  cout << "The number of letters in " << s << " is " << countLetters(s) << endl;

  return 0;
}