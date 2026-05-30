#include <iostream>
#include <vector>
using namespace std;

// product class representing any item of the ecommerce website
class Product
{
public:
    string name;
    double price;

    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

// violating SRP - shoppingCart is handling multiple functionalities
// class ShoppingCart
// {
// private:
//     vector<Product *> products;

// public:
//     void addProducts(Product *p)
//     {
//         products.push_back(p);
//     }
//     const vector<Product *> &getProducts()
//     {
//         return products;
//     }

//     // 1. calculates the total price in the cart
//     double calculateTotal()
//     {
//         double total = 0;
//         for (auto p : products)
//         {
//             total += p->price;
//         }
//         return total;
//     }
//     // 2. prints invoice (should be in separate class)
//     void printInvoice()
//     {
//         cout << "Shopping cart invoice" << endl;
//         for (auto p : products)
//         {
//             cout << p->name << " -> " << p->price << endl;
//         }
//         cout << "Total: $" << calculateTotal();
//     }

//     // 3. saves to DB (should be in separate class)
//     void saveToDB()
//     {
//         cout << "Saving shopping cart to the database...." << endl;
//     }
// };

class ShoppingCart
{
private:
    vector<Product *> products; // stores heap allocated products

public:
    // setters
    void addProducts(Product *p)
    {
        products.push_back(p);
    }
    // getters
    const vector<Product *> &getProducts()
    {
        return products;
    }

    // calculates the total price in the cart
    double calculateTotal()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }
};
class ShoppingCartPrinter
{
private:
    // reference of cart object - has-a relationship
    ShoppingCart *cart;

public:
    ShoppingCartPrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }
    void printInvoice()
    {
        cout << "Shopping cart invoice" << endl;
        for (auto p : cart->getProducts())
        {
            cout << p->name << " -> " << p->price << endl;
        }
        cout << "Total: $" << cart->calculateTotal() << endl;
    }
};
class ShoppingCartStorage
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartStorage(ShoppingCart *cart)
    {
        this->cart = cart;
    }
    void saveToDB()
    {
        cout << "Saving shopping cart to the database...." << endl;
    }
};
int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProducts(new Product("laptop", 200000));
    cart->addProducts(new Product("mouse", 500));
    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();
    ShoppingCartStorage *db = new ShoppingCartStorage(cart);
    db->saveToDB();

    return 0;
}