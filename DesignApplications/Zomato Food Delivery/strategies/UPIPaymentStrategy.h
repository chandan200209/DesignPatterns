#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include <iostream>
#include <string>
#include "PaymentStrategy.h"
#include <iomanip>
using namespace std;

class UPIPaymentStrategy : public PaymentStrategy
{
private:
    string mobile;

public:
    UPIPaymentStrategy(const string &mob)
    {
        this->mobile = mob;
    }
    void pay(double amount) override
    {
        cout << "Paid Rs. " << amount << " using UPI (" << mobile << ")." << endl;
    }
};
#endif // UPI_PAYMENT_STRATEGY_H