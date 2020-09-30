#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#ifndef STRING_H
#define STRING_H

class MyString : public string
{
public:
  // Return true if this string is equal to 
  // the string s case insensitive
  bool equalsIgnoreCaseWith(string s) const; 
};
#endif

bool MyString::equalsIgnoreCaseWith(string s) const
{
  if (this->size() != s.size())
    return false;

  for (unsigned i = 0; i < s.size(); i++)
    if (toupper(this->at(i)) != toupper(s[i]))
      return false;

  return true;
}

int main()
{
  MyString s1, s2;
  cout << "Enter string s1: ";
  getline(cin, s1);
  cout << "Enter string s2: ";
  getline(cin, s2);

  cout << "s1 and s2 are equal ignoring cases? " 
    << (s1.equalsIgnoreCaseWith(s2) ? "True" : "False") << endl;

  return 0;
}