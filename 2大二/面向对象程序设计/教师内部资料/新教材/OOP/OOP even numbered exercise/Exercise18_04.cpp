#include <iostream>
#include <string>
using namespace std;

/**
 The worst-case complexity is O(nk), where n is s.length() and k is pattern.length()

@param s String
 @param pattern String
 @return int
*/
int match(string s, string pattern)
{
  for (int p = 0; p < s.length(); p++)
  {
    int k = 0;
    for (int i = p; i < s.length(); i++)
    {
      if (k == pattern.length())
        return i - pattern.length();
      else
      {
        if (s.at(i) == pattern.at(k))
          k++;
        else
          break;
      }
    }

    if (k == pattern.length())
      return s.length() - pattern.length();
  }

  return -1;
}

int main()
{
  cout << "Enter a string s1: ";
  char chars[100];
  cin.getline(chars, 100, '\n');
  string s1(chars);

  cout << "Enter a string s2: ";
  cin.getline(chars, 100, '\n');
  string s2(chars);

  cout << match(s1, s2) << endl;

  return 0;
}
