#include <iostream>
#include <mutex>

using namespace std;

class Account
{
  private:
    double balance;
    mutex lock;

  public:
    Account(double);
    double getBalance();
    void deposit(double amount);
    void withdraw(double amount);
};

enum AccountType
{
    DEPOSITOR,
    WITHDRAWER
};