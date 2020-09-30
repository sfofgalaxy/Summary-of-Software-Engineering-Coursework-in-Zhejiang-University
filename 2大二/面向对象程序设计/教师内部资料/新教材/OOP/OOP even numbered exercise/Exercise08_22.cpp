#include <iostream>
using namespace std;

bool isConsecutiveFour(char values[][7]); 
bool isConsecutiveFour(char values[], int size);
bool isDraw(char board[][7]); 
bool isWon(char board[][7]);
void dropADisc(char player, char board[][7]);
bool placeADisk(char board[][7], int column, char player);
void displayBoard(char board[][7]);

const int numberOfRows = 6;
const int numberOfColumns = 7;
const int maxNumberOfElementsInDiagonal = 10;

int main()
{
  char board[6][7];

  for (int i = 0; i < numberOfRows; i++)
    for (int j = 0; j < numberOfColumns; j++)
	  board[i][j] = ' ';

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
    else if (isDraw(board)) 
	{
   	  cout << "No winner" << endl;
	  return 0;
	}

	// Prompt the second player
	dropADisc('Y', board);
	displayBoard(board);

	if (isWon(board)) 
	{
	  cout << "The yellow player won" << endl;
	  return 0;
	}
	else if (isDraw(board)) 
	{
	  cout << "No winner" << endl;
	  return 0;
	}
  }
}

void dropADisc(char player, char board[][7]) 
{ 
  bool done = false;
    
  do 
  {
    cout << "Drop a " << (player == 'R' ? "red" : "yellow") <<
	  " disk at column (0-6): ";
    int column;
	cin >> column;
	  
    if (placeADisk(board, column, player)) 
	{ 
      done = true;
    }
    else
      cout << "This column is full. Try a different column" << endl;
  }
  while (!done);
}
  
bool placeADisk(char board[][7], int column, char player)
{
  for (int i = 0; i < numberOfRows; i++) 
  {
      if (board[i][column] == ' ') {
        board[i][column] = player; 
        return true; // successful
      }
    }
    
    return false; // full, unsuccessful
  }
  
void displayBoard(char board[][7]) 
{
  for (int i = numberOfRows - 1; i >= 0; i--) 
  {
    cout << "|";
    for (int j = 0; j < numberOfColumns; j++)
      if (board[i][j] != ' ')
        cout << board[i][j] << "|";
	  else
	    cout << " |";
    cout << endl;
  }
  cout << "----------------------" << endl;
}

bool isWon(char board[][7]) 
{
  return isConsecutiveFour(board);
}

bool isDraw(char board[][7]) 
{
  for (int i = 0; i < numberOfRows; i++)
    for (int j = 0; j < numberOfColumns; j++)
      if (board[i][j] == ' ') return false;

  return true; // All cells are now occupied
}

bool isConsecutiveFour(char values[][7]) 
{
  // Check rows
  for (int i = 0; i < numberOfRows; i++) 
  {
    if (isConsecutiveFour(values[i], numberOfRows))
  	  return true;
  }

  // Check columns
  for (int j = 0; j < numberOfColumns; j++) 
  {
    char column[numberOfRows];
    // Get a column into an array
    for (int i = 0; i < numberOfRows; i++)
	  column[i] = values[i][j];
	  
	if (isConsecutiveFour(column, numberOfRows))
	  return true;
  }
    
  // Check major diagonal (lower part)   
  for (int i = 0; i < numberOfRows - 3; i++) 
  {
    int numberOfElementsInDiagonal 
      = min(numberOfRows - i, numberOfColumns);     
    char diagonal[maxNumberOfElementsInDiagonal];
    for (int k = 0; k < numberOfElementsInDiagonal; k++)
      diagonal[k] = values[k + i][k];
  
    if (isConsecutiveFour(diagonal, numberOfElementsInDiagonal))
      return true;
  }

  // Check major diagonal (upper part)
  for (int j = 1; j < numberOfColumns - 3; j++) 
  {
    int numberOfElementsInDiagonal 
      = min(numberOfColumns - j, numberOfRows);     
    char diagonal[maxNumberOfElementsInDiagonal];
    for (int k = 0; k < numberOfElementsInDiagonal; k++)
      diagonal[k] = values[k][k + j];
  
    if (isConsecutiveFour(diagonal, numberOfElementsInDiagonal))
      return true;
  }

  // Check sub-diagonal (left part)
  for (int j = 3; j < numberOfColumns; j++)
  {
    int numberOfElementsInDiagonal = min(j + 1, numberOfRows);     
    char diagonal[maxNumberOfElementsInDiagonal];
  
    for (int k = 0; k < numberOfElementsInDiagonal; k++)
      diagonal[k] = values[k][j - k];
  
    if (isConsecutiveFour(diagonal, numberOfElementsInDiagonal))
      return true;
  }

  // Check sub-diagonal (right part)
  for (int i = 1; i < numberOfRows - 3; i++) {
    int numberOfElementsInDiagonal 
      = min(numberOfRows - i, numberOfColumns);     
    char diagonal[maxNumberOfElementsInDiagonal];

    for (int k = 0; k < numberOfElementsInDiagonal; k++)
      diagonal[k] = values[k + i][numberOfColumns - k - 1];

    if (isConsecutiveFour(diagonal, numberOfElementsInDiagonal))
      return true;
  }

  return false; 
}

bool isConsecutiveFour(char values[], int size) 
{    
  for (int i = 0; i < size - 3; i++)
  {
    bool isEqual = true;        
    for (int j = i; j < i + 3; j++) 
	{
      if (values[j] == ' ' || values[j] != values[j + 1]) 
	  {
        isEqual = false;
        break;
      }
    }
 
    if (isEqual) return true;
  }

  return false;
}