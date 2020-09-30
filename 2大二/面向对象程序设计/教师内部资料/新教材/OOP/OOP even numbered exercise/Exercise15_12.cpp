#include <iostream>
#include <string>
using namespace std;

#ifndef STRING_H
#define STRING_H

class MyString : public string
{
public:
  // Return true if all characters in the string are letters.
  bool isAlpha() const; 

  // Return true if all characters in the string are digits.
  bool isDigit() const; 
};
#endif

bool MyString::isAlpha() const
{
  for (unsigned i = 0; i < this->size(); i++)
    if (!isalpha(this->at(i)))
      return false;

  return true;
}

bool MyString::isDigit() const
{
  for (unsigned i = 0; i < this->size(); i++)
    if (!isdigit(this->at(i)))
      return false;

  return true;
}

int main()
{
  MyString s;
  cout << "Enter a string: ";
  getline(cin, s);

  if (s.isAlpha())
    cout << "The string contains all letters" << endl;
  else if (s.isDigit())
    cout << "The string is a numeric string" << endl;
  else
    cout << "The string is not a letter string or numeric string" << endl;

  return 0;
}
