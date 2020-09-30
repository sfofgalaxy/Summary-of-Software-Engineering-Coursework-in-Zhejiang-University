#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  fstream binaryio; // Create stream object

  // Open file for input and output
  binaryio.open("Exercise13_13.dat", ios::in | ios::out | ios::binary);

  int value = 0;
  binaryio.read(reinterpret_cast < char * > (& value), sizeof(value));
  value++;

  binaryio.seekp(0);

  binaryio.write(reinterpret_cast < char * > (& value), sizeof(value));

  cout << "This program has been executed " << value << " times" << endl;

  binaryio.close();
  return 0;
}
