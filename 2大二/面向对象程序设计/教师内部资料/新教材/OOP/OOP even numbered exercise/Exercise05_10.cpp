#include <iostream>
#include <string>
using namespace std;

int main()
{
  // Prompt the user to enter the number of students
  cout << "Enter the number of students: ";
  int numberOfStudents;
  cin >> numberOfStudents;

  double score = -1;
  string name;

  for (int i = 0; i < numberOfStudents; i++)
  {
    cout << "Enter the name of the student: ";
    string name1;
    cin >> name1;
    
    cout << "Enter a student score: ";
    int score1;
    cin >> score1;

    if (score < score1)
    {
      name = name1;
      score = score1;
    }
  }

  cout << "Student " << name << " has the highest score is " << score << endl;

  return 0;
}
