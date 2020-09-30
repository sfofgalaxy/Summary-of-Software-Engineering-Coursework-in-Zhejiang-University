#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cout << "Enter a string: ";
  cin >> s;

  for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
  {
    // Swap s[i] with s[j]
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }

  cout << "The reversed string is " << s << endl;

  return 0;
}