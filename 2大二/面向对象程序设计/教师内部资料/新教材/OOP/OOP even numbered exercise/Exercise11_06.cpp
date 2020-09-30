#include <iostream>
#include <cstring>
using namespace std;

int* count(const char* const s)
{
  int* counts = new int[10];
  for (int i = 0; i < 10; i++)
    counts[i] = 0;

  for (int i = 0; i < strlen(s); i++)
  {
    if (isdigit(s[i]))
      counts[s[i] - '0'] ++;
  }

  return counts;
}

int main()
{

  int* counts = count("SSN is 343 32 4545 and ID is 434 34 4323");

  for (int i = 0; i < 10; i++)
    cout << i << " " << counts[i] << endl;

  return 0;
}
