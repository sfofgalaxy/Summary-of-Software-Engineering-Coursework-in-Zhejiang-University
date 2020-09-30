#include <iostream>
using namespace std;

int main()
{
  double scores[100];
  double sum = 0;
  int count = 0;

  do
  {
    cout << "Enter a new score: ";
    cin >> scores[count];
    if (scores[count] >= 0)
      sum += scores[count];
  }
  while (scores[count++] >= 0);

  double average = sum / (count - 1);

  int numOfAbove = 0;
  int numOfBelow = 0;
  for (int i = 0; i < count - 1; i++)
    if (scores[i] >= average)
      numOfAbove++;
    else
      numOfBelow++;

  cout << "Average is " << average << endl;
  cout << "Number of scores above or equal to the average " << numOfAbove << endl;
  cout << "Number of scores below the average " << numOfBelow << endl;

  return 0;
}
