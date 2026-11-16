
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream file;

    // Open CSV file for reading and writing
    file.open("students.csv",
              ios::in | ios::out | ios::trunc);

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Write student records
    cout << "WRITING STUDENT RECORDS" << endl;

    file << "RollNo,Name,Marks" << endl;
    file << "1,Arun,85" << endl;
    file << "2,Bala,90" << endl;
    file << "3,Charan,78" << endl;
    file << "4,David,95" << endl;
    file << "5,Esha,88" << endl;

    file.flush();

    // tellp() - Get current writing position
    cout << "\nCurrent write position (tellp): "
         << file.tellp() << endl;

    // seekp() - Move writing pointer to end
    file.seekp(0, ios::end);

    cout << "Write position after seekp: "
         << file.tellp() << endl;

    // Add another student record
    file << "6,Farhan,92" << endl;
    file.flush();

    cout << "New write position (tellp): "
         << file.tellp() << endl;

    // seekg() - Move reading pointer to beginning
    file.seekg(0, ios::beg);

    // tellg() - Get current reading position
    cout << "\nCurrent read position (tellg): "
         << file.tellg() << endl;

    // Read and display student records
    cout << "\nREADING STUDENT RECORDS" << endl;

    string line;

    if (getline(file, line)) {
        cout << line << endl;

        cout << "Read position after header (tellg): "
             << file.tellg() << endl;
    }

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();

    cout << "\nFile operations completed successfully!"
         << endl;

    return 0;
}
