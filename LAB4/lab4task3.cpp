#include <iostream>
#include <string>
using namespace std;

class Car {
    string model;
    int year, price;

public:
    // Constructor
    Car(string model = "def", int year = 0, int price = 0) {
        this->model = model;
        this->year = year;
        this->price = price;
        
        // Print message when car is created
        cout << "Car Constructor: " << model << " (" << year << ") - $" << price << endl;
    }

    // Destructor
    ~Car() {
        // Print message when car is destroyed
        cout << "Car Destructor: " << model << " destroyed" << endl;
    }

    // Display car info
    void Displayinfo() {
        cout << "Model: " << model << ", Year: " << year << ", Price: $" << price <<"\n\n"<< endl;
    }
};

class CarCollection {
private:
    Car** cars; // Pointer to an array of pointers to Car objects
    int size;  // Number of cars

public:
    // Constructor
    CarCollection(int n) {
        size = n;
        cars = new Car*[size];  // Dynamically allocate an array of pointers to Car objects

        // Input car details
        for (int i = 0; i < size; i++) {
            string model;
            int year, price;

            cout << "Enter model for car " << i + 1 << ": ";
            cin >> model;
            cout << "Enter year: ";
            cin >> year;
            cout << "Enter price: ";
            cin >> price;

            // Dynamically allocate each Car object
            cars[i] = new Car(model, year, price);  // Create new car with user input
        }

        cout << "CarCollection initialized with " << size << " cars\n\n" << endl;
    }

    // Destructor
    ~CarCollection() {
        // Delete each dynamically allocated Car object
        for (int i = 0; i < size; i++) {
            delete cars[i];  // Call each Car's destructor
        }

        delete[] cars;  // Clean up the array of pointers
        cout << "CarCollection destroyed" << endl;
    }

    // Display all cars
    void DisplayCars() {
        cout << "--- Car Collection ---" << endl;
        for (int i = 0; i < size; i++) {
            cars[i]->Displayinfo();
        }
    }
};

int main() {
    int menu, numCars;
    CarCollection* collection = nullptr; // Pointer to CarCollection object

    while (true) {
        cout << "1. Register car\n2. Display all cars\n3. Exit\n";
        cin >> menu;

        switch (menu) {
            case 1:  // Register car
                cout << "How many cars do you want to enter? ";
                cin >> numCars;

                // Create CarCollection object only once
                if (collection == nullptr) {
                    collection = new CarCollection(numCars);
                }
                break;

            case 2:  // Display all cars
                if (collection == nullptr || numCars <= 0) {
                    cout << "No cars registered." << endl;
                } else {
                    collection->DisplayCars();
                }
                break;

            case 3:  // Exit
                cout << "Exiting program." << endl;
                delete collection;  // Delete CarCollection object to free memory
                return 0;

            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
