#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int indexOf(const vector<string>& v, string& name) 
{
  for (unsigned i = 0; i < v.size(); i++)
    if (v[i] == name)
      return i;
    
  return -1;
}

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
       
  vector<string> boyNames;
  vector<string> girlNames;
    
  while (!input.eof()) 
  {
    int dummy;
    input >> dummy; // Skip an integer for ranking
    string name;
    input >> name;
    boyNames.push_back(name); 
    input >> dummy; // Skip an integer for number of boys
    input >> name;
    girlNames.push_back(name);    
    input >> dummy; // Skip an integer for number of girls
  }
    
  // Find the names. The following is not an efficient way. After you learn STL, you can use the STL intersection function to perform the task
  vector<string> commonNames;
  for (int i = 0; i < boyNames.size(); i++)
    if (indexOf(girlNames, boyNames[i]) >= 0)
      commonNames.push_back(boyNames[i]);

  cout << commonNames.size() << " names are used for both boys and girls " << endl;
  cout << "They are ";
  for (int i = 0; i < commonNames.size(); i++)
    cout << commonNames[i] << " ";

  cout << endl;

  return 0;
}
