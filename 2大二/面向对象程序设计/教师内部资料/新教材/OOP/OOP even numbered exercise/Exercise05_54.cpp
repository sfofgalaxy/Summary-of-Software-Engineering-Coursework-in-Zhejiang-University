#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
  ifstream input("c:\\cplusplusexercise\\countletters.txt");

  int count = 0;
  string word;
  while (!input.eof())
  {
    input >> word;

    for (unsigned i = 0; i < word.size(); i++)
      if (isalpha(word[i]))
        count++;
  }

  cout << "The number of letters is " << count << endl;

  return 0;
}