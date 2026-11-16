
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person
{
protected:
    string name;
    int age;
    string gender;

public:
    // Constructor
    Person(string n, int a, string g)
    {
        name = n;
        age = a;
        gender = g;
    }

    // Display Person Details
    void displayPerson()
    {
        cout << "\n--- Person Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

// Single Inheritance
// Student inherits Person
class Student : public Person
{
protected:
    int rollNo;
    string course;

public:
    // Constructor
    Student(string n, int a, string g,
            int r, string c)
        : Person(n, a, g)
    {
        rollNo = r;
        course = c;
    }

    // Display Student Details
    void displayStudent()
    {
        displayPerson();

        cout << "\n--- Student Details ---" << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Course: " << course << endl;
    }
};

// Multilevel Inheritance
// GraduateStudent inherits Student
class GraduateStudent : public Student
{
private:
    string researchTopic;
    string guideName;

public:
    // Constructor
    GraduateStudent(string n, int a, string g,
                    int r, string c,
                    string topic, string guide)
        : Student(n, a, g, r, c)
    {
        researchTopic = topic;
        guideName = guide;
    }

    // Display Graduate Student Details
    void displayGraduateStudent()
    {
        displayStudent();

        cout << "\n--- Graduate Student Details ---" << endl;
        cout << "Research Topic: " << researchTopic << endl;
        cout << "Guide Name: " << guideName << endl;
    }
};

// Main Function
int main()
{
    cout << "================================" << endl;
    cout << "   UNIVERSITY MANAGEMENT SYSTEM" << endl;
    cout << "================================" << endl;

    // Demonstration of Single Inheritance
    cout << "\n===== SINGLE INHERITANCE =====" << endl;

    Student s1("Rahul", 20, "Male",
               101, "BCA");

    s1.displayStudent();

    // Demonstration of Multilevel Inheritance
    cout << "\n===== MULTILEVEL INHERITANCE =====" << endl;

    GraduateStudent g1("Amit", 24, "Male",
                       201, "MCA",
                       "Artificial Intelligence",
                       "Dr. Sharma");

    g1.displayGraduateStudent();

    cout << "\nProgram executed successfully!" << endl;

    return 0;
}
