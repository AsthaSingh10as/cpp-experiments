
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    // Student marks dataset using vector
    vector<pair<string, int>> students = {
        {"Arun", 85},
        {"Bala", 72},
        {"Charan", 95},
        {"David", 60},
        {"Esha", 88}
    };

    cout << "STUDENT MARKS DATASET" << endl;

    for (auto s : students) {
        cout << s.first << " : " << s.second << endl;
    }

    // 1. SORT algorithm
    sort(students.begin(), students.end(),
         [](const pair<string, int>& a,
            const pair<string, int>& b) {
             return a.second > b.second;
         });

    cout << "\nSTUDENTS SORTED BY MARKS (DESCENDING)" << endl;

    for (auto s : students) {
        cout << s.first << " : " << s.second << endl;
    }

    // 2. find_if algorithm
    auto result = find_if(students.begin(), students.end(),
                          [](const pair<string, int>& s) {
                              return s.second >= 90;
                          });

    cout << "\nSTUDENT SCORING 90 OR ABOVE" << endl;

    if (result != students.end()) {
        cout << result->first << " : " << result->second << endl;
    } else {
        cout << "No student found" << endl;
    }

    // 3. transform algorithm
    vector<int> updatedMarks;

    transform(students.begin(), students.end(),
              back_inserter(updatedMarks),
              [](const pair<string, int>& s) {
                  return s.second + 5;
              });

    cout << "\nMARKS AFTER ADDING 5 BONUS MARKS" << endl;

    for (int mark : updatedMarks) {
        cout << mark << " ";
    }
    cout << endl;

    // 4. map container
    map<string, int> studentMap;

    for (auto s : students) {
        studentMap[s.first] = s.second;
    }

    cout << "\nSTUDENT RECORDS USING MAP" << endl;

    for (auto s : studentMap) {
        cout << s.first << " : " << s.second << endl;
    }

    // 5. unordered_map container
    unordered_map<string, int> studentHash;

    for (auto s : students) {
        studentHash[s.first] = s.second;
    }

    cout << "\nSTUDENT RECORDS USING UNORDERED_MAP" << endl;

    for (auto s : studentHash) {
        cout << s.first << " : " << s.second << endl;
    }

    return 0;
}
