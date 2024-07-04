/*
Да се дефинира класа Product за која се чуваат следните информации:



име на продуктот (низа од максимум 100 карактери)
id на продуктот (int)
категорија (низа од максимум 100 карактери)
цена (double)
количина (int)
Сите променливи треба да бидат приватни.

 Во класата да се реализираат:

default конструктор и конструктор со аргументи
set методи
get методи
print() метод за печатење на книга во формат: 
Name: , Id: , Price: , Quantity: 


Да се дефинира надворешна функција void printByCategory(Product *products, int n, const char *category ) која на екран ќе ги испечати сите продукти и вкупната сума на сите продукти од таа категорија.

Да не се менува main функцијата.

---


Define the class Product which stores the following information:

Product name (a string of up to 100 characters)
Product ID (int)
Category (a string of up to 100 characters)
Price (double)
Quantity (int)
All variables should be private.

The class should implement:

Default constructor and constructor with arguments
Set methods
Get methods
A print() method for printing a product in the format: Name: , Id: , Price: , Quantity:
Define an external function void printByCategory(Product *products, int n, const char *category) which will print to the screen all products and the total sum of all products from the given category.

Main function should not be changed.



For example:

Input	Result
0
---Testing constructor with arguments and print()---
Name: Book, Id: 1, Price: 14.99, Quantity: 3
1
---Testing get and set methods---
Name: Book
Id: 1
Category: Books
Price: 14.99
Quantity: 3
2
Laptop 1 Electronics 999.99 5
Shirt 2 Clothing 19.99 20
Book 3 Books 14.99 50
Phone 4 Electronics 899.99 8
Jeans 5 Clothing 29.99 15
Headphones 6 Electronics 149.99 10
Socks 7 Clothing 9.99 30
Notebook 8 Books 5.99 100
---Testing function---
Category: Electronics
Name: Laptop, Id: 1, Price: 999.99, Quantity: 5
Name: Phone, Id: 4, Price: 899.99, Quantity: 8
Name: Headphones, Id: 6, Price: 149.99, Quantity: 10
Total sum : 13699.8

Category: Clothing
Name: Shirt, Id: 2, Price: 19.99, Quantity: 20
Name: Jeans, Id: 5, Price: 29.99, Quantity: 15
Name: Socks, Id: 7, Price: 9.99, Quantity: 30
Total sum : 1149.35

Category: Books
Name: Book, Id: 3, Price: 14.99, Quantity: 50
Name: Notebook, Id: 8, Price: 5.99, Quantity: 100
Total sum : 1348.5
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Product{
        char name[100];
        int id;
        char category[100];
        double price;
        int quantity;
    public:
        Product(){}
        
        Product(char name[100], int id, char category[100], double price, int quantity){
            strcpy(this->name, name);
            this->id = id;
            strcpy(this->category, category);
            this->price = price;
            this->quantity = quantity;
        }
        
        ~Product(){}
        
        // Functions
        void setName(char *name){
            strcpy(this->name, name);
        }
        
        void setId(int id){
            this->id = id;
        }
        
        void setCategory(char category[100]){
            strcpy(this->category, category);
        }
        
        void setPrice(double price){
            this->price = price;
        }
        
        void setQuantity(int quantity){
            this->quantity = quantity;
        }
        
        char *getName(){
            return name;
        }
        
        int getId(){
            return id;
        }
        
        char *getCategory(){
            return category;
        }
        
        double getPrice(){
            return price;
        }
        
        int getQuantity(){
            return quantity;
        }
        
        void print(){
            cout<<"Name: "<<name<<", Id: "<<id<<", Price: "<<price<<", Quantity: "<<quantity<<endl;
        }
};

void printByCategory(Product *products, int n, const char *category ){
    double sum = 0;
    cout<<"Category: "<<category<<endl;
    for(int i = 0; i < n; i++){
        if(!strcmp(products[i].getCategory(), category)){
            products[i].print();
            sum += (products[i].getPrice() * products[i].getQuantity());
        }
    }
    cout<<"Total sum : "<< sum << endl;
}

int main()
{
    int m;
    cin>>m;
    if(m==0)
    {
        cout<<"---Testing constructor with arguments and print()---"<<"\n";
        char name[100]={'B','o','o','k'};
        int id = 1;
        char category [100] = {'B','o','o','k','s'};
        double price = 14.99;
        int quantity = 3;


        Product product = Product(name, id, category, price, quantity);

        product.print();
    }
    else if(m==1)
    {
        cout<<"---Testing get and set methods---"<<"\n";
        char name[100]={'B','o','o','k'};
        int id = 1;
        char category [100] = {'B','o','o','k','s'};
        double price = 14.99;
        int quantity = 3;
        Product product;
        product.setName(name);
        product.setId(id);
        product.setCategory(category);
        product.setPrice(price);
        product.setQuantity(quantity);
        cout<<"Name: "<<product.getName()<<endl;
        cout<<"Id: "<<product.getId()<<endl;
        cout<<"Category: "<<product.getCategory()<<endl;
        cout<<"Price: "<<product.getPrice()<<endl;
        cout<<"Quantity: "<<product.getQuantity()<<endl;

    }
    else if(m==2)
    {
        const int numProducts = 8;
        Product products[numProducts];

        for (int i = 0; i < numProducts; ++i) {
            char name[100];
            int id;
            char category[100];
            double price;
            int quantity;


            cin>>name>>id>>category>>price>>quantity;

            products[i] = Product(name, id, category, price, quantity);
        }


        cout<<"---Testing function---"<<"\n";
        printByCategory(products, numProducts, "Electronics");
        cout << endl;
        printByCategory(products, numProducts, "Clothing");
        cout << endl;
        printByCategory(products, numProducts, "Books");
    }
    return 0;
}
