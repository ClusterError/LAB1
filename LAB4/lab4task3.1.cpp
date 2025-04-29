//prototype code not work!!

#include <iostream>
#include <string>
using namespace std;

class Car {

    string model;
    int year, price;

    public:
    //constuctor
    Car(string model = "def", int year = 0, int price = 0 ){
        this->model = model;
        this->year = year;
        this->price = price;
        }
    //Destructor
    ~Car() {
        cout << " cars destroyred" << endl;
    }

    // Display car info
    void Displayinfo() {
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << "$"<< price << endl;
    }
};

class CarCollection {
private:
    Car* cars; // Pointer to an array of Car objects
    int size;  // Number of cars

public:
    // Constructor
    CarCollection(int n) {
        size = n;
        cars = new Car[size];  // Dynamically allocate array of cars

        // Input car details
        for (int i = 0; i < size; i++) {
            string model;
            int year, price;

            cout << "Enter details for car " << i + 1 << ":" << endl;
            cout << "Model: ";
            cin >> model;
            cout << "Year: ";
            cin >> year;
            cout << "Price: ";
            cin >> price;

            cars[i] = Car(model, year, price);  // Create new car with user input
        }
    }

    // Destructor
    ~CarCollection() {
        delete[] cars;  // Clean up the dynamically allocated memory
        cout << "All cars destroyed!" << endl;
    }

    // Display all cars
    void DisplayCars() {
        for (int i = 0; i < size; i++) {
            cout << "\nCar " << i + 1 << ":" << endl;
            cars[i].Displayinfo();
        }
    }
};

int main() {
    int menu, numCars;
 while (true) {

        cout << "1. Register car\n2. Display all cars\n3. delete cars\n4. Exit\n";
        cin >> menu;

        switch (menu) {


        case 1:  // Register car
        cout<< "how many cars?";
        cin >> numCars;

        CarCollection CarCollection(numCars);

        break;
/*
             failed experiment but i am proud of this so ill let it live
             while (j>0)
            {
                cout << "Enter Car's brand: ";
                cin.ignore();  // Clear the input buffer (?)
                getline(cin, model);  // Get brand name

                cout << "Enter car's year: ";
                cin >> year;  // Get year

                cout << "Enter car's price: ";
                cin >> price; // price

                cars[carCount] = new Car(model, year, price);

                cout << "Car registered!" << endl;
                carCount++;  // Increase the car count
                j=j-1;
                }
            cout << "- - - Initialized with "<< k << " cars - - -"<<endl;
            break;
*/            



        case 2:  // Display all cars
        if (numCars<=0){
            cout << "No cars. go buy some u poor"<<endl;
        }else{
            collection.DisplayCars();
        }
            break;

/*
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
*/

        case 3:  // Exit
            cout << "Exiting program." << endl;
            return 0;  // Exit the program

        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}