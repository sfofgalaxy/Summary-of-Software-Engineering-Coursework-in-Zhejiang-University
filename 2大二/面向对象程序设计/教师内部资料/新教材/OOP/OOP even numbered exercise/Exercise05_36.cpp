#include <iostream>
#include <ctime>
using namespace std;

int main()
{
  // Generate a random number to be guessed
  srand(time(0));

  int count = 0;
  while (count <= 2 || count <= -2)
  {
    // Generate scissor, rock, paper
    int computerNumber = rand() % 3;

    // Prompt the user to enter scissor, rock, or paper
    cout << "scissor (0), rock (1), paper (2): ";
    int userNumber;
    cin >> userNumber;

    // Check the guess
    switch (computerNumber)
    {
      case 0:
        if (userNumber == 0)
        {
          cout << "It is a draw" << endl;
        }
        else if (userNumber == 1)
        {
          cout << "You won" << endl;
          count++;
        }
        else if (userNumber == 2)
        {
          cout << "You lost" << endl;
          count--;
        }
      break;
      case 1:
        if (userNumber == 0)
        {
          cout << "You lost" << endl;
          count--;
        }
        else if (userNumber == 1)
        {
          cout << "It is a draw" << endl;
        }
        else if (userNumber == 2)
        {
          cout << "You won" << endl;
          count++;
        }
      break;
      case 2:
        if (userNumber == 0)
        {
          cout << "You won" << endl;
          count++;
        }
        else if (userNumber == 1)
        {
          cout << "You lost" << endl;
          count--;
        }
        else if (userNumber == 2)
        {
          cout << "It is a draw" << endl;
        }
      break;
    }
  }

  if (count > 2)
  {
    cout << "You won more than two times" << endl;
  }
  else
  {
    cout << "The computer won more than two times" << endl;
  }

  return 0;
}
