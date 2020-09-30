#include <iostream>
#include <fstream>
using namespace std;

class MyInteger
{
private:
  int value;

public:
  int getValue() const
  {
    return value;
  }

  MyInteger(int value)
  {
    this->value = value;
  }

  bool isPrime() const
  {
    return isPrime(value);
  }

  static bool isPrime(const MyInteger& o)
  {
    return isPrime(o.getValue());
  }

  static bool isPrime(int num)
  {
    if ((num == 1) || (num == 2))
    {
      return true;
    }

    for (int i = 2; i <= num / 2; i++)
    {
      if (num % i == 0)
        return false;
    }

    return true;
  }

  bool isEven() const
  {
    return isEven(value);
  }

  static bool isEven(int n)
  {
    return n % 2 == 0;
  }

  static bool isEven(const MyInteger& n)
  {
    return isEven(n.getValue());
  }

  bool equals(int anotherNum) const
  {
    return value == anotherNum;
  }

  bool equals(const MyInteger& o) const
  {
    return value == o.getValue();
  }
};

int main()
{
  MyInteger n1(5);
  cout << "n1 is even? " << n1.isEven() << endl;
  cout << "n1 is prime? " << n1.isPrime() << endl;
  cout << "5 is prime? " << MyInteger::isPrime(5) << endl;
}
