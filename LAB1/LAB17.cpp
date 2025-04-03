#include <iostream>
using namespace std;

#define MIN_LENGTH 8

int main(){
    string password;
    cout << "give password to test";
    cin >> password;

    if (password.length()<MIN_LENGTH) {
        cout <<" weak password. Must be at least " << MIN_LENGTH<< "characters long. \n";
    }
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false; //setting default value to false first
    for (char ch : password) {  // Loop through each character in the string
        if (isupper(ch)) hasUpper = true;  // check for uppercase letter
        if (islower(ch)) hasLower = true;  // gheck for lowercase letter
        if (isdigit(ch)) hasDigit = true;  // check for a digit
        if (!isalnum(ch)) hasSpecial = true;  // check for special char
    }
    if (hasUpper&&hasLower&&hasDigit&&hasSpecial){
        cout << "Strong Password"<<endl;
    } else {
        cout<<"Weak Password. You are missing ";
        if (!hasUpper) cout <<"uppercase letter,";
        if (!hasLower) cout <<"lowercase letter,";
        if (!hasDigit) cout <<"digit";
        if (!hasSpecial) cout <<"special character,";
        cout << endl;
    }
return 0;
}