#include <iostream>
using namespace std;

namespace MathOperations
{

int add(int a,int b)
{
    return a+b;

}
}

namespace TextOperations
{

string concat(string a,string b)
{
    return a+b;
}
}

int main ()
{

cout << MathOperations::add(5,2);
cout << TextOperations::concat("puolijohde","levy");

}

