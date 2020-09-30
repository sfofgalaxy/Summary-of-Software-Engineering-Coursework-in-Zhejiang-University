#include <iostream>
using namespace std;

int main()
{
  cout << "Enter an integer: ";
  int value;
  cin >> value;

  if (value % 5 == 0 && value % 6 == 0)
    cout << "Is " << value << " divisible by 5 and 6? true" << endl;
  else
    cout << "Is " << value << " divisible by 5 and 6? false" << endl;

  if (value % 5 == 0 || value % 6 == 0)
    cout << "Is " << value << " divisible by 5 or 6? true" << endl;
  else
    cout << "Is " << value << " divisible by 5 or 6? false" << endl;

  if ((value % 5 == 0 && value % 6 != 0) ||
     (value % 5 != 0 && value % 6 == 0))
    cout << "Is " << value << " divisible by 5 or 6, but not both? true" << endl;
  else
    cout << "Is " << value << " divisible by 5 or 6, but not both? false" << endl;
}
