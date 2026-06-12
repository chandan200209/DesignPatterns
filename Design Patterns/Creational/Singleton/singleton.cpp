#include <iostream>
using namespace std;

class Singleton
{
public:
    Singleton()
    {
        cout << "Singleton constructor called. New object created." << endl;
    }
};
int main()
{
    Singleton *s1 = new Singleton();
    Singleton *s2 = new Singleton();
    // cout << (s1 == s2) << endl; // s1 and s2 are references to the objects created, they are not objects
    // the output for s1 == s2 will be 0
    return 0;
}