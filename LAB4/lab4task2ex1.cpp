#include <iostream>
#include <string>
using namespace std;

class Book {
    private:
        string title;
        int pages;

    public:
    //constuctor
    Book(string t = "Untitled", int p=0) : title(t), pages(p) {
        cout << "Constructor: \""<< title << "\" with" << pages << "pages\n";
    }
    // DESCTRUCT!!
    ~Book(){
        cout << "Destructor: \"" << title << "\" destroyed \n";
    }
    // diplsay book info
    void display() const {
        cout << "Title:" << title << ", Pages: " << pages << endl;
    }
};

int main(){
    // array of 3 book objectives
    
    Book library[3] = {
        Book("C++ Fundamentals", 300),
        Book("Data structures", 450),
        Book("Algorithms", 500),
    };

    cout << "\n---Library Contents --- \n";
    return 0;
}