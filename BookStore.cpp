#include <bits/stdc++.h>

using namespace std;

class Customer;

class Category{
    string customer_name;

public:
    Category(){
    }

    Category(string customer_name){
        this->customer_name = customer_name;
    }

    string get_name(){
        return customer_name;
    }
};

class Writer{
    string name;

public:
    Writer(){
    }

    Writer(string name){
        this->name = name;
    }

    string get_name(){
        return name;
    }
};

class Book{             ///book details
    string title;
    string category;
    string writer;
    double price;
    string edition_no;
    int quantity;
public:

    Book(){
    }

    Book(string title, Category c, Writer w, double price, string edition_no, int quantity){
        this->title = title;
        this->category = c.get_name();
        this->writer = w.get_name();
        this->price = price;
        this->edition_no = edition_no;
        this->quantity = quantity;
    }

    void display(){
        cout << "Book Title: " << title << endl;
        cout << "Category Name: " << category << endl;
        cout << "Writer Name: " << writer << endl;
        cout << "Price: " << price << endl;
        cout << "Edition Number: " << edition_no << endl;
        cout << "Remaining  Stock: " << quantity << endl << endl;
    }

    friend void buyBooks(Customer customer, Book book);


};


class Person{         ///customer details
public:
    string name;
    Person(){
    }
    Person(string name){
        this->name = name;
    }
};

class Customer: public Person{
    int books_count;
    string address;
public:
    Customer(){
    }

    Customer(string name,  string address): Person(name){
        this->address = address;
    }
    void display(){
        cout << "Customer Name: " << name << endl;
        cout << "Customer Address: " << address << endl;
        cout << "Number of Books Brought: " << books_count << endl<< endl;
        //cout << "-----------------------------------"<< endl << endl;
    }

    friend void buyBooks(Customer customer, Book book);
};

void buyBooks(Customer customer, Book book){ ///price and update
    double d_price;

    if (customer.books_count >= 5){
        d_price = book.price - (book.price*10)/100;
    }
    else {
        d_price = book.price;
    }

    cout << customer.name << " has brought " << book.title << " at " << d_price << endl << endl;
    book.quantity = book.quantity-1;
    customer.books_count += 1;
    cout << "Book Information Update: " << endl;
    book.display();


}

int main(){

    Category category1("Science");
    Category category2("Technology");

    Writer writer1("Mark");
    Writer writer2("John");

    Book book1("Quantam Physics", category1, writer1, 400.00, "sc007", 500);
    Book book2("Internet of Things", category2, writer2, 600.00, "tc577", 400);

    cout << "Book Information: " << endl;
    book1.display();
    book2.display();

    cout << "Customer Information: " << endl;
    Customer customer1("Rima", "Comilla");
    customer1.display();

    cout << "Book Buy: " << endl;
    buyBooks(customer1, book1);

}
