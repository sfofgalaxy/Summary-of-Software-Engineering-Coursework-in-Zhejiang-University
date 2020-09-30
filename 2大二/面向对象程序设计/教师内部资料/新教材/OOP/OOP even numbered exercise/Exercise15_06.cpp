#include <iostream>
#include <string>
using namespace std;

#ifndef STRING_H
#define STRING_H

class MyString : public string
{
public:
  bool isLowerCase() const;
  bool isUpperCase() const;
};

#endif

bool MyString::isLowerCase() const
{
  for (unsigned i = 0; i < this->size(); i++)
    if (!islower(this->at(i)))
      return false;

  return true;
}

bool MyString::isUpperCase() const
{
  for (unsigned i = 0; i < this->size(); i++)
    if (!isupper(this->at(i)))
      return false;

  return true;
}

int main()
{
  cout << "Enter a string: ";
  MyString s;
  getline(cin, s);

  if (s.isLowerCase())
    cout << "All characters in " << s << " are in lowercase" << endl;
  else if (s.isUpperCase())
    cout << "All characters in " << s << " are in uppercase" << endl;
  else
    cout << "Not all characters in " << s << " are in lowercase or uppercase" << endl;

  return 0;
}
