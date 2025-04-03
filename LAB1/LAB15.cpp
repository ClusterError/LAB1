#include <iostream>
#include <cmath>


using namespace std;
int main(){
    int A;
    int sum = 0;
    cout << "give numbers to sum";
    cin >> A;

    for (;A>0 ;A/=10){
    sum += A%10;
    }
    cout<<"sum is " << sum << endl;
return 0;
}