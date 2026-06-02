#include <iostream>
#include <stdexcept>
using namespace std;

// single interface for all shapes (violates ISP)
class Shape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0; // 2D shapes don't have any volume
};
class Square : public Shape
{
private:
    double side;

public:
    // 'side' - member initializer list
    // it directly initializes 'side' with the value of 's' before the constructor body executes.
    // but initialization is usually more efficient and is required for some types of members.
    // side = s
    Square(double s) : side(s) {}
    double area() override
    {
        return side * side;
    }
    double volume() override
    {
        throw logic_error("Volume not applicable for square."); // unnecessary method
    }
};
// rectangle is also a 2D shape but forced to implement volume()
class Rectangle : public Shape
{
private:
    double length, width;

public:
    // length = l
    // width = w
    Rectangle(double l, double w) : length(l), width(w) {};
    double area() override
    {
        return length * width;
    }
    double volume() override
    {
        throw logic_error("Volume not applicable for rectangle."); // unnecessary method
    }
};
// cube is a 3D shape, so it does has a volume
class Cube : public Shape
{
private:
    double side;

public:
    // side = s
    Cube(double s) : side(s) {};
    double area() override
    {
        return 6 * side * side;
    }
    double volume() override
    {
        return side * side * side;
    }
};
int main()
{
    Shape *square = new Square(5);
    Shape *rectangle = new Rectangle(4, 7);
    Shape *cube = new Cube(10);

    cout << "Square area : " << square->area() << endl;
    cout << "Rectangle area : " << rectangle->area() << endl;
    cout << "Cube area : " << cube->area() << endl;
    cout << "Cube volume : " << cube->volume() << endl;

    try
    {
        cout << "Square volume : " << square->volume() << endl;
    }
    catch (logic_error &e)
    {
        cout << "Exception : " << e.what() << endl;
    }
    try
    {
        cout << "Rectangle volume : " << rectangle->volume() << endl;
    }
    catch (logic_error &e)
    {
        cout << "Exception : " << e.what() << endl;
    }
    return 0;
}