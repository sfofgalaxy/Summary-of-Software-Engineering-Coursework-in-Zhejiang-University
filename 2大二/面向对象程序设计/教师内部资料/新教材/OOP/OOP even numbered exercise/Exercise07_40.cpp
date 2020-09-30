#include <iostream>
#include <cstring>
using namespace std;

void bin2Hex(const char binaryString[], char hexString[])
{
  // Append 0s to the binaryString
  char temp[80];
  int i = 0;
  for ( ; i < 4 - (strlen(binaryString) % 4 == 0 ? 4 : strlen(binaryString) % 4); i++)
    temp[i] = '0';

  // Append the rest of binaryString to temp
  int j = 0;
  for ( ; j < strlen(binaryString); j++)
    temp[i + j] = binaryString[j];

  temp[i + j] = '\0';
  // For every four binary digits, get its hex number
  int k = 0;
  for ( ; k < strlen(temp); k += 4)
  {
    char four[5];
    four[0] = temp[k];
    four[1] = temp[k + 1];
    four[2] = temp[k + 2];
    four[3] = temp[k + 3];
    four[4] = '\0';

    if (strcmp(four, "0000") == 0)
      hexString[k / 4] = '0';
    else if (strcmp(four, "0001") == 0)
      hexString[k / 4] = '1';
    else if (strcmp(four, "0010") == 0)
      hexString[k / 4] = '2';
    else if (strcmp(four, "0011") == 0)
      hexString[k / 4] = '3';
    else if (strcmp(four, "0100") == 0)
      hexString[k / 4] = '4';
    else if (strcmp(four, "0101") == 0)
      hexString[k / 4] = '5';
    else if (strcmp(four, "0110") == 0)
      hexString[k / 4] = '6';
    else if (strcmp(four, "0111") == 0)
      hexString[k / 4] = '7';
    else if (strcmp(four, "1000") == 0)
      hexString[k / 4] = '8';
    else if (strcmp(four, "1001") == 0)
      hexString[k / 4] = '9';
    else if (strcmp(four, "1010") == 0)
      hexString[k / 4] = 'A';
    else if (strcmp(four, "1011") == 0)
      hexString[k / 4] = 'B';
    else if (strcmp(four, "1100") == 0)
      hexString[k / 4] = 'C';
    else if (strcmp(four, "1101") == 0)
      hexString[k / 4] = 'D';
    else if (strcmp(four, "1110") == 0)
      hexString[k / 4] = 'E';
    else if (strcmp(four, "1111") == 0)
      hexString[k / 4] = 'F';
  }

  hexString[k / 4] = '\0';
}

int main()
{
  cout << "Enter a bianry number as a string: ";
  char bianryString[80], hexString[20];
  cin >> bianryString;

  bin2Hex(bianryString, hexString);
  cout << hexString << endl;

  return 0;
}
