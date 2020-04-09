
#include "account.h"
#include "std-threads.hpp"
#include <thread>

using namespace std;

Account::Account(double balance)
{
    this->balance = balance;
}
double Account::getBalance()
{
    return balance;
}
void Account::withdraw(double amount)
{
    lock.lock();
    if (balance >= amount)
    {
        this_thread::sleep_for(1s);
        balance = balance - amount;
    }
    else
    {
        this_thread::sleep_for(1s);
        cout << "Insufficient balance, withdraw denied." << endl;
    }
    lock.unlock();

    return;
}
void Account::deposit(double amount)
{
    lock.lock();
    this_thread::sleep_for(1s);
    balance = balance + amount;
    lock.unlock();
}


class AccountUser : public Thread
{
  private:
    Account* m_account;
    AccountType m_accountType;

    void operateAccount()
    {
        switch (m_accountType)
        {
        case DEPOSITOR:
        {
            cout << "DEPOSITOR : Account balance before the deposit is " << m_account->getBalance() << endl;
            m_account->deposit(1000.00);
            cout << "DEPOSITOR : Account balance after deposit is " << m_account->getBalance() << endl;
        }
        break;
        case WITHDRAWER:
        {
            cout << "WITHDRAWER : Account balance before withdrawing is " << m_account->getBalance() << endl;
            m_account->withdraw(2000.00);
            cout << "WITHDRAWER: Account balance after withdrawing is " << m_account->getBalance() << endl;
        }
        break;
        }
    }

  public:
    AccountUser(Account* account, AccountType type)
    {
        m_account = account;
        m_accountType = type;
    }

    void run()
    {
        while (!stopped)
        {
            operateAccount();
        }
        cout << "\nThread " << this_thread::get_id() << " stopped as requested." << endl;
        return;
    }

    void start()
    {
        thread* t = new thread(&AccountUser::run, this);
        Thread::start(t);
    }
};

int main()
{
    Account l_account(5000.00);
    AccountUser depositor(&l_account, AccountType::DEPOSITOR);
    AccountUser withdrawer(&l_account, AccountType::WITHDRAWER);

    depositor.start();
    withdrawer.start();

    this_thread::sleep_for(5s);
    depositor.stop();
    withdrawer.stop();

    depositor.join();
    withdrawer.join();

    return 0;
}
