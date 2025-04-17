#include <iostream>

int main(){

struct Student{
    char name[100];
    int id;
    float grade;
    };

Student student [100];

int StudentCount=0;
int menu;
while (true)
 {
     std::cout<<"1 Add a student\n2 Display all students\n3 Search for a student by ID\n4 Exit program\n";
     std::cin>>menu;

switch (menu)
{
case 1: {
    if (StudentCount < 100) {  
        std::cout << "Enter student name: ";
        std::cin.ignore(); // clear any newline left in the buffer
        std::cin.getline(student[StudentCount].name, 100); // Read student name
        std::cout << "Enter student ID: ";
        std::cin >> student[StudentCount].id;
        std::cout << "Enter student grade: ";
        std::cin >> student[StudentCount].grade;

        StudentCount++; }
     else {
        std::cout << "Max students reached.\n";
    }}
    break;

case 2:{
for (int i = 0; i < StudentCount; i++) {
    std::cout << "Student " << i + 1 << ":\n";
    std::cout << "Name: " << student[i].name << std::endl;
    std::cout << "ID: " << student[i].id << std::endl;
    std::cout << "Grade: " << student[i].grade << std::endl; }
} 
    break;

case 3: {

int searchID;
std::cout << "Enter the student ID to search: ";
std::cin >> searchID;

bool found = false;
for (int i = 0; i < StudentCount; i++) {
    if (student[i].id == searchID) {
        std::cout << "student found:\n";
        std::cout << "Name: " << student[i].name << std::endl;
        std::cout << "ID: " << student[i].id << std::endl;
        std::cout << "Grade: " << student[i].grade << std::endl;
        found = true;
        break; // stop after finding
    }
}
if (!found) {
    std::cout << "No student found with ID " << searchID << std::endl;
} }
 break;

case 4:{
    std::cout<<"exit program"<<std::endl;
 return 0;

default:
std::cout<<"choose an option\n"<<std::endl;}

}
}
}