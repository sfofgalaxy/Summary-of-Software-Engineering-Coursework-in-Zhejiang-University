#include <iostream>
using namespace std;

bool isWon(char ch, char board[][3])
{
  // Check rows
  for (int i = 0; i < 3; i++)
    if (ch == board[i] [0] && ch == board[i] [1] && ch == board[i] [2]) return true;

  // Check columns
  for (int j = 0; j < 3; j++)
    if (ch == board[0] [j] && ch == board[1] [j] && ch == board[2] [j]) return true;

  // Check majoe diagonal
  if (ch == board[0] [0] && ch == board[1] [1] && ch == board[2] [2]) return true;

  // Check sub diagonal
  if (ch == board[0] [2] && ch == board[1] [1] && ch == board[2] [0]) return true;

  return false;
}

bool isDraw(char board[][3])
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (board[i] [j] == ' ') return false;

  return true;
}

void displayBoard(char board[] [3])
{
  cout << "\n-------------" << endl;

  for (int i = 0; i < 3; i++)
  {
    cout << "| " ;
    for (int j = 0; j < 3; j++)
      cout << board[i][j] << " | ";
    cout << "\n-------------" << endl;
  }
}

void makeAMove(char board[][3], char player)
{
  bool done = false;

  do {
    // Prompt the first player
    cout << "Enter a row (0, 1, 2) for player " << player << ": ";
    int row;
    cin >> row;

    cout << "Enter a column (0, 1, 2) for player " << player << ": ";
    int column;
    cin >> column;

    if (board[row][column] == ' ')
    { // an empty cell
      board[row][column] = player;
      done = true;
    }
    else
      cout << "This cell is already occupied. Try a different cell" << endl;
  }
  while (!done);
}

int main()
{
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  displayBoard(board);

  while (true)
  {
    // The first player makes a move
    makeAMove(board, 'X');
    displayBoard(board);
    if (isWon('X', board))
    {
      cout << "X player won" << endl;
      exit(0);
    }
    else if (isDraw(board))
    {
      cout << "No winner" << endl;
      exit(0);
    }

    // The second player makes a move
    makeAMove(board, 'O');
    displayBoard(board);

    if (isWon('O', board))
    {
      cout << "O player won" << endl;
      exit(0);
    }
    else if (isDraw(board))
    {
      cout << "No winner" << endl;
      exit(0);
    }
  }

  return 0;
}

