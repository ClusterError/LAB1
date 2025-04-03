#include <iostream>

using namespace std;

int main(){
    int i, reversenum = 0;
    cout<<"give numbers";
    cin >> i;

    for (;i>0 ;i/=10){
    reversenum = reversenum * 10 +(i%10);
    }
cout<<"reversed: " << reversenum << endl;
return 0;
}