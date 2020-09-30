#include <iostream>
using namespace std;

int main()
{
  cout << "Enter three edges: ";
  double edge1, edge2, edge3;
  cin >> edge1 >> edge2 >> edge3;

  bool isValid = (edge1 + edge2 > edge3) &&
    (edge1 + edge3 > edge2) && (edge3 + edge2 > edge1);

  // Display results
  if (!isValid)
    cout << "The input is invalid" << endl;
  else
  {
    cout << "The perimeter is " << (edge1 + edge2 + edge3) << endl;
  }

  return 0;
}
