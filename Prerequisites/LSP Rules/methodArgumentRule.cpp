#include <iostream>
using namespace std;

// method argument rule : subtype method arguments can be identical or wider than their supertype
// c++ imposes this type keeping signature identical
// the return type can be narrower (covariant).
// the input arguments must be identical or broader (contravariant).

// C++ does not support true contravariance for function arguments during an override. In C++, if you change the argument type in the child class (even to make it broader), it is no longer considered an override—it becomes function overloading, and it hides the base class method instead of overriding it.

class Parent
{
public:
    virtual void print(string msg)
    {
        cout << "Parent : " << msg << endl;
    }
};
class Child : public Parent
{
    void print(string msg) override
    {
        cout << "Child : " << msg << endl;
    }
};
// Client Class that passes string as msg that client expects
class Client
{
private:
    Parent *p;

public:
    Client(Parent *p)
    {
        this->p = p;
    }
    void printMsg()
    {
        p->print("Hello World");
    }
};
int main()
{
    Parent *parent = new Parent();
    Parent *child = new Child();

    // Client *client = new Client(parent);
    Client *client = new Client(child);
    client->printMsg();
    return 0;
}