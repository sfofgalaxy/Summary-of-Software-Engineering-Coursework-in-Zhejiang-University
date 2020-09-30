#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream input;

  // Open a file
  input.open("Exercise13_1.txt");

  if (input.fail())
  {
    cout << "File does not exist" << endl;
    cout << "Exit program" << endl;
    return 0;
  }

  int count = 0;

  while (!input.eof()) // Continue if not end of file
  {
    input.get();
    count++;
   }

  count--; // adjust count since it was increased after the last character was read

  input.close();

  cout << "Number of characters is " << count << endl;
  return 0;
}
