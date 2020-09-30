#include <iostream>
#include <cmath>
using namespace std;

/** Compute the distance between two points (x1, y1) and (x2, y2) */
double getDistance(double x1, double y1, double x2, double y2)
{
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main()
{
  const int NUMBER_OF_POINTS = 8;

  // Each row in points represents a point
  double points[NUMBER_OF_POINTS][2];

  cout << "Enter " << NUMBER_OF_POINTS << " points: ";
  for (int i = 0; i < NUMBER_OF_POINTS; i++)
    cin >> points[i][0] >> points[i][1];

  // p1 and p2 are the indices in the points array
  int p1 = 0, p2 = 1; // Initial two points
  double shortestDistances = getDistance(points[p1][0], points[p1][1],
    points[p2][0], points[p2][1]); // Initialize shortestDistances

  // Store a closest pair in (indices[i][0], indices[i][1])
  // The pair of the points for (indices[i][0], indices[i][1]) is
  // points[indices[i][0]] and points[indices[i][1]]
  int indices[NUMBER_OF_POINTS][2];
  int k = 0;
  indices[k][0] = p1;
  indices[k][1] = p2;

  // Compute distance for every two points
  for (int i = 0; i < NUMBER_OF_POINTS; i++)
  {
    for (int j = i + 1; j < NUMBER_OF_POINTS; j++)
    {
      double distance = getDistance(points[i][0], points[i][1],
        points[j][0], points[j][1]); // Find distance

      if (shortestDistances > distance)
      {
        // Add a closest pair
        k = 0;
        indices[k][0] = i;
        indices[k][1] = j;
        shortestDistances = distance; // Update shortestDistances
      }
      else if (distance == shortestDistances)
      {
        // Add another closest pair with the same minimum distance
        k++;
        indices[k][0] = i;
        indices[k][1] = j;
      }
    }
  }

  // Display all closest pairs
  for (int i = 0; i <= k; i++) {
    p1 = indices[i][0]; p2 = indices[i][1];
    cout << "The closest two points are " <<
      "(" << points[p1][0] << ", " << points[p1][1] << ") and (" <<
      points[p2][0] << ", " << points[p2][1] << ")" << endl;
  }

  cout << "Their distance is " << shortestDistances << endl;

  return 0;
}
