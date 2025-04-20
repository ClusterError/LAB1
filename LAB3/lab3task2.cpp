#include <iostream>
using namespace std;

class Student {
private: 
    string name;
    int age;
    char grade;
    string group = "2025 group";

public:
    // Setters
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGrade(char g) { grade = g; }
    void setGroup(string gro) { group = gro; }

    // Getters
    string getName() { return name; }
    int getAge() { return age; }
    char getGrade() { return grade; }
    string getGroup() { return group; }

    // Display student info
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
        cout << "Group: " << group << endl;
    }
};

int main() {
    int menu, age;
    string name, group;
    char grade;
    Student students[10];  // Array to hold up to 10 students
    int studentCount = 0;   // Counter

    while (true) {
        cout << "1. Create student\n2. Print a student\n3. Display all students\n4. Exit\n";
        cin >> menu;

        switch (menu) {
        case 1:  // Create student
            if (studentCount < 10) {  // Check if there's space for more students
                cout << "Enter student's name: ";
                cin.ignore();  // Clear the input buffer (?)
                getline(cin, name);  // Get student name
                students[studentCount].setName(name);

                cout << "Enter student's age: ";
                cin >> age;  // Get student age
                students[studentCount].setAge(age);

                cout << "Enter student's grade: ";
                cin >> grade;  // Get student grade
                students[studentCount].setGrade(grade);

                cout << "Student created!" << endl;
                studentCount++;  // Increase the student count
            } else {
                cout << "Max student limit reached!" << endl;
            }
            break;

        case 2:  // Print a specific student's info (you can choose a student by index)
            if (studentCount > 0) {
                int studentIndex;
                cout << "Enter student index (1 to " << studentCount << "): ";
                cin >> studentIndex;

                if (studentIndex > 0 && studentIndex <= studentCount) {
                    students[studentIndex - 1].displayInfo();  // Display info of the selected student
                } else {
                    cout << "Invalid student index." << endl;
                }
            } else {
                cout << "No students to display." << endl;
            }
            break;

        case 3:  // Display all students
            if (studentCount > 0) {
                for (int i = 0; i < studentCount; i++) {
                    cout << "\nStudent " << i + 1 << ":\n";
                    students[i].displayInfo();
                }
            } else {
                cout << "No students to display." << endl;
            }
            break;

        case 4:  // Exit
            cout << "Exiting program." << endl;
            return 0;  // Exit the program

        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
