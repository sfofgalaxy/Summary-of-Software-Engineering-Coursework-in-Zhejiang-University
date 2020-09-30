#include <iostream>
#include <string>
#include <ctime> // for time function
#include <cstdlib> // for rand and srand functions

using namespace std;

void shuffle(string& s) 
{
  srand(time(0));
  for (unsigned i = 0; i < s.size(); i++) 
  {
    int j = rand() % s.size();
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}

int main()
{
  string s;
  cout << "Enter a string: ";
  cin >> s;

  shuffle(s);

  cout << "The shuffled string is " << s << endl;

  return 0;
}