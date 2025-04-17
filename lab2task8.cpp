#include <iostream>

int main(){
    int a = 200;
    int & refA=a;

    std::cout<<"before editing refA:"<<std::endl;
    std::cout<<"a=" <<a<<std::endl;
    std::cout<<"refA="<<refA<<std::endl;

    refA = 20;

    std::cout<<"\nafter editing refA"<<std::endl;
    std::cout<<"a="<<a<<std::endl;
    std::cout<<"refA=" <<refA<<std::endl;

    return 0;
}