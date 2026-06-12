#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "Restaurant.h"
#include "MenuItem.h"
#include "../strategies/PaymentStrategy.h"
#include "../util/TimeUtils.h"

class Order
{
protected:
    static int nextOrderId;
    int orderId;
    User *user;
    Restaurant *restaurant;
    vector<MenuItem> items;
    PaymentStrategy *paymentStrategy;
    double total;
    string scheduled;

public:
    Order()
    {
        user = nullptr;
        restaurant = nullptr;
        paymentStrategy = nullptr;
        total = 0.0;
        scheduled = "";
        orderId = ++nextOrderId;
    }
    virtual ~Order()
    {
        delete paymentStrategy;
    }
    bool processPayment()
    {
        if (paymentStrategy)
        {
            paymentStrategy->pay(total);
            return true;
        }
        else
        {
            cout << "Please choose a payment strategy first." << endl;
            return false;
        }
    }
    virtual string getType() const = 0;
    // getters and setters
    int getOrderId() const
    {
        return orderId;
    }
    void setUser(User *u)
    {
        user = u;
    }
    User *getUser() const
    {
        return user;
    }
    void setRestaurant(Restaurant *r)
    {
        restaurant = r;
    }
    Restaurant *getRestaurant() const
    {
        return restaurant;
    }
    void setItems(const vector<MenuItem> &its)
    {
        items = its;
        total = 0;
        for (auto &i : items)
        {
            total += i.getPrice();
        }
    }
    const vector<MenuItem> &getItems() const
    {
        return items;
    }
    void setPaymentStrategy(PaymentStrategy *p)
    {
        paymentStrategy = p;
    }
    void setScheduled(const string &s)
    {
        scheduled = s;
    }
    string getScheduled() const
    {
        return scheduled;
    }
    double getTotal() const
    {
        return total;
    }
    void setTotal(int totalPrice)
    {
        total = totalPrice;
    }
};
int Order::nextOrderId = 0;
#endif // ORDER_H