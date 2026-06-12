#ifndef ZOMATO_APP_H
#define ZOMAT0_APP_H

#include <vector>
#include <string>
#include "./models/User.h"
#include "./models/Restaurant.h"
#include "./models/Cart.h"
#include "./managers/OrderManager.h"
#include "./managers/RestaurantManager.h"
#include "./strategies/PaymentStrategy.h"
#include "./strategies/UPIPaymentStrategy.h"
#include "./strategies/CreditCardPaymentStrategy.h"
#include "./services/NotificationService.h"
#include "./factories/NowOrderFactory.h"
#include "./factories/ScheduledOrderFactory.h"
#include "./util/TimeUtils.h"
using namespace std;

class ZomatoApp
{
public:
    ZomatoApp()
    {
        initializeRestaurants();
    }
    void initializeRestaurants()
    {
        Restaurant *restaurant01 = new Restaurant("Dil Se", "Hyderabad");
        restaurant01->addMenuItem(MenuItem("P1", "Idli", 70));
        restaurant01->addMenuItem(MenuItem("P2", "Biryani", 160));

        Restaurant *restaurant02 = new Restaurant("Savanna", "Mumbai");
        restaurant02->addMenuItem(MenuItem("P1", "Vada Pav", 30));
        restaurant02->addMenuItem(MenuItem("P2", "Corn Cheese Pizza", 210));
        restaurant02->addMenuItem(MenuItem("P3", "Chillie Paneer", 130));

        Restaurant *restaurant03 = new Restaurant("Haldiram", "Nagpur");
        restaurant03->addMenuItem(MenuItem("P1", "Pav Bhaji", 110));
        restaurant03->addMenuItem(MenuItem("P2", "Cold Drink", 60));

        // static method
        RestaurantManager *restaurantManager = RestaurantManager::getInstance();
        restaurantManager->addRestaurant(restaurant01);
        restaurantManager->addRestaurant(restaurant02);
        restaurantManager->addRestaurant(restaurant03);

        // add another sample restaurants
    }
    vector<Restaurant *> searchRestaurants(const string &location)
    {
        return RestaurantManager::getInstance()->searchByLocation(location);
    }
    void selectRestaurant(User *user, Restaurant *restaurant)
    {
        Cart *cart = user->getCart();
        cart->setRestaurant(restaurant);
    }
    void addToCart(User *user, const string &itemCode)
    {
        Restaurant *restaurant = user->getCart()->getRestaurant();
        if (!restaurant)
        {
            cerr << "Please select a restaurant first." << endl;
            return;
        }
        for (const auto &item : restaurant->getMenu())
        {
            if (item.getCode() == itemCode)
            {
                user->getCart()->addItem(item);
            }
        }
    }
    Order *checkOutNow(User *user, const string &orderType, PaymentStrategy *paymentStrategy)
    {
        return checkout(user, orderType, paymentStrategy, new NowOrderFactory());
    }
    Order *checkOutScheduled(User *user, const string &orderType, PaymentStrategy *paymentStrategy, const string &scheduleTime)
    {
        return checkout(user, orderType, paymentStrategy, new ScheduledOrderFactory(scheduleTime));
    }
    Order *checkout(User *user, const string &orderType, PaymentStrategy *paymentStrategy, OrderFactory *orderFactory)
    {
        if (user->getCart()->isEmpty())
        {
            return nullptr;
        }
        Cart *userCart = user->getCart();
        Restaurant *orderedRestaurant = userCart->getRestaurant();
        vector<MenuItem> itemsOrdered = userCart->getItems();
        double totalCost = userCart->getTotalCost();

        Order *order = orderFactory->createOrder(user, userCart, orderedRestaurant, itemsOrdered, paymentStrategy, totalCost, orderType);
        return order;
    }
    void payForOrder(User *user, Order *order)
    {
        bool isPaymentSuccess = order->processPayment();
        // clear user cart if payment is successful
        if (isPaymentSuccess)
        {
            NotificationService *notification = new NotificationService();
            notification->notify(order);
            user->getCart()->clear();
        }
    }
    void printUserCart(User *user)
    {
        cout << "Items in cart : " << endl;
        cout << "---------------------------------" << endl;
        for (const auto &item : user->getCart()->getItems())
        {
            cout << item.getCode() << " : " << item.getName() << " -> " << item.getPrice() << "/-" << endl;
        }
        cout << "---------------------------------" << endl;
        cout << "Grand Total : Rs." << user->getCart()->getTotalCost() << "/-" << endl;
    }
};

#endif // ZOMATO_APP_H
       // this is breaking SRP and principle of Least Knowledge
       // this is a kind of trade-off we generally have to face