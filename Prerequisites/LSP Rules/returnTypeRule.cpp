#include <iostream>
using namespace std;

/*
return type rule :
subtype overriden method return type should be either identical or narrower than the parent's method return type
this is also called return type covariance
c++ enforces this by covariance
*/
class Animal
{
    // some common Animal methods
};
class Cat : public Animal
{
    // additional Cat methods related to Cats
};
class Parent
{
public:
    virtual Animal *getAnimal()
    {
        cout << "Parent : Returning Animal instance." << endl;
        return new Animal();
    }
};
class Child : public Parent
{
public:
    Cat *getAnimal() override
    {
        cout << "Child : Returning Cat instance." << endl;
        return new Cat();
    }
};
class Client
{
private:
    Parent *p;

public:
    Client(Parent *p)
    {
        this->p = p;
    }
    void takeAnimal()
    {
        p->getAnimal();
    }
};
int main()
{
    Parent *parent = new Parent();
    Child *child = new Child();
    // Client *client = new Client(parent);
    Client *client = new Client(child);
    client->takeAnimal();
    return 0;
}