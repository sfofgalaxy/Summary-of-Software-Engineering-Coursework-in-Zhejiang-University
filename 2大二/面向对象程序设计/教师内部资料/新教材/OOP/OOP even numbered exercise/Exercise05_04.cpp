#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  cout << left;
  cout << setw(12) << "Miles" << setw(15) << "Kilometers" << endl;
  cout << "---------------------------------" << endl;

  // Use while loop
  int miles = 1;
  while (miles <= 10)
  {
    cout << fixed << setprecision(3);
    cout << setw(12) << miles << setw(15) << miles * 1.609 << endl;
    miles++;
  }

/** Use for loop
  for (int miles = 1; miles <= 10; miles++)
  {
    cout << fixed << setprecision(3);
    cout << setw(12) << miles << setw(15) << miles * 1.609 << endl;
  }
*/
  return 0;
}
