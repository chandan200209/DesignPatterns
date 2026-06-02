#include <iostream>
using namespace std;

// a postcondition must be satisfied after a method is executed.
// subclasses can strengthen the postcondition but cannot weaken it.

class Car
{
protected:
    int speed;

public:
    Car()
    {
        speed = 0;
    }
    void accelerate()
    {
        cout << "Accelerating." << endl;
        speed += 20;
    }
    // postcondition - speed of the car must reduce after brake
    virtual void brake()
    {
        cout << "Applying brakes." << endl;
        speed -= 20;
    }
};
// subclasses can strengthen the postcondition -> it does not violated LSP
class HybridCar : public Car
{
private:
    int charge;

public:
    HybridCar() : Car()
    {
        charge = 0;
    }
    // postcondition - speed must reduce after brake, charge must increase
    void brake() override
    {
        cout << "Applying brakes." << endl;
        speed -= 20;
        charge += 10;
    }
};
int main()
{
    // Car *hybridCar = new Car();
    Car *hybridCar = new HybridCar();
    hybridCar->brake();
    // works fine, hybrid car reduces speed and increases charge also
    // client feels no difference in substituting HybridCar in place of Car
    return 0;
}