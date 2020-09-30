#include <iostream>
#include <ctime>
using namespace std;

// Get a dice
int getDice()
{
  // srand(time(0)); // Why should not be here
  int i1 = 1 + (rand() % 6);
  int i2 = 1 + (rand() % 6);

  //  cout << "You rolled " << i1 << " + " << i2 << " = " << (i1 + i2) << endl;
  return i1 + i2;
}

int main()
{
  srand(time(0)); // Why must be here
  int winCount = 0;
  for (int i = 0; i < 10000; i++)
  {
    int dice = getDice();
    if (dice == 7 || dice == 11)
    {
      //  cout << "You win" << endl;
      winCount++;
      //continue;
    }
    else if (dice == 2 || dice == 3 || dice == 12)
    {
      // cout << "You lose" << endl;
      //continue;
    }
    else
    {
      int point = dice;
      //    cout << "point is " << point << endl;
      do
      {
        dice = getDice();
      }
      while (dice != 7 && dice != point);

      if (dice == 7)
      {
      //  cout << "You lose" << endl;
      }
      else
        winCount++;
      // cout << "You win" << endl;
    }
  }

  cout << "Win count: " << winCount;
}
