
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int marks;
};

int main() {
    Student s[100];
    int n;

    ofstream outfile("students.txt");

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter name and marks: ";
        cin >> s[i].name >> s[i].marks;

        outfile << s[i].name << " "
                << s[i].marks << endl;
    }

    outfile.close();

    ifstream infile("students.txt");

    int i = 0;

    while (i < n && infile >> s[i].name >> s[i].marks) {
        i++;
    }

    infile.close();

    if (i == 0) {
        cout << "No student records found!";
        return 0;
    }

    int topper = 0;

    for (int j = 1; j < i; j++) {
        if (s[j].marks > s[topper].marks) {
            topper = j;
        }
    }

    cout << "\nTopper Details" << endl;
    cout << "Name: " << s[topper].name << endl;
    cout << "Marks: " << s[topper].marks << endl;

    return 0;
}
