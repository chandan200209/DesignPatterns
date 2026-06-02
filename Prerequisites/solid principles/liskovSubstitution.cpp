#include <bits/stdc++.h>
using namespace std;

class Account
{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};
class SavingAccount : public Account
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
        cout << "Deposited : " << amount << " in saving account. New balance : " << balance << endl;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn : " << amount << " from saving account. New balance : " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in saving account." << endl;
        }
    }
};
class CurrentAccount : public Account
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
        cout << "Deposited : " << amount << " in current account. New balance : " << balance << endl;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn : " << amount << " from current account. New balance : " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in current account." << endl;
        }
    }
};
class FixedTermAccount : public Account
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
        cout << "Deposited : " << amount << " in fixed term account. New balance : " << balance << endl;
    }
    void withdraw(double amount)
    {
        throw logic_error("Withdrawal not allowed in fixed term account.");
    }
};
// violated lsp
// class BankClient
// {
// private:
//     vector<Account *> accounts;

// public:
//     BankClient(vector<Account *> accounts)
//     {
//         this->accounts = accounts;
//     }
//     void processTransactions()
//     {
//         for (Account *acc : accounts)
//         {
//             acc->deposit(100); // all accounts support deposit
//             try
//             {
//                 // assuming all accounts support withdrawal (lsp violation)
//                 acc->withdraw(50);
//             }
//             catch (const logic_error &e)
//             {
//                 cout << "Exception : " << e.what() << endl;
//             }
//         }
//     }
// };

// solved lsp - wrongly using if-else conditions
// client class
class BankClient
{
private:
    vector<Account *> accounts;

public:
    BankClient(vector<Account *> accounts)
    {
        this->accounts = accounts;
    }
    void processTransactions()
    {
        for (Account *acc : accounts)
        {
            acc->deposit(12000);

            // checking account type explicitly
            if (typeid(*acc) == typeid(FixedTermAccount))
            {
                cout << "Skipping withdrawal for fixed term account" << endl;
            }
            else
            {
                try
                {
                    acc->withdraw(4000);
                }
                catch (const logic_error &e)
                {
                    cout << "Exception : " << e.what() << endl;
                }
            }
        }
    }
};
int main()
{
    vector<Account *> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient *client = new BankClient(accounts);
    // throws exception while withdrawing from fixed term account
    client->processTransactions();
    return 0;
}