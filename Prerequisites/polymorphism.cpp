// this program includes all the concepts of OOPs
#include <iostream>
#include <string>
using namespace std;

class Car
{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string b, string m)
    {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }
    // common methods for all cars
    void startEngine()
    {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }
    void stopEngine()
    {
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off!" << endl;
    }
    virtual void accelerate() = 0;          // abstract method for dynamic polymorphism
    virtual void accelerate(int speed) = 0; // abstract method for static polymorphism
    virtual void brake() = 0;               // abstract method for dynamic polymorphism
    virtual ~Car() {};                      // virtual destructor
};
class ManualCar : public Car
{
private:
    int currentGear;

public:
    ManualCar(string b, string m) : Car(b, m)
    {
        currentGear = 0;
    }
    // specialized method for manual car
    void shiftGear(int gear)
    {
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }
    // overriding accelerate - dynamic polymorphism
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
    // overriding and overloading accelerate - dynamic + static polymorphism
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
    // overriding brake - dynamic polymorphism
    void brake()
    {
        currentSpeed -= 20;
        if (currentSpeed < 0)
            currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << "km/h" << endl;
    }
};
class ElectricCar : public Car
{
private:
    int batteryLevel;

public:
    ElectricCar(string b, string m) : Car(b, m)
    {
        batteryLevel = 100;
    }
    // specialized method for electric car
    void chargeBattery()
    {
        batteryLevel = 100;
        cout << brand << " " << model << " : Battery fully charged. " << endl;
    }
    // overriding accelerate - dynamic polymorphism
    void accelerate()
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Engine is off. Cannot accelerate!" << endl;
            return;
        }
        if (batteryLevel <= 0)
        {
            cout << brand << " " << model << " : Battery dead! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 15;
        batteryLevel -= 10;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << "km/h" << " Battery level " << batteryLevel << " %" << endl;
    }
    // overriding and overloading accelerate - dynamic + static polymorphism
    void accelerate(int speed)
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Engine is off. Cannot accelerate!" << endl;
            return;
        }
        if (batteryLevel <= 0)
        {
            cout << brand << " " << model << " : Battery dead! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += speed;
        batteryLevel -= 10;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << "km/h" << " Battery level " << batteryLevel << " %" << endl;
    }
    // overriding brake - dynamic polymorphism
    void brake()
    {
        currentSpeed -= 20;
        if (currentSpeed < 0)
            currentSpeed = 0;
        cout << brand << " " << model << " : Regenerative Braking! Speed is now " << currentSpeed << "km/h" << " Battery level " << batteryLevel << " %" << endl;
    }
};
int main()
{
    ManualCar *myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1); // specific for manual car
    myManualCar->accelerate();
    myManualCar->shiftGear(2);
    myManualCar->accelerate();
    myManualCar->accelerate(34);
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout << endl;

    ElectricCar *myElectricCar = new ElectricCar("Tesla", "Model X");
    myElectricCar->chargeBattery(); // specific for electric car
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate(27);
    myElectricCar->brake();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;
    return 0;
}
