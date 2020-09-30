#include <iostream>
#include <cstring>
#include <string>
#include <stdexcept>
using namespace std;

class BinaryFormatException : public runtime_error
{
public:
  BinaryFormatException(char ch) : runtime_error("Binary number format error")
  {
    this->ch = ch;
  }

  char getChar()
  {
    return ch;
  }

private:
  char ch;
};

void validate(const char* const binaryString) throw (runtime_error)
{
  for (int i = 0; i < strlen(binaryString); i++)
  {
    if (binaryString[i] != '0' && binaryString[i] != '1')
      throw BinaryFormatException(binaryString[i]);
  }
}

int parseBinary(const char * const binaryString)
{
  validate(binaryString);

  int value = binaryString[0] - '0';
  for (int i = 1; i < strlen(binaryString); i++)
  {
    value = value * 2 + binaryString[i] - '0';
  }

  return value;
}

int main()
{
  try
  {
    cout << parseBinary("10001") << endl;
    cout << parseBinary("11111111") << endl;
    cout << parseBinary("21111111") << endl;
  }
  catch (runtime_error ex)
  {
    cout << ex.what() << endl;
  }

  return 0;
}
