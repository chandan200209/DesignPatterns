#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include <iostream>
#include <iomanip>
#include "PaymentStrategy.h"
#include <string>
using namespace std;

class CreditCardPaymentStrategy : public PaymentStrategy
{
private:
    string cardNumber;

public:
    CreditCardPaymentStrategy(const string &card)
    {
        this->cardNumber = card;
    }
    void pay(double amount) override
    {
        cout << "Paid Rs. " << amount << " using credit card (" << cardNumber << ")" << endl;
    }
};
#endif // CREDIT_CARD_PAYMENT_STRATEGY_H