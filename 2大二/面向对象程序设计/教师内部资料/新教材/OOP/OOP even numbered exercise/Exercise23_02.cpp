#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
using namespace std;

int nextNum()
{
  srand(time(0));
  return rand();
}

int main()
{
  double values[] = {1.3, 2.4, 4.5, 6.7, 9.0};
  deque<double> doubleDeque(values, values + 5);
  deque<double> doubleDeque1(values, values + 5);

  ostream_iterator<int> output(cout, " ");
  cout << "Initial contents, values: ";
  copy(values, values + 5, output);
  cout << "\nInitial contents, intList: ";
  copy(doubleDeque.begin(), doubleDeque.end(), output);

  generate(doubleDeque.begin(), doubleDeque.end(), nextNum);
  cout << "\nAfter the generate function, deque: ";
  copy(doubleDeque.begin(), doubleDeque.end(), output);

  generate_n(doubleDeque1.begin(), 2, nextNum);
  cout << "\nAfter the generate_n function, deque: ";
  copy(doubleDeque1.begin(), doubleDeque1.end(), output);

  return 0;
}
