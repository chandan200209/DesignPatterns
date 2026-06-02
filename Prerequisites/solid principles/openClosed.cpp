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
    // getters - takes a reference, instead of copying it whole
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
    // constructor
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
// class ShoppingCartStorage
// {
// private:
//     ShoppingCart *cart;

// public:
//     ShoppingCartStorage(ShoppingCart *cart)
//     {
//         this->cart = cart;
//     }
//     void saveToDB()
//     {
//         cout << "Saving shopping cart to the database...." << endl;
//     }
// };

// abstract class
class Persistence
{
private:
    ShoppingCart *cart;

public:
    virtual void save(ShoppingCart *cart) = 0; // pure virtual function
};
class SQLPersistence : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving shopping cart to SQL DB...." << endl;
    }
};
class MongoPersistence : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving shopping cart to MongoDB...." << endl;
    }
};
class FilePersistence : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving shopping cart to Files...." << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProducts(new Product("laptop", 200000));
    cart->addProducts(new Product("mouse", 500));
    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    // 3 different references of persistence
    Persistence *db = new SQLPersistence();
    Persistence *mongo = new MongoPersistence();
    Persistence *file = new FilePersistence();

    db->save(cart);    // saves to sql
    mongo->save(cart); // saves to mongodb
    file->save(cart);  // saves to a file

    return 0;
}