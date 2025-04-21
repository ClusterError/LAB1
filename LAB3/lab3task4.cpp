#include <iostream>
using namespace std;

class Vehicle {

    protected:
    string Brand;
    int Year;

    public:
    Vehicle(string b="def", int y = 0){
        Brand = b;
        Year = y;
    }
        // Display car info
    void ShowInfo() {
        cout << "Brand: " << Brand << endl;
        cout << "Year: " << Year << endl;
    }
    void StartEngine(){
        cout<<"Starting engine of vehicle"<<endl;
    }
};

class Car: public Vehicle{
    private:
    int numDoors;

    public:
    Car(string b="", int y=0, int doors=0):Vehicle(b , y ){
        numDoors = doors;
    }
    void ShowInfo(){
    Vehicle::ShowInfo();
    cout<<"Number of doors:"<<numDoors<<endl;
    }
    void StartEngine(){
        cout<<"Car engine is starting!"<<endl;
    }
};

class ElectricCar: public Car{
    private:
    int BatteryCapacity;

    public:
    ElectricCar(string b="def", int y=0, int doors=0 ,int Battery=0):Car(b,y,doors){
        BatteryCapacity=Battery;
    }
    void ShowInfo(){
        Car::ShowInfo();
        cout<<"Battery capacity in kWH: "<< BatteryCapacity<<"kWh" <<endl;
    }
    void StartEngine(){
        cout<<"Car engine is starting... SIlent but powerful!"<<endl;
    }
};

int main(){
    Vehicle*v1 = new Vehicle ("Tajuta",2025);
    v1->ShowInfo();
    v1->StartEngine();
    
    Car* car1= new Car ("Lambargambar",1995,2);
    car1->ShowInfo();
    car1->StartEngine();

    ElectricCar* ecar1 = new ElectricCar("Tosla",1420,4,160);
    ecar1->ShowInfo();
    ecar1->StartEngine();

    ElectricCar* ecar2 = new ElectricCar();
    ecar2->ShowInfo();
    ecar2->StartEngine();

    delete v1;
    delete car1;
    delete ecar1;
    delete ecar2;

    return 0;

}