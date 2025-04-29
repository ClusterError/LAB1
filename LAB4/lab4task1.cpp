#include <iostream>
#include <string>
using namespace std;

class Complex {
    private:
        double real;
        double img;

    public:
        // Constructor. Setting def val to 0. This seperates inputs like (4,5) to real 4 and img 5.
        //These can lter be used in the overloaded functions. 
        Complex(double R = 0, double I = 0): real(R), img(I) {
        }

        // Overloading the + operator to add two complex numbers. = making it able to calculate complex numbers
        // const complex& other -> the second complex number you are dividing by
        Complex operator+(const Complex& other) {
            // Add real and imaginary parts separately
            int realSum = this->real + other.real;
            int imgSum = this->img + other.img;

            //this points to the CURRENT object eg. c1. other.real points to OTHER object eg c2. 
            
            // Return a new complex number with the summed parts
            return Complex(realSum, imgSum);
        }

        // Overload the - operator to subtract two complex numbers
        Complex operator-(const Complex& other) {
            // Subtract real and imaginary parts separately
            int realDiff = this->real - other.real;
            int imgDiff = this->img - other.img;

            // Return a new complex number with - calculater
            return Complex(realDiff, imgDiff);
        }

        // Overload the / operator to divide two complex numbers
        Complex operator/(const Complex& other) {
            double denominator = other.real * other.real + other.img * other.img; // (a+bi)/(c+di) -> denominator is (c^2 + d^2)
            double realPart = (this->real * other.real + this->img * other.img) / denominator;
            double imgPart = (this->img * other.real - this->real * other.img) / denominator;

            // Return a new complex number representing the quotient
            return Complex(realPart, imgPart);
        }

        // Friend function to overload the << operator for output (??? look into friend more)
        friend ostream& operator<<(ostream& out, const Complex& c);
};

// Overload the << operator for printing Complex numbers in the form a + bi
ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real;
    if (c.img >= 0) {
        out << " + " << c.img << "i"; // Display as a + bi
    } else {
        out << " - " << -c.img << "i"; // Display as a - bi for negative imaginary part
    }
    return out;
}

// if the  values inserted are Complex(x,y) the code sees "hmm yes complex"
// and tries to search if specific function for Complex has been assigned. 



int main() {
    Complex c1(4, 5), c2(2, -3);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "Sum = " << c1 + c2 << endl;
    cout << "Difference = " << c1 - c2 << endl;
    cout << "Quotient = " << c1 / c2 << endl;

    return 0;
}
