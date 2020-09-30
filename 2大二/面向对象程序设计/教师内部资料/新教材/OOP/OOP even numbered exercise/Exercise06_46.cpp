#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string swapCase(string& s) 
{
  string result;
  
  for (unsigned i = 0; i < s.size(); i++)
  {
    if (islower(s[i]))
      result += toupper(s[i]);
    else if (isupper(s[i]))
      result += tolower(s[i]);
    else
      result = result + s[i];
  } 
  
  return result;
}

int main()
{
  cout << "Enter a string: ";
  string s;
  getline(cin, s);

  cout << "The new string is: " << swapCase(s) << endl;

  return 0; 
}