#include <iostream>
#include <string>
using namespace std;

int hashCode(const string& s, int b);

int main()
{
  cout << "Enter a string s: ";
  string s;
  getline(cin, s);

  cout << "Enter an integer b: ";
  int b;
  cin >> b;
  
  cout << "The hashCode for " << s << " is " << 
    hashCode(s, b) << endl;

  return 0; 
}
  
int hashCode(const string& s, int b)
{
    int hashCode = 0;
    for (int i = 0; i < s.length(); i++)
    {
      hashCode = hashCode * b + s[i];
    }
    
    return hashCode;
}
