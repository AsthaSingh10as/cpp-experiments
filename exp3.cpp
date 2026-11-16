
#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

class StringData
{
private:
    char* data;
    int length;

public:

    // 1. Default Constructor
    StringData()
    {
        data = nullptr;
        length = 0;

        cout << "Default Constructor Called" << endl;
    }

    // 2. Parameterized Constructor
    StringData(const char* str)
    {
        length = strlen(str);

        data = new char[length + 1];
        strcpy(data, str);

        cout << "Parameterized Constructor Called" << endl;
    }

    // 3. Copy Constructor
    StringData(const StringData& other)
    {
        length = other.length;

        if (other.data != nullptr)
        {
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        else
        {
            data = nullptr;
        }

        cout << "Copy Constructor Called" << endl;
    }

    // 4. Move Constructor
    StringData(StringData&& other) noexcept
    {
        data = other.data;
        length = other.length;

        other.data = nullptr;
        other.length = 0;

        cout << "Move Constructor Called" << endl;
    }

    // 5. Copy Assignment Operator
    StringData& operator=(const StringData& other)
    {
        if (this != &other)
        {
            char* newData = nullptr;

            if (other.data != nullptr)
            {
                newData = new char[other.length + 1];
                strcpy(newData, other.data);
            }

            delete[] data;

            data = newData;
            length = other.length;
        }

        cout << "Copy Assignment Called" << endl;

        return *this;
    }

    // 6. Move Assignment Operator
    StringData& operator=(StringData&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;

            data = other.data;
            length = other.length;

            other.data = nullptr;
            other.length = 0;
        }

        cout << "Move Assignment Called" << endl;

        return *this;
    }

    // Display Function
    void display() const
    {
        if (data != nullptr)
        {
            cout << "String: " << data << endl;
        }
        else
        {
            cout << "String: Empty" << endl;
        }

        cout << "Length: " << length << endl;
    }

    // 7. Destructor
    ~StringData()
    {
        delete[] data;

        cout << "Destructor Called" << endl;
    }
};

int main()
{
    cout << "===== CONSTRUCTOR DEMONSTRATION =====" << endl;

    // Default Constructor
    StringData obj1;

    // Parameterized Constructor
    StringData obj2("Hello C++");

    // Copy Constructor
    StringData obj3(obj2);

    // Move Constructor
    StringData obj4(move(obj2));

    cout << "\n===== DISPLAY OBJECTS =====" << endl;

    cout << "\nObject 1:" << endl;
    obj1.display();

    cout << "\nObject 2 (Moved From):" << endl;
    obj2.display();

    cout << "\nObject 3 (Copied):" << endl;
    obj3.display();

    cout << "\nObject 4 (Moved):" << endl;
    obj4.display();

    // Copy Assignment
    cout << "\n===== COPY ASSIGNMENT =====" << endl;

    StringData obj5;
    obj5 = obj3;
    obj5.display();

    // Move Assignment
    cout << "\n===== MOVE ASSIGNMENT =====" << endl;

    StringData obj6;
    obj6 = move(obj3);
    obj6.display();

    cout << "\n===== PROGRAM COMPLETED =====" << endl;

    return 0;
}
