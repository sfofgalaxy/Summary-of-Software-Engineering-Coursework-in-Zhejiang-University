#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string sort(string &s)
{
  const char* p = s.c_str(); 
  char* p1 = new char[strlen(p) + 1];
  strcpy(p1, p);
  sort(p1, p1 + strlen(p1));
  s.assign(p1);
  return s;
}

int main()
{
  // Prompt the user to enter a string
  cout << "Enter a string s: ";
  string s;
  getline(cin, s);

  cout << "The sorted string is " << sort(s) << endl;

  return 0;
}

