#include <iostream>
#include <cctype>
using namespace std;

int main()
{
  cout << "Enter a letter: ";
  char letter;
  cin >> letter;

  if (toupper(letter) == 'A' || toupper(letter) == 'E' || toupper(letter) == 'I' 
      || toupper(letter) == 'O' || toupper(letter) == 'U')
    cout << letter << " is a vowel" << endl;
  else if (isalpha(letter))
    cout << letter << " is a consonant" << endl;
  else
    cout << letter << " is an invalid input" << endl;

  return 0;
}