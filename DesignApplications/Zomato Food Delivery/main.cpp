#include <iostream>
#include "ZomatoApp.h"
using namespace std;

int main()
{
    // create Zomato Facade
    ZomatoApp *zomatoApp = new ZomatoApp();

    // simulate a user coming in (happy flow)
    User *user = new User(101, "Chandan", "Navi Mumbai");
    cout << "User : " << user->getName() << " is active." << endl;

    // user searches the restaurants by location
    vector<Restaurant *> restaurantList = zomatoApp->searchRestaurants("Mumbai");
    if (restaurantList.empty())
    {
        cout << "No restaurants found!" << endl;
        return 0;
    }
    cout << "Found restaurants : " << endl;
    for (auto restaurant : restaurantList)
    {
        cout << " -> " << restaurant->getName() << endl;
    }

    // user selects a restaurant
    zomatoApp->selectRestaurant(user, restaurantList[0]);
    cout << "Selected Restaurant : " << restaurantList[0]->getName() << endl;

    // user add items to the cart
    zomatoApp->addToCart(user, "P1");
    zomatoApp->addToCart(user, "P3");

    zomatoApp->printUserCart(user);

    // user checkouts the cart
    Order *order = zomatoApp->checkOutNow(user, "Delivery", new UPIPaymentStrategy("1234567890"));

    // user pays for the cart, if payment is successful, notification is sent
    zomatoApp->payForOrder(user, order);

    // cleanup code
    delete zomatoApp;
    delete user;

    return 0;
}