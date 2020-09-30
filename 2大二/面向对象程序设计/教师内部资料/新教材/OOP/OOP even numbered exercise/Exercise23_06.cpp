#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <set>
#include <list>
using namespace std;

bool lessThan2(double value)
{
  return value < 2;
}

bool greaterThan4(double value)
{
  return value > 4;
}

bool condition(double value)
{
  return value > 1.3;
}

int main()
{
  double values[] = {2.4, 1.3, 2.4, 2.4, 4.5, 6.7, 4.5, 9.0};

  ostream_iterator<double> output(cout, " ");
  cout << "Initial contents, values: ";
  copy(values, values + 8, output);

  double array2[] = {2.4, 4.5};
  double *p = search(values, values + 8, array2, array2 + 2);
  if (p != values + 8)
    cout << "\nfound at position " << (p - values);
  else
    cout << "\nnot found";

  double *p1 = search_n(values, values + 8, 2, 2.4);
  if (p1 != values + 8)
    cout << "\nfound at position " << (p1 - values);
  else
    cout << "\nnot found";

  return 0;
}
