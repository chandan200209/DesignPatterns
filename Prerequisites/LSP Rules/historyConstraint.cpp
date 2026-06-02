#include <iostream>
using namespace std;

// sub classes would not be allowed to change state the parent classes not allowed
class BankAccount
{
protected:
    double balance;

public:
    BankAccount(double b)
    {
        if (b < 0)
        {
            throw invalid_argument("Balance can't be negative.");
        }
        balance = b;
    }
    // history constraint -> withdrawal should be allowed
    virtual void withdraw(double amount)
    {
        if (balance - amount < 0)
            throw runtime_error("Insufficient funds.");
        balance -= amount;
        cout << "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};
class FixedDepositAccount : public BankAccount
{
public:
    FixedDepositAccount(double b) : BankAccount(b) {}
    // LSP broke, history constraint breaks
    // parent class behavior changed, now withdrawl is not allowed
    // this class will break client code that relies on withdrawl
    void withdraw(double amount) override
    {
        throw runtime_error("Withdrawal is not allowed in Fixed Term Account.");
    }
};

int main()
{
    // BankAccount *account = new BankAccount(1000);         // allowed
    BankAccount *account = new FixedDepositAccount(1000); // denied, we got exception
    account->withdraw(500);
    return 0;
}