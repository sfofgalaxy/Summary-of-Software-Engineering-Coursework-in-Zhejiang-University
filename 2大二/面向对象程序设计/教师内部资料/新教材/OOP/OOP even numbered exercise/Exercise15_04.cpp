#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Account
{
private:
  int id;
  double balance;
  double annualInterestRate;

public:
  Account()
  {
    id = 0;
    balance = 0;
    annualInterestRate = 0;
  }

  Account(int id, double balance, double annualInterestRate)
  {
    this->id = id;
    this->balance = balance;
    this->annualInterestRate = annualInterestRate;
  }

  int getId() const
  {
    return this->id;
  }

  double getBalance() const
  {
    return balance;
  }

  double getAnnualInterestRate() const
  {
    return annualInterestRate;
  }

  void setId(int id)
  {
    this->id = id;
  }

  void setBalance(double balance)
  {
    this->balance = balance;
  }

  void setAnnualInterestRate(double annualInterestRate)
  {
    this->annualInterestRate = annualInterestRate;
  }

  double getMonthlyInterest() const
  {
    return balance * (annualInterestRate / 1200);
  }

  void withdraw(double amount)
  {
    balance -= amount;
  }

  void deposit(double amount)
  {
    balance += amount;
  }

  virtual string toString() const
  {
    stringstream ss;
    ss << "Account id: " << id << " balance: " << balance;
    return ss.str();
  }
};

class Checkings : public Account
{
protected:
  int overdraftLimit;

public:
  Checkings()
  {
    overdraftLimit = 5000;
  }

  string toString() const
  {
    return "Checkings";
  }
};

class Saving : public Account
{
protected:
  int overdraftLimit;

public:

  Saving()
  {
    overdraftLimit = 5000;
  }

  string toString() const
  {
    return "Saving";
  }
};

int main()
{
  Saving saving;
  Checkings checking;

  return 0;
}