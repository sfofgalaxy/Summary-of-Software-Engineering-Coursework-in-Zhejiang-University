#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

string names[10][2][5];

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
        
    for (int j = 0; j < 5; j++) 
    {
      int dummy;
      input >> dummy; // Skip the ranking
      input >> names[i][0][j];
      input >> dummy; // Skip the number of boy's name
      input >> names[i][1][j];
      input >> dummy; // Skip the number of girl's name
    }
  }
}

void displayRankingSummary()
{
  cout << setw(5) << "Year";

  for (int i = 1; i <= 5; i++)
    cout << setw(10) << "Rank " << i;

  for (int i = 1; i <= 5; i++)
    cout << setw(10) << "Rank " << i;
    
  cout << endl;
    
  for (int i = 9; i >= 0; i--) 
  {
    cout << setw(5) << 2001 + i;
    for (int j = 1; j >= 0; j--)
      for (int k = 0; k < 5; k++)
        cout << setw(10) << names[i][j][k];
    cout << endl;
  }
}

int main()
{
  readNames();
  displayRankingSummary();

  return 0;
}
