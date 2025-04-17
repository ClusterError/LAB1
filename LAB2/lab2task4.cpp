#include <iostream>

int main(){
    float A1,B1;
    std::cout<<"input number to be squared"<<std::endl;
    std::cin>>A1;

    while (true){
    
        if (A1<0){
        std::cout << "negative number given. Self destruction initiated. BOOM!\n";    
        break;}

        if (A1==0)
        {
            std::cout<<"do not input 0"<<std::endl;
            std::cin>>A1;
            continue;
        }
        
        B1=A1*A1;
        std::cout<<"squared value is: "<<B1<<std::endl;
        std::cout<<"input number to be squared"<<std::endl;
        std::cin>>A1;
    }
}