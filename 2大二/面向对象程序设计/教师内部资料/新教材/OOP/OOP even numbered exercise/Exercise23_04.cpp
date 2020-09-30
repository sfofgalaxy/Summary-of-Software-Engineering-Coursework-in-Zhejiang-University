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
  double values[] = {2.4, 1.3, 2.4, 4.5, 6.7, 4.5, 9.0};

  ostream_iterator<double> output(cout, " ");
  cout << "Initial contents, values: ";
  copy(values, values + 7, output);

  replace(values, values + 7, 2.4, 9.9);
  cout << "\nAfter the replace function, values: ";
  copy(values, values + 7, output);

  replace_if(values, values + 7, lessThan2, 12.5);
  cout << "\nAfter the replace_if function, v: ";
  copy(values, values + 7, output);

  vector<double> v(7);
  replace_copy(values, values + 7, v.begin(), 6.7, 9.7);
  cout << "\nAfter the replace_copy function, v: ";
  copy(v.begin(), v.end(), output);

  vector<double> s(values, values + 7);
  replace_copy_if(values, values + 7, s.begin(), condition, 747);
  cout << "\nAfter the replace_copy function, s: ";
  copy(s.begin(), s.end(), output);

  return 0;
}
