#include <iostream>
#include <string>
using namespace std;

int* countLetters(const string& s)
{
  int* counts = new int[26];
  for (int i = 0; i < 26; i++)
    counts[i] = 0;

  for (int i = 0; i < s.size(); i++)
  {
    if (isalpha(s[i]))
      counts[tolower(s[i]) - 'a'] ++;
  }

  return counts;
}

int main()
{

  int* counts = countLetters(string("ABcaBaddeekjdfefdeg,TTew44Tt"));

  for (int i = 0; i < 26; i++)
    cout << static_cast<char>(i + 'a') << " " << counts[i] << endl;

  return 0;
}
