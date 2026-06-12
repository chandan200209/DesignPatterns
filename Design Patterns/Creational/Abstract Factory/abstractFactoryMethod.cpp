#include <iostream>
using namespace std;

// product - 01 - Burger
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

// product - 02 - Garlic Bread
class GarlicBread
{
public:
    virtual void prepare() = 0; // pure virtual function
    virtual ~GarlicBread() {};
};
class BasicGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing basic garlic bread with butter and garlic!" << endl;
    }
};
class CheeseGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing cheese garlic bread with extra cheese and butter!" << endl;
    }
};
class BasicWheatGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing basic wheat garlic bread with butter and garlic!" << endl;
    }
};
class CheeseWheatGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing cheese wheat garlic bread with extra cheese and butter!" << endl;
    }
};

// factory and its concretions
class MealFactory
{
public:
    virtual Burger *createBurger(string &type) = 0;
    virtual GarlicBread *createGarlicBread(string &type) = 0;
};
class SinghBurger : public MealFactory
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
    GarlicBread *createGarlicBread(string &type) override
    {
        if (type == "basic")
        {
            return new BasicGarlicBread();
        }
        else if (type == "cheese")
        {
            return new CheeseGarlicBread();
        }
        else
        {
            cout << "Invalid garlic bread type!" << endl;
            return nullptr;
        }
    }
};
class KingBurger : public MealFactory
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
    GarlicBread *createGarlicBread(string &type) override
    {
        if (type == "basic")
        {
            return new BasicWheatGarlicBread();
        }
        else if (type == "cheese")
        {
            return new CheeseWheatGarlicBread();
        }
        else
        {
            cout << "Invalid garlic bread type!" << endl;
            return nullptr;
        }
    }
};
int main()
{
    string burgerType = "basic";
    string garlicBreadType = "cheese";
    MealFactory *mealFactory = new KingBurger();
    Burger *burger = mealFactory->createBurger(burgerType);
    GarlicBread *garlicBread = mealFactory->createGarlicBread(garlicBreadType);
    burger->prepare();
    garlicBread->prepare();
    return 0;
}