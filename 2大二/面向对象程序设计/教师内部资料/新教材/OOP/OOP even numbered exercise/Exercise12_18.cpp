#include <iostream>
#include <vector>
#include <string>
#include "ImprovedStack.h"
using namespace std;

string infixToPostfix(const string &expression);

// Split an expression into numbers, operators, and parenthese
vector<string> split(const string &expression);

int main()
{
  // Enter the express as a string
  string expression;
  cout << "Enter an expression: ";
  getline(cin, expression, '\n');
  cout << infixToPostfix(expression) << endl;
}

string infixToPostfix(const string &expression)
{
  // Result string
  string s = "";

  // Create operandStack to store operands
  Stack<int> operandStack;

  // Create operatorStack to store operators
  Stack<char> operatorStack;

  // Extract operands and operators
  vector<string> tokens = split(expression);

  // Phase 1: Scan tokens
  // Phase 1: Scan tokens
  for (unsigned i = 0; i < tokens.size(); i++)
  {
    if (tokens[i][0] == '+' || tokens[i][0] == '-')
    {
      // Process all +, -, *, / in the top of the operator stack
      while (!operatorStack.empty() && (operatorStack.peek() == '+'
       || operatorStack.peek() == '-' || operatorStack.peek() == '*'
       || operatorStack.peek() == '/'))
	  {
        s.append(1, operatorStack.pop());
		s.append(" ");
      }

      // Push the + or - operator into the operator stack
      operatorStack.push(tokens[i][0]);
    }
    else if (tokens[i][0] == '*' || tokens[i][0] == '/')
	{
        // Process all *, / in the top of the operator stack
      while (!operatorStack.empty() && (operatorStack.peek() == '*'
        || operatorStack.peek() == '/'))
      {
        s.append(1, operatorStack.pop());
		s.append(" ");
      }

      // Push the * or / operator into the operator stack
      operatorStack.push(tokens[i][0]);
    }
    else if (tokens[i][0] == '(')
    {
      operatorStack.push('('); // Push '(' to stack
    }
    else if (tokens[i][0] == ')')
    {
      // Process all the operators in the stack until seeing '('
      while (operatorStack.peek() != '(')
      {
        s.append(1, operatorStack.pop());
		s.append(" ");
      }

      operatorStack.pop(); // Pop the '(' symbol from the stack
    }
    else 
	{ // An operand scanned
      s.append(tokens[i]);
	  s.append(" ");
    }
  }

  // Phase 2: process all the remaining operators in the stack
  while (!operatorStack.empty())
  {
    s.append(1, operatorStack.pop());
	s.append(" ");
  }

  // Return the result
  return s;
}

vector<string> split(const string &expression)
{
  vector<string> v; // A vector to store split items as strings
  string numberString; // A numeric string

  for (unsigned i = 0; i < expression.length(); i++)
  {
    if (isdigit(expression[i]))
      numberString.append(1, expression[i]); // Append a digit
    else
    {
      if (numberString.size() > 0)
      {
        v.push_back(numberString); // Store the numeric string
        numberString.erase(); // Empty the numeric string
      }

      if (!isspace(expression[i]))
      {
        string s;
        s.append(1, expression[i]);
        v.push_back(s); // Store an operator and parenthese
      }
    }
  }

  // Store the last numeric string
  if (numberString.size() > 0)
    v.push_back(numberString);

  return v;
}