#include <iostream>
#include <stdexcept>
using namespace std;

// separate interface for 2D shapes
class TwoDimensionalShape
{
public:
    virtual double area() = 0;
};

// separate interface for 3D shapes
class ThreeDimensionalShape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

// square implements only the 2D interface
class Square : public TwoDimensionalShape
{
private:
    double side;

public:
    // side = s
    Square(double s) : side(s) {}
    double area() override
    {
        return side * side;
    }
};
// rectangle implements only the 2D interface
class Rectangle : public TwoDimensionalShape
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
};
// cube is a 3D shape, so it does has a volume
// cube implements the 3D interface
class Cube : public ThreeDimensionalShape
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
    TwoDimensionalShape *square = new Square(5);
    TwoDimensionalShape *rectangle = new Rectangle(4, 7);
    ThreeDimensionalShape *cube = new Cube(10);

    cout << "Square area : " << square->area() << endl;
    cout << "Rectangle area : " << rectangle->area() << endl;
    cout << "Cube area : " << cube->area() << endl;
    cout << "Cube volume : " << cube->volume() << endl;
    return 0;
}