#include <iostream>
#include <math.h>
using namespace std;

int multiply(int A1, int B1){
    return A1 * B1 ;
}

double multiply(double A1, double B1){
    return A1 * B1;
}

double multiply(double A1, double B1, bool C1){
    double result = A1 * B1;
    if (C1==1){
        return floor(result);
    }
    if (C1==0){
        return A1*B1;
    }
}

int main (){
int selection;
cout<< "Please select 1 = INTEGER, 2 = DOUBLE, 3 = ROUNDED INTEGER x DOUBLE";
cin >> selection;

    if (selection == 1){
        int A1, B1;
        cout << "give first integer";
        cin >> A1;
        cout << " give second integer";
        cin >> B1;
        cout<<"sum is: " << multiply(A1,B1)<<endl;
    }
    if (selection ==2 ){
        double A1, B1;
        cout << "give first double";
        cin >> A1;
        cout <<" give second double ";
        cin >> B1;
        cout <<"sum is: " << multiply(A1,B1)<<endl;
    }
    if (selection == 3 ){
        int A1;
        double B1;
        bool C1;
        cout << "give first integer";
        cin >>A1;
        cout << "give second double";
        cin >> B1;
        cout << "Would you like to floor the result? 1 = Yes, 0 = No. ";
        cin >> C1;
        if (C1==1){
        cout <<"rounded sum is: "<< (multiply((double)A1,B1,true))<<endl;
        }
        else{
            cout << "not rounded sum is:" <<(multiply((double)A1,B1,false));
        }
        
    }
}