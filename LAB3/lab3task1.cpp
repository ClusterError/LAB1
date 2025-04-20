#include <iostream>
#include <string>

using namespace std;

class Book {
private: 
    string title;
    int pages;
    string author;
protected:
    float price;
public:
    string publisher;
    void setAuthor(string a){
    author = a;
        }
    void displayAuthorInfo(){
    std::cout<<"Author: "<< author << std::endl;
        }
    };

int main(){
Book Book;

Book.setAuthor("Vincent");
Book.displayAuthorInfo();

Book.publisher="Arasaka";

std::cout<<("Publisher:")<<Book.publisher<<std::endl;

}