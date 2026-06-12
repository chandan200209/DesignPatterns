#include <iostream>
using namespace std;

// eager initialization - used when object is light-weight
// because, there can be chances that the object created even before the main method won't be called a single time, but resources got wasted in creation of it
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
        return instance;
    }
};
// initializing static members
// when staic member ('instance') is being initialized, the object of singleton class is created in heap and reference of that is assigned to the 'instance' variable
// this is all done, even before the 'main()' run
Singleton *Singleton::instance = new Singleton();
int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    cout << (s1 == s2) << endl; // this time it will be true
    return 0;
}
