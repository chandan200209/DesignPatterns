#ifndef RESTAURANT_H // "If RESTAURANT_H has NOT been defined, continue."
#define RESTAURANT_H

// .h file → Table of contents / blueprint - "These classes and functions exist."
// .cpp file → Actual implementation - "Here's how those classes and functions work."

#include <iostream>
#include <vector>
#include <string>
#include "MenuItem.h"

using namespace std;

class Restaurant
{
private:
    static int nextRestaurantId; // static to make it auto-incrementing
    int restaurantId;
    string name;
    string location;
    vector<MenuItem> menu;

public:
    // why '&' is used, without it, copies the string - which is inefficient
    Restaurant(const string &name, const string &location)
    {
        this->name = name;
        this->location = location;
        this->restaurantId = ++nextRestaurantId;
    }
    ~Restaurant()
    {
        // optional : just for clarity and debug
        cout << "Destroying restaurant : " << name << ", and clearing its menu." << endl;
        menu.clear();
    }
    // getters and setters
    // The 'const' after the function means: this function promises not to modify the object.
    string getName() const
    {
        return name;
    }
    void setName(const string &n)
    {
        name = n;
    }
    string getLocation() const
    {
        return location;
    }
    void setLocation(const string &loc)
    {
        location = loc;
    }
    void addMenuItem(const MenuItem &item)
    {
        menu.push_back(item);
    }
    const vector<MenuItem> &getMenu() const
    {
        return menu;
    }
};
int Restaurant::nextRestaurantId = 0;
#endif // RESTAURANT_H