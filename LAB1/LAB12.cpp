//adding libraries
#include <iostream>
#include<algorithm>
#include <string>

//creating namespace. allows us to call for this code easily
using namespace std;
namespace uppercase1
{
      // checking if the letter is a vowel 
      //char c takes one letter
      // toupper c takes the letter and turns it into a uppercase
      //c is given the "values" in below aeiouyäö that are converted into uppercase
      //return returns the uppercased vowels if true
      bool isVowel(char c)
   {
      // vowels in finnnish
      c=toupper(c);
      return c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y'||c=='Ä'||c=='Ö';
   }

   void processText()
   {
       cout << "give text";
         string input;
         getline(cin,input);  // reads the whole line. cin reads only the first word. 
         transform(input.begin(), input.end(), input.begin(),::toupper); //transforms every letter to uppercase
         cout << "Uppercase: " <<input<< endl; // Tulostetaan  isolla kirjaimet
   
   //VOWEL
     int vowelCount=0; //formating the counter to 0
     for (char c : input) // checking every letter
    {
       if (isVowel(c)) //if letter is vowel(toupper is true) add +1 to the counter
          vowelCount++;
    }
    cout << "number of vowels: " << vowelCount <<endl; // displaying the  amount of vowels

    string reversedText = input; //copying the original text
    reverse(reversedText.begin(), reversedText.end()); //reversing the text
    cout <<"Reversed text:"<<reversedText<<endl; //displaying the reversed text
   }
}

int main() //clling for the uppercase1 code
{
   uppercase1::processText();
   return 0;
}