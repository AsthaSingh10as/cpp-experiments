
#include <iostream>
using namespace std;

// Abstract Base Class
class Shape
{
public:
    // Pure Virtual Function
    virtual double area() = 0;

    virtual void display()
    {
        cout << "Calculating Area of Shape" << endl;
    }

    // Virtual Destructor
    virtual ~Shape()
    {
    }
};

// Derived Class 1: Circle
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    double area() override
    {
        return 3.14159 * radius * radius;
    }

    void display() override
    {
        cout << "\nCircle Area: " << area() << endl;
    }
};

// Derived Class 2: Rectangle
class Rectangle : public Shape
{
private:
    double length, breadth;

public:
    Rectangle(double l, double b)
    {
        length = l;
        breadth = b;
    }

    double area() override
    {
        return length * breadth;
    }

    void display() override
    {
        cout << "\nRectangle Area: " << area() << endl;
    }
};

// Derived Class 3: Triangle
class Triangle : public Shape
{
private:
    double base, height;

public:
    Triangle(double b, double h)
    {
        base = b;
        height = h;
    }

    double area() override
    {
        return 0.5 * base * height;
    }

    void display() override
    {
        cout << "\nTriangle Area: " << area() << endl;
    }
};

// Main Function
int main()
{
    cout << "===== RUNTIME POLYMORPHISM =====" << endl;

    Circle c(5);
    Rectangle r(10, 5);
    Triangle t(8, 6);

    // Base class pointers
    Shape* shape;

    shape = &c;
    shape->display();

    shape = &r;
    shape->display();

    shape = &t;
    shape->display();

    cout << "\nProgram executed successfully!" << endl;

    return 0;
}
