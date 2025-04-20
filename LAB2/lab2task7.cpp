#include <iostream>

int main(){

    int x = 100;

    int*p1=&x;

    int*p2=p1;

    std::cout<<"X value:"<<x<<std::endl;

    *p1=205;

    std::cout<<"modified:"<<x<<std::endl;
    
    std::cout<<"value through p2:"<<*p2<<std::endl;

    return 0;
}