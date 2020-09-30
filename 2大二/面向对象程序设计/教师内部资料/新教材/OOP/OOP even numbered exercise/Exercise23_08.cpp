#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

template <typename forwardIterator, typename T>
void fill(forwardIterator beg, forwardIterator end, const T &value);

template <typename forwardIterator, typename T>
void fill(forwardIterator beg, forwardIterator end, const T &value)
{
  for (forwardIterator p = beg; p < end; p++)
  {
    *p = value;
  }
}

template <typename forwardIterator, typename size, typename T>
void fill_n(forwardIterator beg, int n, const T &value);

template <typename forwardIterator, typename size, typename T>
void fill_n(forwardIterator beg, int n, const T &value)
{
  for (forwardIterator p = beg; p < beg + n; p++)
  {
    *p = value;
  }
}

int main()
{
  double values[] = {2.4, 1.3, 2.4, 2.4, 4.5, 6.7, 4.5, 9.0};

  ostream_iterator<double> output(cout, " ");
  cout << "Initial contents, values: ";
  copy(values, values + 8, output);

  fill_n(values, 2, 5.6);

  cout << "\nAfter fill, values: ";
  copy(values, values + 8, output);

  return 0;
}
