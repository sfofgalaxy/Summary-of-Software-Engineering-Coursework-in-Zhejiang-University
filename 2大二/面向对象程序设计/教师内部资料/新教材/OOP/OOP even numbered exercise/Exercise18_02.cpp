#include <iostream>
#include <string>
using namespace std;

/** The worst-case complexity is O(n^2) */
string maxSubstring(string s)
{
  // maxLength[i] stores the length of the max substring ending at index i
  int *maxLength = new int[s.length()];

  // previous[i] stores the index of the previous element in the sequenece
  int *previous = new int[s.length()];

  for (int i = 0; i < s.length(); i++)
  {
    maxLength[i] = 0;
    previous[i] = -1;
  }

  for (int i = 0; i < s.length(); i++)
  {
    previous[i] = -1;
    for (int j = i - 1; j >= 0; j--)
    {
      if (s.at(i) > s.at(j) && maxLength[i] < maxLength[j] + 1)
      {
        maxLength[i] = maxLength[j] + 1;
        previous[i] = j;
      }
    }
  }

  // Find the largest subsequence length and ending index
  int maxL = maxLength[0];
  int index = 0;
  for (int i = 1; i < s.length(); i++)
  {
    if (maxL < maxLength[i])
    {
      maxL = maxLength[i];
      index = i;
    }
  }

  // Constrcut the subsequence by tracing through previous
  char *chars = new char[maxL + 1];
  int i = maxL;
  chars[i + 1] = '\0';
  while (index != -1)
  {
    chars[i--] = s.at(index);
    index = previous[index];
  }

  return string(chars);
}

int main()
{
  cout << "Enter a string: ";
  char chars[100];
  cin.getline(chars, 100, '\n');
  string s(chars);
  cout << maxSubstring(s) << endl;

  return 0;
}
