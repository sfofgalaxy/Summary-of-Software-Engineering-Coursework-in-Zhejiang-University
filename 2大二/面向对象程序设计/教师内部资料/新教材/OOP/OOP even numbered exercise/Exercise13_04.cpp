#include <iostream>
#include <fstream>
using namespace std;

void selectionSort(int list[], int arraySize)
{
  for (int i = arraySize - 1; i >= 1; i--)
  {
    // Find the maximum in the list[0..i]
    int currentMax = list[0];
    int currentMaxIndex = 0;

    for (int j = 1; j <= i; j++)
    {
      if (currentMax < list[j])
      {
        currentMax = list[j];
        currentMaxIndex = j;
      }
    }

    // Swap list[i] with list[currentMaxIndex] if necessary;
    if (currentMaxIndex != i)
    {
      list[currentMaxIndex] = list[i];
      list[i] = currentMax;
    }
  }
}

int main()
{
  ifstream input;

  // Open a file
  input.open("Exercise13_4.txt");

  int numbers[100];
  int i = 0;
  while (!input.eof()) // Continue if not end of file
  {
    input >> numbers[i];
    i++;
  }
  input.close();

  selectionSort(numbers, 100);

  for (int i = 0; i < 100; i++)
    cout << numbers[i] << endl;

  ofstream output("Exercise13_4.txt");

  for (int i = 0; i < 100; i++)
    output << numbers[i] << " ";

  output.close();
  cout << "Done" << endl;

  return 0;
}
