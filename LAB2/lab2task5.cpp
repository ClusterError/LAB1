#include <iostream>

int main(){
int A1[5]={1,4,7,10,15};
int A2[5]={0,0,0,0,0};
int * from = A1; //traversing the array
int * to = A2;

int i;


    for (int i = 0; i < 5; i++)
{
    *(to+i)=*(from+(4-i));
    std::cout<<*(A2+i)<<",";
}
}
