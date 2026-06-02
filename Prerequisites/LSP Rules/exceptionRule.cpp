#include <iostream>
using namespace std;

/*
exception rule -
a subclass should throw narrower or fewer exceptions (but not broader or additional exceptions) than the parent
C++ does not enforces this. Hence, no compilation error.

<stdexcept> header
logic_error -> for logical errors detected before runtime (easily preventable)
    invalid_argument -> invalid function argument
    domain_error -> function argument domain error
    length_error -> exceeding valid length limits
    out_of_range -> array or container index out of bounds

runtime_error -> for errors occured at runtime (not predicted or prevented generally)
    range_error -> numeric result out of range
    overflow_error -> arithmetic overflow
    underflow_error -> arithmetic underflow
*/

class Parent
{
public:
    virtual void getValue() noexcept(false)
    { // Parent throws logic error exception
        throw logic_error("Parent Error");
    }
};
class Child : public Parent
{
    void getValue() noexcept(false)
    {
        // Child throws out of range error exception
        throw out_of_range("Child Error");
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
    void takeValue()
    {
        try
        {
            p->getValue();
        }
        catch (const logic_error &e)
        {
            cout << "Logic error exception occurred : " << e.what() << endl;
        }
    }
};
int main()
{
    Parent *parent = new Parent();
    Child *child = new Child();
    Client *client = new Client(parent);
    client->takeValue();
    return 0;
}