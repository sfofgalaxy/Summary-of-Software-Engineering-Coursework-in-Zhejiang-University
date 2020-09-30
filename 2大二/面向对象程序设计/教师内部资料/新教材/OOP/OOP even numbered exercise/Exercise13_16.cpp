#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  const int FILENAME_SIZE = 40;

  // Enter a source file
  cout << "Enter a source file name: ";
  char inputFilename[FILENAME_SIZE];
  cin >> inputFilename;

  // Enter a target file
  cout << "Enter a target file name: ";
  char outputFilename[FILENAME_SIZE];
  cin >> outputFilename;

  ifstream input;
  ofstream output;

  // Open a file
  input.open(inputFilename, ios::binary);
  output.open(outputFilename, ios::binary);

  if (input.fail())
  {
    cout << inputFilename << " does not exist" << endl;
    cout << "Exit program" << endl;
    return 0;
  }

  char ch[1024];
  while (!input.eof()) // Continue if not end of file
  {
    input.read(ch, 1024);
    output.write(ch, input.gcount());
  }

  input.close();
  output.close();

  cout << "\nCopy Done" << endl;

  return 0;
}
