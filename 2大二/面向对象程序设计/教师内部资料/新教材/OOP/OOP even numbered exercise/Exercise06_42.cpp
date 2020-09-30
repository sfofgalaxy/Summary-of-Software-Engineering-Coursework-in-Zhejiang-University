#include <iostream>
#include <string>
using namespace std;

string prefix(const string& s1, const string& s2) 
{
  string s;

  int i = 0;
  for (; i < s1.size() && i < s2.size(); i++)
  {
    if (s1[i] == s2[i])
      s += s1[i];
    else
      break;
  }

  return s;
}

int main()
{
  string s1, s2;

  cout << "Enter s1: ";
  cin >> s1;

  cout << "Enter s2: ";
  cin >> s2;

  string s3 = prefix(s1, s2);
  if (s3.size() == 0)
    cout << "No common prefix" << endl;
  else
    cout << "The common prefix is " << prefix(s1, s2) << endl;

  return 0;
}
