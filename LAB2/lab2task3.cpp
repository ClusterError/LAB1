#include <iostream>

int main () {

int A1, B1, C1;
char D1;
std::cout<<"Hello this is calculator. \n Please enter first value. Note this program can only handle integers"<<std::endl;
std::cin>>A1;
std::cout<<"input another value."<<std::endl;
std::cin>>B1;
std::cout<<" what operation would you like to perform? Please select one from below by typing \n [+],[-], [*], [/]\n";
std::cin>>D1;

switch (D1) {
    case '+':
    C1=A1+B1;
    std::cout<<""<<A1<<"+"<<B1<<"="<<C1<<std::endl;
    break;

    case '-':
    C1=A1-B1;
    std::cout<<""<<A1<<"-"<<B1<<"="<<C1<<std::endl;
    break;

    case '*':
    C1=A1*B1;
    std::cout<<""<<A1<<"*"<<B1<<"="<<C1<<std::endl;
    break;

    case '/':
    C1=A1/B1;
    std::cout<<""<<A1<<"/"<<B1<<"="<<C1<<std::endl;
    break;

    }
return 0;
}

//this program cant handle decimals but in the task that wasnt exactly specified. 