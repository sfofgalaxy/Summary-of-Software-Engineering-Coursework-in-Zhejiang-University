#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int getNumberOfUppercaseLetters(const string& s, int high) 
{
  if (high == 0)
    return isupper(s[0]) ? 1 : 0;
  else
    return getNumberOfUppercaseLetters(s, high - 1) + (isupper(s[high]) ? 1 : 0);
}

int getNumberOfUppercaseLetters(const string& s) 
{
  return getNumberOfUppercaseLetters(s, s.size() - 1);
}


int main()
{
  cout << "Enter a string: ";
  string s;
  getline(cin, s);

  cout << getNumberOfUppercaseLetters(s) << endl;

  return 0;
}
