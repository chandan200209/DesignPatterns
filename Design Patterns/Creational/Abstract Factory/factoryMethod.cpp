#include <iostream>
using namespace std;

// product class and subclasses
class Burger
{
public:
    virtual void prepare() = 0; // pure virtual function
    virtual ~Burger() {};       // virtual destructor
};
class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing basic burger with bun, patty and ketchup!" << endl;
    }
};
class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing standard burger with bun, patty, cheese and lettuce!" << endl;
    }
};
class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing premium burger with gourmet bun, premium patty, cheese, lettuce and secret sauce!" << endl;
    }
};
class BasicWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing basic wheat burger with bun, patty and ketchup!" << endl;
    }
};
class StandardWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing standard wheat burger with bun, patty, cheese and lettuce!" << endl;
    }
};
class PremiumWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing premium wheat burger with gourmet bun, premium patty, cheese, lettuce and secret sauce!" << endl;
    }
};
// factory and its concretions
class BurgerFactory
{
public:
    virtual Burger *createBurger(string &type) = 0;
};
class SinghBurger : public BurgerFactory
{
public:
    Burger *createBurger(string &type) override
    {
        if (type == "basic")
        {
            return new BasicBurger();
        }
        else if (type == "standard")
        {
            return new StandardBurger();
        }
        else if (type == "premium")
        {
            return new PremiumBurger();
        }
        else
        {
            cout << "Invalid burger type!" << endl;
            return nullptr;
        }
    }
};
class KingBurger : public BurgerFactory
{
public:
    Burger *createBurger(string &type) override
    {
        if (type == "basic")
        {
            return new BasicWheatBurger();
        }
        else if (type == "standard")
        {
            return new StandardWheatBurger();
        }
        else if (type == "premium")
        {
            return new PremiumWheatBurger();
        }
        else
        {
            cout << "Invalid burger type!" << endl;
            return nullptr;
        }
    }
};
int main()
{
    string type1 = "standard";
    string type2 = "basic";
    BurgerFactory *burgerFac = new SinghBurger();
    Burger *burger = burgerFac->createBurger(type1);
    burger->prepare();

    BurgerFactory *burgerFacAnother = new KingBurger();
    Burger *burgerAnother = burgerFacAnother->createBurger(type2);
    burgerAnother->prepare();
    return 0;
}