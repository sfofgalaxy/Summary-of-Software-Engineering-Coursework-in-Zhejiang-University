#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  cout << "Enter a file name for baby name ranking: ";
  string filename;
  cin >> filename;
  
  ifstream input(filename.c_str());

  if (input.fail())
  {
    cout << "File " << filename << " does not exist" << endl;
    return 1;
  }
  
  ofstream output((filename + ".new").c_str());
  
  while (!input.eof())
  {
    int dummy;
    input >> dummy; // Skip the ranking
    string s;
    input >> s; // Boy's name
    output << s << " ";

    input >> s; // Boy's count
    output << s << " ";

    input >> s; // Girl's name
    output << s << " ";

    input >> s; // Girl's count
    output << s << endl;
  }

  input.close();
  output.close();

  return 0;
}
