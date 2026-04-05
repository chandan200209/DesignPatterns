// method overloading - same name, different parameters
#include <iostream>
#include <string>
using namespace std;

class ManualCar
{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

public:
    ManualCar(string b, string m)
    {
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
        this->currentGear = 0;
    }
    // methods
    void startEngine()
    {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }
    // overloading accelerate - static polymorphism
    void accelerate()
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Engine is off. Cannot accelerate!" << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << "km/h" << endl;
    }
    void accelerate(int speed)
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Engine is off. Cannot accelerate!" << endl;
            return;
        }
        currentSpeed += speed;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << "km/h" << endl;
    }
    void brake()
    {
        currentSpeed -= 20;
        if (currentSpeed < 0)
            currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << "km/h" << endl;
    }
    void stopEngine()
    {
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off!" << endl;
    }
    void shiftGear(int gear)
    {
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }
};
int main()
{
    ManualCar *myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1); // specific for manual car
    myManualCar->accelerate();
    myManualCar->shiftGear(2);
    myManualCar->accelerate(12);
    myManualCar->accelerate(28);
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;
    return 0;
}
