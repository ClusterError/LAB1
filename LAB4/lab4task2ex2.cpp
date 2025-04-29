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
        cout << "Constructor: \""<< title << "\" with " << pages << "pages\n";
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

class BookShelf {
    private:
    Book* books;
    int size;

    public:
    // constructor dynamically create array and initialize it
    BookShelf(){
        size=3;
        books=new Book[size]{
        Book("C++ Fundamentals", 300),
        Book("Data structures", 450),
        Book("Algorithms", 500),
        };
        cout << "Bookshelf constructor: sheld initialized with " << size << " books \n";
    }
    // destrcutor: clean up heap memroy
    ~BookShelf(){
        delete[]books;
        cout<<"Bookshelf destructor: Shelf destroyed\n";
    }
    void displayBook() const {
        cout << "\nBooks on shelf:\n";
        for (int i=0;i<size;++i){
            books[i].display();
        }
    }
};


int main(){
    BookShelf* shelf = new BookShelf();
    shelf->displayBook();

    delete shelf;
    cout << "\n - - -end of program- - -";
    return 0;
}