#include <iostream>
#include <string> 
#include <ctime> // for time function
#include <cstdlib> // for rand and srand functions
using namespace std;

int main()
{
  srand(time(0));
  char ch1 = 'A' + rand() % ('Z' - 'A' + 1);
  char ch2 = 'A' + rand() % ('Z' - 'A' + 1);
  char ch3 = 'A' + rand() % ('Z' - 'A' + 1);

  string s;
  s = s + ch1 + ch2 + ch3;

  cout << s << endl;

  return 0;
}