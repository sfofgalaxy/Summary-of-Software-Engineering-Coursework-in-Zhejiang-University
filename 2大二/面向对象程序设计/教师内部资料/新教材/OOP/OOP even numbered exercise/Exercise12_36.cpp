#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool placeADisc(vector<vector<char> > board, int column, char player);
void displayBoard(vector<vector<char> > board);
bool isWon(vector<vector<char> > board);
bool isConsecutiveFour(vector<vector<char> > values);
bool isConsecutiveFour(vector<char> values);

void dropADisc(char player, vector<vector<char> > board)
{
  bool done = false;

  do
  {
    cout << "Drop a " << (player == 'R' ? "red" : "yellow") <<
      " disc at column (0-6): ";
    int column;
    cin >> column;

    if (!placeADisc(board, column, player))
    {
      cout << "This column is full. Try a different column" << endl;
    }
    else
    {
      done = true;
    }
  }
  while (!done);
}

bool placeADisc(vector<vector<char> > board, int column, char player)
{
  for (int i = 0; i < board.size(); i++)
  {
    if (board[i][column] == ' ')
    {
      board[i][column] = player;
      return true; // successful
    }
  }

  return false; // full, unsuccessful
}

void displayBoard(vector<vector<char> > board)
{
  for (int i = board.size() - 1; i >= 0; i--)
  {
    cout << "|";
    for (int j = 0; j < board[i].size(); j++)
      cout << (board[i][j] != ' ' ?  board[i][j] + "|": " |");
    cout << endl;
  }
  cout << "----------------------" << endl;
}

bool isWon(vector<vector<char> > board)
{
  return isConsecutiveFour(board);
}

bool isDraw(vector<vector<char> > board)
{
  for (int i = 0; i < board.size(); i++)
    for (int j = 0; j < board[i].size(); j++)
      if (board[i][j] == ' ') return false;

  return true; // All cells are now occupied
}

bool isConsecutiveFour(vector<vector<char> > values)
{
  int numberOfRows = values.size();
  int numberOfColumns = values[0].size();

  // Check rows
  for (int i = 0; i < numberOfRows; i++) {
    if (isConsecutiveFour(values[i]))
      return true;
  }

  // Check columns
  for (int j = 0; j < numberOfColumns; j++) {
    vector<char> column(numberOfRows);
    // Get a column into an array
    for (int i = 0; i < numberOfRows; i++)
      column[i] = values[i][j];

    if (isConsecutiveFour(column))
      return true;
  }

  // Check major diagonal (lower part)
  for (int i = 0; i < numberOfRows - 3; i++) {
    int numberOfElementsInDiagonal
      = min(numberOfRows - i, numberOfColumns);
    vector<char> diagonal(numberOfElementsInDiagonal);
    for (int k = 0; k < numberOfElementsInDiagonal; k++)
      diagonal[k] = values[k + i][k];

    if (isConsecutiveFour(diagonal))
      return true;
  }

  // Check major diagonal (upper part)
  for (int j = 1; j < numberOfColumns - 3; j++) {
    int numberOfElementsInDiagonal
      = min(numberOfColumns - j, numberOfRows);
    vector<char> diagonal(numberOfElementsInDiagonal);
    for (int k = 0; k < numberOfElementsInDiagonal; k++)
      diagonal[k] = values[k][k + j];

    if (isConsecutiveFour(diagonal))
      return true;
  }

  // Check sub-diagonal (left part)
  for (int j = 3; j < numberOfColumns; j++) {
    int numberOfElementsInDiagonal
      = min(j + 1, numberOfRows);
    vector<char> diagonal(numberOfElementsInDiagonal);

    for (int k = 0; k < numberOfElementsInDiagonal; k++)
      diagonal[k] = values[k][j - k];

    if (isConsecutiveFour(diagonal))
      return true;
  }

  // Check sub-diagonal (right part)
  for (int i = 1; i < numberOfRows - 3; i++) {
    int numberOfElementsInDiagonal
      = min(numberOfRows - i, numberOfColumns);
    vector<char> diagonal(numberOfElementsInDiagonal);

    for (int k = 0; k < numberOfElementsInDiagonal; k++)
      diagonal[k] = values[k + i][numberOfColumns - k - 1];

    if (isConsecutiveFour(diagonal))
      return true;
  }

  return false;
}

bool isConsecutiveFour(vector<char> values)
{
  for (int i = 0; i < values.size() - 3; i++)
  {
    bool isEqual = true;
    for (int j = i; j < i + 3; j++) {
      if (values[j] == '\u0000' || values[j] != values[j + 1]) {
        isEqual = false;
        break;
      }
    }

    if (isEqual) return true;
  }

  return false;
}

int main()
{
  vector<vector<char> > board(6);
  for (int i = 0; i < board.size(); i++)
  {
    board[i] = vector<char>(7);
    for (int j = 0; j < 7; j++)
      board[i][j] = ' ';
  }

  displayBoard(board);

  while (true)
  {
    // Prompt the first player
    dropADisc('R', board);

    displayBoard(board);
    if (isWon(board))
    {
      cout << "The red player won" << endl;
      return 0;
    }
    else if (isDraw(board)) {
      cout << "No winner" << endl;
      return 0;
    }

    // Prompt the second player
    dropADisc('Y', board);
    displayBoard(board);

    if (isWon(board)) {
      cout << "The yellow player won" << endl;
      return 0;
    }
    else if (isDraw(board)) {
      cout << "No winner" << endl;
      return 0;
    }
  }

  return 0;
}
