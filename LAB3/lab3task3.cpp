#include <iostream>
using namespace std;

class car {
    private:
        string name;
        string brand;
        int year;
    public:
    
    //construct

    car(string b = "", int y=0){
        brand = b;
        year = y;
        cout << " " << brand << "car from " << year << "created" << endl;
    }

    //Destructor
    ~car() {
        cout << " " << brand << "destroyred" << endl;
    }

    // Display car info
    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    int menu, year;
    string brand;
    car* cars[10];  // Array to hold up to 10 students
    int carCount = 0;   // Counter

 while (true) {

        cout << "1. Register car\n2. Display all cars\n3. delete cars\n4. Exit\n";
        cin >> menu;

        switch (menu) {
        case 1:  // Register car
            if (carCount < 10) {  // Check if there's space for more students
                cout << "Enter Car's brand: ";
                cin.ignore();  // Clear the input buffer (?)
                getline(cin, brand);  // Get brand name

                cout << "Enter car's year: ";
                cin >> year;  // Get year

                cars[carCount] = new car(brand, year);

                cout << "Car registered!" << endl;
                carCount++;  // Increase the student count
            } else {
                cout << "Max cars registered!!" << endl;
            }
            break;
        case 2:  // Display all cars
            if (carCount > 0) {
                for (int i = 0; i < carCount; i++) {
                    cout << "\nCars " << i + 1 << ":\n";
                    cars[i]->displayInfo();
                }
            } else {
                cout << "No cars registered" << endl;
            }
            break;
        case 3:
            if (carCount==0){
                cout<< "no cars to delete"<<endl;
            } else {
            int delIndex;
            cout<<"how many cars to delete? 1-"<<carCount<<endl;
            cin>>delIndex;

            if (delIndex<1||delIndex>carCount)
            {
                cout<<"invalid number"<<endl;
            } else {
                delete cars[delIndex-1]; //call destructor
                for (int i =delIndex-1; i<carCount - 1; i++){
                    cars[i] = cars[i+1];
                }
                carCount--;
                cout<<"car deleted"<<endl;
                }
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
