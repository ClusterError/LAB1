#include <iostream>

void swp(float a1, float b1){
    float c1 = a1;
    a1 = b1;
    b1 = c1;

    std::cout << "swap without pointers or ref: a = " << a1 << ", b = " << b1 << std::endl;

    // does not swap the original values in the main()
}

void swppointer (float *a2, float *b2){
float temp2 = *a2;
*a2=*b2;
*b2=temp2;

//swaps original values and also a list of other uses i dont quite unterstand. displays in "computer language"
}

void swpref (float &a3, float &b3){
float temp3 = a3;
a3=b3;
b3=temp3;
// swaps original values but instead displays in "human language" i can unterstand easily. 
}

int main() {
    float a1 = 1.5;
    float b1 = 4.5;
    float a2 = 2.7;
    float b2 = 5.7;
    float a3 = 3.7;
    float b3 = 6.7;

    std::cout << "Before swap: a = " << a1 << ", b = " << b1 << std::endl;
    std::cout << "Before swap with pointers : a = " << &a2 << ", b = " << &b2 << std::endl;

    swp(a1, b1); 
    swppointer(&a2,&b2);
    swpref(a3, b3);

    std::cout << "After swap no pointer or ref in main() : a = " << a1 << ", b = " << b1 << std::endl;
    //swapping without pointers or ref shouldnt work in main() but i will keep this line for visualizing.
    std::cout << "After swap with pointers : a = " << &a2 << ", b = " << &b2 << std::endl;
    std::cout << "After swap with references : a = " << a3 << ", b = " << b3 << std::endl;

    return 0;
}
