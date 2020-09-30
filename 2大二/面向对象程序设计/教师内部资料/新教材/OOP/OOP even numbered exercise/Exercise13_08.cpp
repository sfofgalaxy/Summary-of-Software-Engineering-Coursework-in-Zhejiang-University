#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<string> names;

void readNames() 
{
  for (int i = 0; i < 10; i++) 
  {
    string filename;
    if (i == 9)
      filename = "C:\\cplusplusexercise\\Babynamesranking2010.txt";
    else
    {
      filename += "C:\\cplusplusexercise\\Babynamesranking200";
      filename += static_cast<char>((i + 1) + '0');
      filename += ".txt";
    }

    ifstream input(filename.c_str());
        
    int j = 0;
    while (!input.eof()) // (int j = 0; j < 1000; j++)
    {
      int dummy;
      input >> dummy; // Skip the ranking
      string name;
      input >> name;
      names.push_back(name);
      input >> dummy; // Skip the number of boy's name
      input >> name;
      names.push_back(name);
      input >> dummy; // Skip the number of girl's name
      j++;
    }

    input.close();
  }
}

template<typename T>
void sort(vector<T>& list)
{
  for (int i = 0; i < list.size(); i++) 
  {
    // Find the minimum in the list[i..listSize-1]
    T currentMin = list[i];
    int currentMinIndex = i;

    for (int j = i + 1; j < list.size(); j++) 
    {
      if (currentMin > list[j]) 
      {
        currentMin = list[j];
        currentMinIndex = j;
      }
    }

    // Swap list[i] with list[currentMinIndex] if necessary;
    if (currentMinIndex != i) 
    {
      list[currentMinIndex] = list[i];
      list[i] = currentMin;
    }
  }
}

void writeNames() 
{
  string filename = "C:\\cplusplusexercise\\BabynamesSortedDuplicatesAllowed.txt";
  ofstream output(filename.c_str());

  for (int i = 1; i <= names.size(); i++) 
  {
    if (i % 10 == 0)
      output << names[i - 1] << endl; 
    else
      output << names[i - 1] << " "; 
  }
}

int main()
{
  readNames();
  sort(names); // This may take a long time to sort
  writeNames();

  return 0;
}
