#include <iostream>
using namespace std;
/*
a precondition must be satisfied before a method can be executed.
subclasses can weaken the precondition but cannot strengthen it
*/

class User
{
public:
    // precondition : password must be atleast 8 characters long
    virtual void setPassword(string password)
    {
        if (password.length() < 8)
        {
            throw invalid_argument("Password must be atleast 8 characters long.");
        }
        cout << "Password set successfully" << endl;
    }
};
class AdminUser : public User
{
public:
    // precondition : password must be atleast 6 characters long
    void setPassword(string password) override
    {
        if (password.length() < 6)
        {
            throw invalid_argument("Password must be atleast 6 characters long.");
        }
        cout << "Password set successfully" << endl;
    }
};

int main()
{
    User *user = new AdminUser();
    // user->setPassword("chandan123");
    user->setPassword("chandan"); // works fine, AdminUser allows shorter passwords
    return 0;
}