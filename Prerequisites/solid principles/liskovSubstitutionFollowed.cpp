#include <iostream>
#include <vector>
#include <stdexcept>
#include <typeinfo>
using namespace std;

// deposit only accounts include fixed term accounts
class DepositOnlyAccount
{
public:
    virtual void deposit(double amount) = 0;
};
// withdrawable accounts include both current and saving accounts
class WithdrawableAccount : public DepositOnlyAccount
{
public:
    virtual void withdraw(double amount) = 0;
};
class SavingAccount : public WithdrawableAccount
{
private:
    double balance;

public:
    SavingAccount()
    {
        balance = 0;
    }
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited : " << amount << " in Saving account. Balance : " << balance << endl;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn : " << amount << " from Saving account. Balance : " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in saving account." << endl;
        }
    }
};
class CurrentAccount : public WithdrawableAccount
{
private:
    double balance;

public:
    CurrentAccount()
    {
        balance = 0;
    }
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited : " << amount << " in Current account. Balance : " << balance << endl;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn : " << amount << " from Current account. Balance : " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in current account." << endl;
        }
    }
};
class FixedTermAccount : public DepositOnlyAccount
{
private:
    double balance;

public:
    FixedTermAccount()
    {
        balance = 0;
    }
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited : " << amount << " in Fixed Term account. Balance : " << balance << endl;
    }
};
class BankClient
{
private:
    vector<WithdrawableAccount *> withdrawableAccounts;
    vector<DepositOnlyAccount *> depositOnlyAccounts;

public:
    BankClient(vector<WithdrawableAccount *> withdrawableAccounts, vector<DepositOnlyAccount *> depositOnlyAccounts)
    {
        this->depositOnlyAccounts = depositOnlyAccounts;
        this->withdrawableAccounts = withdrawableAccounts;
    }
    void processTransactions()
    {
        for (WithdrawableAccount *acc : withdrawableAccounts)
        {
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for (DepositOnlyAccount *acc : depositOnlyAccounts)
        {
            acc->deposit(600);
        }
    }
};

int main()
{
    vector<WithdrawableAccount *> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());
    vector<DepositOnlyAccount *> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

    BankClient *client = new BankClient(withdrawableAccounts, depositOnlyAccounts);
    client->processTransactions();
    return 0;
}