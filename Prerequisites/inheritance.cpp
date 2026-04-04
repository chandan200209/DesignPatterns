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
    // methods
    void startEngine()
    {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }
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
};
int main()
{
    ManualCar *myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1); // specific for manual car
    myManualCar->accelerate();
    myManualCar->shiftGear(2);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout << endl;

    ElectricCar *myElectricCar = new ElectricCar("Tesla", "Model X");
    myElectricCar->chargeBattery(); // specific for electric car
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;
    return 0;
}
