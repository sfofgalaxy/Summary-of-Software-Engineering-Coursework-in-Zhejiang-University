#include <iostream>
using namespace std;

const int MAXIMUM_SIZE = 100; // Maximum string size 100

class MyString
{
public:
  MyString(char ch, int n)
  {
    for (int i = 0; i < n; i++)
      value[i] = ch;

    size = n;
  }

  MyString(char chars[], int size)
  {
    for (int i = 0; i < size; i++)
      value[i] = chars[i];

    this->size = size;
  }

  MyString append(MyString s)
  {
    for (int i = 0; i < s.length(); i++)
      value[size + i] = s.at(i);

    size += s.length();

    return MyString(value, size);
  }

  MyString append(MyString s, int index, int n)
  {
    for (int i = 0; i < s.length() && i < n; i++)
      value[size + i] = s.at(index + i);

    size += s.length();

    return MyString(value, size);
  }

  MyString append(int n, char ch)
  {
    for (int i = size; i < size + n; i++)
      value[i] = ch;

    size += n;

    return MyString(value, size);
  }

  MyString assign(char* chars)
  {
    int i;
    for (i = 0; chars[i] != '\0'; i++)
      value[i] = chars[i];

    size = i;

    return MyString(value, size);
  }

  MyString assign(MyString s, int index, int n)
  {
    int i;
    for (i = 0; i < n; i++)
      value[i] = s.at(index + i);

    size = n;

    return MyString(value, size);
  }

  MyString assign(MyString s, int n)
  {
    return assign(s, 0, n);
  }

  MyString assign(int n, char ch)
  {
    for (int i = 0; i < n; i++)
      value[i] = ch;

    size = n;

    return MyString(value, size);
  }

  char at(int index)
  {
    return value[index];
  }

  int length()
  {
    return size;
  }

  MyString erase(int index, int n)
  {
    char temp[MAXIMUM_SIZE];
    for (int i = 0; i < size && i < index; i++)
      temp[i] = value[i];

    return MyString(temp, size - n);
  }

  char* data()
  {
    char * temp = new char[size + 1];
    for (int i = 0; i < size; i++)
      temp[i] = value[i];

    temp[size] = '\0';

    return temp;
  }

  MyString substr(int index, int n)
  {
    char * temp = new char[n];
    for (int i = 0; i < size && i < n; i++)
      temp[i] = value[i + index];

    return MyString(temp, n);
  }

  MyString substr(int index)
  {
    return substr(index, size - index - 1);
  }

  void swap(MyString s)
  {
    char * temp = s.data();
    int tempSize = s.length();

    s.assign(value);

    // Copy temp to value
    for (int i = 0; i < tempSize; i++)
      value[i] = temp[i];
    size = tempSize;
  }

  char operator[](const int &index)
  {
    if (index < 0 || index >= size)
    {
      cout << "subscript error" << endl;
      exit(0);
    }
    else
    {
      return value[index];
    }
  }

  MyString(char* chars)
  {
    int i = 0;
    for (; chars[i] != '\0'; i++)
      value[i] = chars[i];

    size = i;
  }

  MyString operator+(MyString& secondString)
  {
    char* s = new char[this->size + secondString.size + 1];
    int i = 0;
    for (; i <this->size; i++)
      s[i] = this->value[i];

    int j = 0;
    for (int j = 0; j < secondString.size; j++)
      s[i + j] = secondString.value[j];

    s[i + j] = '\0';
    return MyString(s);
  }

private:
  char value[MAXIMUM_SIZE];
  int size;
}; // Must place a semicolon here

int main()
{
  char s[] = {'a', 'b', 'c'};
  MyString stringObject1(s, 3);
  MyString stringObject2(s, 3);

  stringObject1 = stringObject2;

  stringObject1.append(stringObject2);

  for (int i = 0; i < stringObject1.length(); i++)
    cout << stringObject1.at(i);

  cout << endl;

  stringObject1 = stringObject1 + stringObject2;

  cout << stringObject1[0] << endl;
  cout << stringObject1[5] << endl;
  
  return 0;
}