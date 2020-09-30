#include <iostream>
#include <string>
using namespace std;

#ifndef STRING_H
#define STRING_H

class MyString : public string
{
public:
  MyString();

  MyString(string s);

  // Return a new string with all left whitespace characters trimmed 
  string leftTrim() const; 

  // Return a new string with all right whitespace characters trimmed 
  string rightTrim() const;

  // Return a new string with all whitespace characters trimmed 
  // from both ends
  string trim() const;
};

#endif

MyString::MyString() : string()
{
}

MyString::MyString(string s) : string(s)
{
}

string MyString::leftTrim() const
{
  string s = *this;
  for (unsigned i = 0; i < s.size(); i++)
    if (isspace(s[i]))
      s.erase(0, 1);
    else
      break;

  return s;
}

string MyString::rightTrim() const
{
  string s = *this;
  for (unsigned i = s.size() - 1; i >= 0; i--)
    if (isspace(s[i]))
      s.erase(i, 1);
    else
      break;

  return s;
}

string MyString::trim() const
{
  MyString s = this->leftTrim();
  return s.rightTrim();
}

int main()
{
  cout << "Enter a string: ";
  MyString s;
  getline(cin, s);

  cout << "The trimmed string is " << s.trim() << endl;

  return 0;
}
