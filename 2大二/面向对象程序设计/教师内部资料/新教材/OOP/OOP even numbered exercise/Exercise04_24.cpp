#include <iostream>
#include <string> 
#include <ctime> // for time function
#include <cstdlib> // for rand and srand functions
using namespace std;

int main()
{
  srand(time(0));
  char ch1 = 'A' + rand() % ('Z' - 'A' + 1);
  char ch2 = 'A' + rand() % ('Z' - 'A' + 1);
  char ch3 = 'A' + rand() % ('Z' - 'A' + 1);
  char ch4 = '0' + rand() % 10;
  char ch5 = '0' + rand() % 10;
  char ch6 = '0' + rand() % 10;
  char ch7 = '0' + rand() % 10;

  string vehiclePlateNumber;
  vehiclePlateNumber = vehiclePlateNumber 
    + ch1 + ch2 + ch3 + ch4 + ch5 + ch6 + ch7;

  cout << vehiclePlateNumber << endl;

  return 0;
}