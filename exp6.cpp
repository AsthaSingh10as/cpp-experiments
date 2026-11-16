
#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Default Constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized Constructor
    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    // Function Overloading
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }

    void display(string message) {
        cout << message;
        display();
    }

    // Operator Overloading (+)
    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // Operator Overloading (-)
    Complex operator-(Complex c) {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }

    // Operator Overloading (*)
    Complex operator*(Complex c) {
        Complex temp;
        temp.real = (real * c.real) - (imag * c.imag);
        temp.imag = (real * c.imag) + (imag * c.real);
        return temp;
    }
};

int main() {
    Complex c1(5, 3);
    Complex c2(2, 4);
    Complex result;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    // Function Overloading
    cout << "\nFunction Overloading:" << endl;
    c1.display("Complex Number: ");

    // Addition
    result = c1 + c2;
    cout << "\nAddition: ";
    result.display();

    // Subtraction
    result = c1 - c2;
    cout << "Subtraction: ";
    result.display();

    // Multiplication
    result = c1 * c2;
    cout << "Multiplication: ";
    result.display();

    return 0;
}
