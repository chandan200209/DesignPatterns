#include <iostream>
using namespace std;
/*
class invariant (rule) of parent class object should not be broken by child class object
hence, child class can either maintain or strengthen the invariant but never narrows it down.
*/
// invariant - balance can never be negative
class BankAccount
{
protected:
    double balance;

public:
    BankAccount(double b)
    {
        if (b < 0)
        {
            throw invalid_argument("Balance can never be negative.");
        }
        balance = b;
    }
    virtual void withdraw(double amount)
    {
        if ((balance - amount) < 0)
        {
            throw runtime_error("Insufficient funds.");
        }
        balance -= amount;
        cout << "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};
// breaks invariant : should not be allowed
class CheatAccount : public BankAccount
{
public:
    CheatAccount(double b) : BankAccount(b) {}
    void withdraw(double amount) override
    {
        balance -= amount; // LSP broke, negative balance allowed
        cout << "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};
int main()
{
    BankAccount *bankAccount = new BankAccount(100);
    bankAccount->withdraw(100);

    // BankAccount *bankAccount = new CheatAccount(100);
    // bankAccount->withdraw(200);
    return 0;
}