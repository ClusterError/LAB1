#include <iostream>
#include <string>
using namespace std;


//class
class Car {
protected:
    string model;
    int year;
    float price;

public:
    Car() : model(""), year(0), price(0.0f) {}
    virtual ~Car() {}

// virtual for polymorphic cleanup. It clear classes and sublclasses. (this was suggested by chatgpt when debugging)
//  virtual makes sure derived class destrcutors are properly called for cleanup. 

    virtual void input() {
        cout << "Enter model: ";
        cin.ignore();
        getline(cin, model);
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter price: ";
        cin >> price;
    }
    virtual void display() const {
    cout << "Model: " << model << ", Year: " << year << ", Price: $" << price;
    }
};


class ElectricCar : public Car {
    float batterySize;
public:
    void input() override {
        Car::input();
        cout << "Enter battery size (kWh): ";
        cin >> batterySize;
    }
    void display() const override {
        Car::display();
        cout << ", Battery: " << batterySize << " kWh" << endl;
    }
    ~ElectricCar() override {
        cout << "Destroying Electric Car: " << model << endl;
    }
};

class GasCar : public Car {
    float fuelCapacity;
public:
    void input() override {
        Car::input();
        cout << "Enter fuel capacity (L): ";
        cin >> fuelCapacity;
    }
    void display() const override {
        Car::display();
        cout << ", Fuel: " << fuelCapacity << " L" << endl;
    }
    ~GasCar() override {
        cout << "Destroying Gas Car: " << model << endl;
    }
};

class HybridCar : public Car {
    float batterySize;
    float fuelCapacity;



public:
    void input() override {
        Car::input();
        cout << "Enter battery size (kWh): ";
        cin >> batterySize;
        cout << "Enter fuel capacity (L): ";
        cin >> fuelCapacity;
    }

    void display() const override {
        Car::display();
        cout << ", Battery: " << batterySize << " kWh, Fuel: " << fuelCapacity << " L" << endl;
    }

    ~HybridCar() override {
        cout << "Destroying Hybrid Car: " << model << endl;
    }
};

int main() {
    int n;
    cout << "Enter total number of cars: ";
    cin >> n;

    Car** fleet = new Car*[n];
    int* types = new int[n];

    for (int i = 0; i < n; i++) {
        int choice;
        cout << "\nCar " << i + 1 << " type:\n";
        cout << "[1] Electric\n[2] Gasoline\n[3] Hybrid\nEnter choice: ";
        cin >> choice;

        types[i] = choice;

        switch (choice) {
            case 1:
                fleet[i] = new ElectricCar();
                break;
            case 2:
                fleet[i] = new GasCar();
                break;
            case 3:
                fleet[i] = new HybridCar();
                break;
            default:
                cout << "Invalid choice. Defaulting to Electric.\n";
                fleet[i] = new ElectricCar();
                break;
        }
        fleet[i]->input();
    }

    cout << "\n - - - Fleet Information - - - \n";
    for (int i = 0; i < n; i++) {
        fleet[i]->display();
    }
    cout << "\n--- Cleaning up fleet ---\n";
    for (int i = 0; i < n; i++) {
        delete fleet[i];
    }
    delete[] fleet;
    delete[] types;
    return 0;
}
