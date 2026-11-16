
#include <iostream>
#include <string>
using namespace std;

// Generic Stack Class using Template
template <class T>
class Stack {
private:
    T arr[100];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Push operation
    void push(T value) {
        if (top >= 99) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack" << endl;
        }
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
        } else {
            cout << arr[top--] << " popped from stack" << endl;
        }
    }

    // Display operation
    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    // Peek operation
    void peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }
};

int main() {
    // Integer Stack
    cout << "INTEGER STACK" << endl;
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.display();
    s1.peek();
    s1.pop();
    s1.display();

    // Float Stack
    cout << "\nFLOAT STACK" << endl;
    Stack<float> s2;
    s2.push(10.5);
    s2.push(20.5);
    s2.push(30.5);
    s2.display();
    s2.pop();
    s2.display();

    // String Stack
    cout << "\nSTRING STACK" << endl;
    Stack<string> s3;
    s3.push("Apple");
    s3.push("Banana");
    s3.push("Orange");
    s3.display();
    s3.peek();
    s3.pop();
    s3.display();

    return 0;
}
