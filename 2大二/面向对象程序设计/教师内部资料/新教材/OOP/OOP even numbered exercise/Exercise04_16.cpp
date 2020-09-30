#include <iostream>
#include <string>
using namespace std;

int main()
{
  cout << "Enter a string: ";
  string s;
  getline(cin, s);

  cout << "The length of string " << s << " is " << s.length() << endl;
  cout << "The first character of string " << s << " is " << s[0] << endl;

  return 0;
}