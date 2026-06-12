#include <iostream>
using namespace std;

/*
Thread-safe singleton using C++11 local static initialization.
This avoids explicit mutex use on toolchains where <mutex> is unavailable.
*/

class Singleton
{
private:
    Singleton()
    {
        cout << "Singleton constructor called. New object created." << endl;
    }

    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

public:
    static Singleton *getInstance()
    {
        static Singleton instance;
        return &instance;
    }
};

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    cout << (s1 == s2) << endl; // this time it will be true
    return 0;
}
