#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
  int id;
  double balance;
  double annualInterestRate;

public:
  Account();
  Account(int id, double balance, double annualInterestRate);

  int getId();
  double getBalance();
  double getAnnualInterestRate();
  void setId(int id);
  void setBalance(double balance);
  void setAnnualInterestRate(double annualInterestRate);
  double getMonthlyInterest();
  void withdraw(double amount);
  void deposit(double amount);
};

#endif
