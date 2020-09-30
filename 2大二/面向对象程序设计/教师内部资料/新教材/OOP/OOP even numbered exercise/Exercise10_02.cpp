#include <iostream>
#include <string>
using namespace std;

bool inString(char ch, const string& s)
{
  for (unsigned i = 0; i < s.size(); i++)
    if (s[i] == ch)
      return true;

  return false;
}

string commonChars(const string& s1, const string& s2)
{
  string result;

  for (unsigned i = 0; i < s1.size(); i++) 
    if (inString(s1[i], s2) && !inString(s1[i], result))
      result += s1[i];

  return result;
}

int main()
{
  // Prompt the user to enter two strings
  cout << "Enter a string s1: ";
  string s1;
  getline(cin, s1);

  // Prompt the user to enter two strings
  cout << "Enter a string s2: ";
  string s2;
  getline(cin, s2);

  string commonCharacters = commonChars(s1, s2);
  if (commonCharacters.size() == 0)
    cout << "No common characters" << endl;
  else
    cout << "The common characters are " << commonCharacters << endl;

  return 0;
}
