
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    // 1. Demonstration of Data Types
    int age;
    float height;
    double marks;
    char grade;
    bool isStudent;
    string name;

    // 2. Demonstration of Constants
    const float PI = 3.14159;
    const int MAX_MARKS = 100;

    // 3. Input and Output
    cout << "===== C++ BASIC CONCEPTS =====" << endl;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your height in meters: ";
    cin >> height;

    cout << "Enter your marks: ";
    cin >> marks;

    cout << "Enter your grade: ";
    cin >> grade;

    // 4. Demonstration of Variables
    isStudent = true;

    // 5. Demonstration of Operators
    int nextYearAge = age + 1;       // Arithmetic operator
    double percentage = (marks / MAX_MARKS) * 100;

    bool passed = marks >= 40;       // Relational operator

    bool eligible = (age >= 18) && isStudent;
                                      // Logical operator

    age += 1;                         // Assignment operator

    // 6. Display Results
    cout << "\n===== STUDENT DETAILS =====" << endl;

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << " meters" << endl;
    cout << "Marks: " << marks << endl;
    cout << "Grade: " << grade << endl;
    cout << "Is Student: " << boolalpha << isStudent << endl;

    cout << "\n===== CONSTANTS =====" << endl;
    cout << "PI = " << PI << endl;
    cout << "Maximum Marks = " << MAX_MARKS << endl;

    cout << "\n===== OPERATORS =====" << endl;
    cout << "Age next year: " << nextYearAge << endl;
    cout << "Percentage: " << percentage << "%" << endl;
    cout << "Passed: " << passed << endl;
    cout << "Eligible: " << eligible << endl;

    cout << "\nProgram executed successfully!" << endl;

    return 0;
}
