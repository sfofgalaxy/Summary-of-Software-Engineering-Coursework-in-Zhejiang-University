#include <iostream>
using namespace std;

void prefix(const char s1[], const char s2[], char commonPrefix[])
{
  int len = strlen(s1);

  int i = 0;
  for (; i < len; i++)
  {
    if (s1[i] == s2[i])
    {
      commonPrefix[i] = s1[i];
    }
    else
      break;
  }

  commonPrefix[i] = '\0'; // Set a null terminator
}

int main()
{
  // Prompt the user to enter two strings
  cout << "Enter a string s1: ";
  char s1[80];
  cin.getline(s1, 80);

  // Prompt the user to enter two strings
  cout << "Enter a string s2: ";
  char s2[80];
  cin.getline(s2, 80);

  char s3[80];
  int size = 0;
  prefix(s1, s2, s3);
  if (strlen(s3) == 0)
    cout << "No common prefix" << endl;
  else
    cout << "The common prefix is " << s3 << endl;

  return 0;
}
