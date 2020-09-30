#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

template <typename InputIterator, typename T>
InputIterator find(InputIterator beg, InputIterator end, T &value);

template <typename InputIterator, typename T>
InputIterator find(InputIterator beg, InputIterator end, T &value)
{
   for (InputIterator p = beg; p != end; p++)
   {
     if (*p == value) return p;
   }

   return end;
}

template <typename InputIterator, typename boolFunction>
InputIterator find_if(InputIterator beg, InputIterator end,
  boolFunction f);

template <typename InputIterator, typename boolFunction>
InputIterator find_if(InputIterator beg, InputIterator end,
  boolFunction f)
{
  for (InputIterator p = beg; p != end; p++)
  {
    if (f(*p)) return p;
  }

  return end;
}

bool greaterThan4(double value)
{
  return value > 4;
}

int main()
{
  double values[] = {1, 2, 3, 55, 41, 4};

  ostream_iterator<double> output(cout, " ");
  cout << "Initial contents, values: ";
  copy(values, values + 6, output);

  double *p = find(values, values + 6, 4);
  if (p != values + 6)
    cout << "\nfound at position " << (p - values);
  else
    cout << "\nnot found";

  double *p1 = find_if(values, values + 6, greaterThan4);
  if (p1 != values + 6)
    cout << "\nfound at position " << (p1 - values);
  else
    cout << "\nnot found";

  return 0;
}
