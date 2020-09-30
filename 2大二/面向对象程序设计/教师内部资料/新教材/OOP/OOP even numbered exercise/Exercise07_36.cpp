#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void swapCase(const char s1[], char s2[])
{
  unsigned i = 0;
  for ( ; i < strlen(s1); i++)
  {
    if (islower(s1[i]))
      s2[i] = toupper(s1[i]);
    else if (isupper(s1[i]))
      s2[i] = tolower(s1[i]);
    else
      s2[i] = s1[i];
  } 

  s2[i] = '\0';
}

int main()
{

  cout << "Enter a string: ";
  char s1[40], s2[40];
  cin.getline(s1, 40, '\n');

  swapCase(s1, s2);

  cout << "The new string is: " << s2 << endl; 

  return 0; 
}