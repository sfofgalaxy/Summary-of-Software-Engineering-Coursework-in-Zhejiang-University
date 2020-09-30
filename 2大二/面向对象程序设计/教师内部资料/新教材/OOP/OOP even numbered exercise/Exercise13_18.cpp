#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
  cout << "Enter the number of source files: ";
  int numberOfSourceFiles;
  cin >> numberOfSourceFiles;

  vector<string> files;
  for (int i = 0; i < numberOfSourceFiles; i++) {
    // Enter a source file
    cout << "Enter a source file name: ";
    string inputFilename;
    cin >> inputFilename;
    files.push_back(inputFilename);
  }

  ofstream output;
  // Enter an output file
  cout << "Enter an output file name: ";
  string outputFilename;
  cin >> outputFilename;
  output.open(outputFilename.c_str(), ios::binary);

  int count = 0;
  char ch[1024];
  ifstream input;
  for (int i = 0; i < numberOfSourceFiles; i++) {
    input.open(files[i].c_str(), ios::binary);

    if (input.fail())
    {
      cout << files[i].data() << " does not exist" << endl;
      cout << "Exit program" << endl;
      return 0;
    }
    while (!input.eof()) // Continue if not end of file
    {
      input.read(ch, 1024);
      output.write(ch, input.gcount());
      count += input.gcount();
    }

    input.close();
    input.clear();
  }

  cout << "count " << count << endl;
  cout << "File " << outputFilename << " produced " << endl;
  output.close();
  cout << "\nJoin Done" << endl;

  return 0;
}
