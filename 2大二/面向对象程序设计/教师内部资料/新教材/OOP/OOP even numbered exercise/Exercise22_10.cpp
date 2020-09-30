#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main()
{
  string filename;
  cout << "Enter a file name: ";
  cin >> filename;

  ifstream input(filename.c_str());
  
  multiset<string> s;
  string word;
  while (!input.eof())
  {
    input >> word;
    s.insert(word);
  }
  
  for (multiset<string>::iterator p = s.begin(); p != s.end(); p++)
  {
    cout << *p << " ";
  }
 
  return 0;
}
