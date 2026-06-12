#ifndef CART_H
#define CART_H

#include <string>
#include <vector>
#include <iostream>
#include "../models/MenuItem.h"
#include "../models/Restaurant.h"
using namespace std;

class Cart
{
private:
    Restaurant *restaurant;
    vector<MenuItem> items;

public:
    Cart()
    {
        restaurant = nullptr;
    }
    void addItem(const MenuItem &item)
    {
        if (!restaurant)
        {
            cerr << "Cart: Set a restaurant before adding items." << endl;
        }
        items.push_back(item);
    }
    int getTotalCost() const
    {
        double sum = 0;
        for (const auto &it : items)
        {
            sum += it.getPrice();
        }
        return sum;
    }
    bool isEmpty()
    {
        return (!restaurant || items.empty());
    }
    void clear()
    {
        items.clear();
        restaurant = nullptr;
    }
    // getters and setters
    void setRestaurant(Restaurant *r)
    {
        restaurant = r;
    }
    Restaurant *getRestaurant() const
    {
        return restaurant;
    }
    const vector<MenuItem> &getItems() const
    {
        return items;
    }
};
#endif // CART_H