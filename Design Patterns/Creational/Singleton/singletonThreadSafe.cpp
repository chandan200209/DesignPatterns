#include <iostream>
#include <mutex>
using namespace std;

/*
using locks to make it thread safe.
problem - when two threads try to enter getInstance() the exact same time, they can create their own respective objects (more than one in total)
critical section - a portion of a code which multiple threads can execute simultaneously
*/

class Singleton
{
private:
    static Singleton *instance; // used for returning the same instance when once created.
    static mutex mtx;           // used for locking and unlocking
    Singleton()
    {
        cout << "Singleton constructor called. New object created." << endl;
    }

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            lock_guard<mutex> lock(mtx); // lock for thread safety
            if (instance == nullptr)
            {
                instance = new Singleton();
            }
        }
        return instance;
    }
};
// declaring the static variable
Singleton *Singleton::instance = nullptr;
mutex Singleton::mtx;
int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    cout << (s1 == s2) << endl; // this time it will be true
    return 0;
}
