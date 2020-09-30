#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  const int FILENAME_SIZE = 40;
  ifstream input;

  // Enter a source file
  cout << "Enter a source file name: ";
  char inputFilename[FILENAME_SIZE];
  cin >> inputFilename;
  input.open(inputFilename, ios::binary);

  if (input.fail())
  {
    cout << inputFilename << " does not exist" << endl;
    cout << "Exit program" << endl;
    return 0;
  }

  ofstream output;
  // Enter a target file
  cout << "Enter an output file name: ";
  char outputFilename[FILENAME_SIZE];
  cin >> outputFilename;
  output.open(outputFilename, ios::binary);

  int count = 0;
  char ch[1];

  while (!input.eof()) // Continue if not end of file
  {
    input.read(ch, 1);
    *ch -= 5;
    output.write(ch, input.gcount());
    count += input.gcount();
  }

  input.close();

  cout << "count " << count << endl;
  cout << "File " << outputFilename << " produced " << endl;
  output.close();
  cout << "\nDecryption Done" << endl;

  return 0;
}

/* Works if you simply modify CopyFile.cpp as follows:

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  // Enter a source file
  cout << "Enter a source file name: ";
  string inputFilename;
  cin >> inputFilename;

  // Enter a target file
  cout << "Enter a target file name: ";
  string outputFilename;
  cin >> outputFilename;

  // Create input and output streams
  ifstream input(inputFilename.c_str());
  ofstream output(outputFilename.c_str());

  if (input.fail())
  {
    cout << inputFilename << " does not exist" << endl;
    cout << "Exit program" << endl;
    return 0;
  }

  char ch = input.get();
  while (!input.eof()) // Continue if not end of file
  {
    output.put(ch - 5);
    ch = input.get(); // Read next character
  }

  input.close();
  output.close();

  cout << "\nCopy Done" << endl;

  return 0;
}
*/