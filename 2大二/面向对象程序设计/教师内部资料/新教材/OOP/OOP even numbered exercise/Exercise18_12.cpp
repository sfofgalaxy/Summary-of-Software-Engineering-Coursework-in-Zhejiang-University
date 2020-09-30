#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int count = 0; // Count the number of prime numbers

  fstream input;
  input.open("Exercise18_7.dat", ios::in | ios::binary);

  long limits[] = {
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000};
  int k = 0;

  while (!input.eof()) {
    long number;
    input.read(reinterpret_cast<char*>(&number), sizeof(long));

    if (number > limits[k]) {
      cout << "Number of prime number <= " << limits[k]
        << " is " << count << endl;
      k++;
    }
    count++;
  }

  input.close();
  cout << "Total number of prime numbers found: " <<
    count;

  return 0;
}
