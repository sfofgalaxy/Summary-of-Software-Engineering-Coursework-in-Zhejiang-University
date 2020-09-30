#include <iostream>
#include <cctype>
using namespace std;

int main()
{
  cout << "Enter a letter grade: ";
  char grade;
  cin >> grade;

  int value;
  if (toupper(grade) == 'A')
    value = 4;
  else if (toupper(grade) == 'B')
    value = 3;
  else if (toupper(grade) == 'C')
    value = 2;
  else if (toupper(grade) == 'D')
    value = 1;
  else if (toupper(grade) == 'F')
    value = 0;
  else {
    cout << grade << " is an invalid grade" << endl;
    exit(1);
  }

  cout << "The numeric value for grade " << grade 
    << " is " << value << endl;

  return 0;
}