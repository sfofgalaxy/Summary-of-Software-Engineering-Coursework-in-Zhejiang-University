#include <iostream>
#include <fstream>
#include <ctime>
#include "Loan.h"
using namespace std;

int main()
{
  fstream binaryio; // Create stream object
  binaryio.open("Exercise13_14.dat", ios::out | ios::binary);

  Loan loan1(5.5, 15, 100000.0);
  Loan loan2(6.5, 15, 100000);
  Loan loan3(7.5, 15, 100000);
  Loan loan4(8.5, 15, 100000);
  Loan loan5(9.5, 15, 100000);

  binaryio.write(reinterpret_cast < char * > (& loan1), sizeof(Loan));
  binaryio.write(reinterpret_cast < char * > (& loan2), sizeof(Loan));
  binaryio.write(reinterpret_cast < char * > (& loan3), sizeof(Loan));
  binaryio.write(reinterpret_cast < char * > (& loan4), sizeof(Loan));
  binaryio.write(reinterpret_cast < char * > (& loan5), sizeof(Loan));

  binaryio.close();

  cout << "Done" << endl;

  return 0;
}
