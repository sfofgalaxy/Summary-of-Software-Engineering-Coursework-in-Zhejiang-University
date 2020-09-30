#include <iostream>
#include <vector>
using namespace std;

class Location
{
public: 
  Location(int r, int c, double m)
  {
    row = r;
	column = c;
	maxValue = m;
  }
  int row;
  int column;
  double maxValue;
};

Location locateLargest(const vector<vector<double> > v)
{
  int row = 0;
  int column = 0;
  double maxValue = v[0][0];

  for (unsigned int i = 0; i < v.size(); i++)
    for (unsigned int j = 0; j < v[i].size(); j++)
      if (maxValue < v[i][j]) {
	    row = i;
		column = j;
	    maxValue = v[i][j];
	  }

  return Location(row, column, maxValue);
}

int main()
{
  int rowSize, columnSize;
  cout << "Enter the number of rows and columns:";
  cin >> rowSize >> columnSize;

  vector<vector<double> > v(rowSize);

  // Enter the two-dimensional array
  cout << "Enter a 3 by 4 two-dimensional array:";
  for (int i = 0; i < rowSize; i++)
  {
    v[i] = vector<double>(columnSize);
    for (int j = 0; j < columnSize; j++)
      cin >> v[i][j];
  }
 
  Location loc = locateLargest(v);
  
  cout << "The location of the largest element is " <<
  loc.maxValue << " at (" << loc.row << ", " << loc.column << ")" << endl;
 
  return 0;
}