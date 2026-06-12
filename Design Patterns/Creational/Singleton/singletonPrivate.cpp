#include <iostream>
using namespace std;

class Singleton
{
private:
    static Singleton *instance; // used for returning the same instance when once created.
    Singleton()
    {
        cout << "Singleton constructor called. New object created." << endl;
    }

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }
};
// declaring the static variable
Singleton *Singleton::instance = nullptr;
int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    cout << (s1 == s2) << endl; // this time it will be true
    return 0;
}
// this is all correct for a single thread, but for multithreading environment, it is not thread safe.