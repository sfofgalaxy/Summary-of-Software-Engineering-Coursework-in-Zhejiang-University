#include <iostream>
#include <vector>
using namespace std;

void displayPoints(const vector<vector<double> > points)
{
  for (int i = 0; i < points.size(); i++)
    cout << "(" << points[i][0] << ", " << points[i][1] << ") ";

  cout << endl;
}

bool sameLine(vector<vector<double> > points)
{
  if (points.size() < 2) return true;

  double slope = (points[0][0] - points[1][0]) /
    (points[0][1] - points[1][1]);
  for (int i = 3; i < points.size(); i++)
  {
    double slope1 = (points[i][0] - points[1][0]) /
      (points[i][1] - points[1][1]);

    if (slope != slope1) return false;
  }

  return true;
}

int main()
{
  vector<vector<double> > set1 = vector<vector<double> >(4);
  set1[0] = vector<double>(2);
  set1[0][0] = 1;  set1[0][1] = 1;
  set1[1] = vector<double>(2);
  set1[1][0] = 2;  set1[1][1] = 2;
  set1[2] = vector<double>(2);
  set1[2][0] = 3;  set1[2][1] = 3;
  set1[3] = vector<double>(2);
  set1[3][0] = 4;  set1[3][1] = 4;

  vector<vector<double> > set2 = vector<vector<double> >(4);
  set1[0] = vector<double>(2);
  set1[0][0] = 0;  set1[0][1] = 1;
  set1[1] = vector<double>(2);
  set1[1][0] = 1;  set1[1][1] = 2;
  set1[2] = vector<double>(2);
  set1[2][0] = 4;  set1[2][1] = 5;
  set1[3] = vector<double>(2);
  set1[3][0] = 5;  set1[3][1] = 6;

  vector<vector<double> > set3 = vector<vector<double> >(4);
  set1[0] = vector<double>(2);
  set1[0][0] = 0;  set1[0][1] = 1;
  set1[1] = vector<double>(2);
  set1[1][0] = 1;  set1[1][1] = 2;
  set1[2] = vector<double>(2);
  set1[2][0] = 4;  set1[2][1] = 5;
  set1[3] = vector<double>(2);
  set1[3][0] = 4.5;  set1[3][1] = 4;

  displayPoints(set1);
  cout << "same line? " << sameLine(set1) << endl;

  displayPoints(set2);
  cout << "same line? " << sameLine(set2) << endl;

  displayPoints(set3);
  cout << "same line? " << sameLine(set3) << endl;

  return 0;
}
