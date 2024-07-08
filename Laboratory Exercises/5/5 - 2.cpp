/*
Да се дефинира класа Book, која репрезентира една книга. За класата Book се чуваат:

Наслов (текстуална низа од 30 знаци)
Сериски број (цел број)
Тип на книга (енумерациски тип, стручна литература или роман) 
цена (децимален број)
Серискиот број е единствен за секоја книга, неговата почетна вредност е 777550.  Да се обезбеди секвенцијално генерирање на овој број, така што првата сметка ќе има идентификациски број 777551, втората 777552, третата 777553 итн. (5 поени)

За оваа класа да се обезбедат потребните конструктори, set и get методи. (5 поени).

 Да се имплементира оператор за печатење << со кој ќе се печатат информациите за секој објект во формат: [сериски број]-[наслов] [тип] [цена] (5 поени).

Да се имплементира оператор += кој како аргумент ќе прима реален број, што ќе ја означува маржата од дадена книга и ќе се додаде на цената на книгата. (5 поени).

Потоа да се дефинира класа BookStore, во која се чуваат информации за:

Име (текстуална низа од 20 знаци)
Листа од книги (динамички алоцирана низа објекти од класата Book)
Број на сметки (број на елементи во низата од книги, иницијално е 0)
За оваа класа да се дефинираат потребните конструктори, деструктор, set и get методи.  (5 поени).

Оператор за печатење << во формат [име] и сите книги поединечно (види формат во тест примерите). (5 поени).

Oператор += за додавање нова книга во продавницата. Во продавницата книгите се менаџираат според нивниот сериски број кој е уникатен. Во продавницата не смее да се дозволи додавање нова книга со сериски број кој веќе постои во продавницата. (10 поени).

Оператор  > кој споредува продавници според бројот на книги во продавницата. (5 поени).

Да се дефинира метод void createMarketPrice() - со кој продавницата генерира продажни цени на сите книги. Продажните цени се пресметуваат во зависност од тоа за каков тип на литература станува збор. За стручна литература на цената на книгата се додава 5% од цената, а за романи се додава 3%. (10 поени). 

Да се дефинира глобален метод best() - кој прима низа од објекти од класатa BookStore и бројот на продавници, а ја враќа онаа продавница која има најмногу книги. Доколку повеќе продавници имаат ист број на книги се враќа онаа која е прва најдена. (5 поени)

 ---------------------------------------------------------------------------------------------------------------------------

Define the class Book, which represents a single book. The class Book holds:

Title (a textual array of 30 characters)
Serial number (integer)
Type of book (enumerated type, academic or roman)
Price (decimal number)
The serial number is unique for each book, with its initial value being 777550. Sequential generation of this number is ensured, so the first book will have the serial number 777551, the second 777552, the third 777553, and so on.(5 points)

For this class, provide the necessary constructors, set and get methods. (5 points)

Implement the << operator to print the information for each object in the format: [serial number]-[title] [type] [price] (5 points).

Implement the += operator which takes a real number as an argument, representing the margin of a given book, and adds it to the book's price. (5 points)

Then, define the class BookStore , which stores information about:

Name (a textual array of 20 characters)
List of books (dynamically allocated array of Book objects)
Number of books (number of elements in the array of books, initially 0)
For this class, define the necessary constructors, destructor, set and get methods. (5 points)

Implement the << operator in the format [name] and all individual books. (5 points)

Implement the += operator to add a new book to the store. Books in the store are managed according to their unique serial number. Adding a new book with a serial number that already exists in the store is not allowed. (10 points)

Implement the > operator to compare stores based on the number of books in the store. (5 points)

Define a method void createMarketPrice() that generates selling prices for new books in the store. Selling prices are calculated depending on the type of literature. For academic literature, 5% of the price is added to the book's price, while for the romans, 3% is added. (10 points)

Define a global method best(), which takes an array of BookStore objects and the number of the stores, and returns the store with the most books. If multiple stores have the same number of books, the first one found is returned. (5 points)



For example:

Input	Result
1
TESTING BOOK OPERATOR <<
777551 - Object-oriented programming academic 2300
777552 - Discrete Mathematics academic 1800
777553 - Crime and punishment roman 950
TEST PASSED
4
TESTING BOOKSTORE OPERATOR += and <<
The Book Cellar
777551 - Object-oriented programming academic 2300
777552 - Discrete Mathematics academic 1800
777553 - Crime and punishment roman 950
TEST PASSED
6
TESTING BOOKSTORE COPY-CONSTRUCTOR and OPERATOR =
The Book Cellar
777551 - Object-oriented programming academic 2300
777552 - Discrete Mathematics academic 1800
777553 - Crime and punishment roman 950
Word Wizardry Books
777554 - Anna Karenina roman 1200
777555 - Calculus 1 academic 1320
TEST PASSED
7
TESTING BOOKSTORE OPERATOR >
TEST PASSED
8
3
The Book Cellar
3
Object-oriented_code 0 2300
Discrete_Mathematics 0 1800
Crime_and_punishment 1 950
Word Wizardry Book
2
Anna_Karenina 1 1200
Calculus_1 0 1320
The Literary Lounge
1
Looking_for_Alaska 0 500
TESTING METHOD createMarketPrice()
The Book Cellar
777551 - Object-oriented_code academic 2300
777552 - Discrete_Mathematics academic 1800
777553 - Crime_and_punishment roman 950
CREATED MARKET PRICES
The Book Cellar
777551 - Object-oriented_code academic 2415
777552 - Discrete_Mathematics academic 1890
777553 - Crime_and_punishment roman 978.5
Word Wizardry Book
777554 - Anna_Karenina roman 1200
777555 - Calculus_1 academic 1320
CREATED MARKET PRICES
Word Wizardry Book
777554 - Anna_Karenina roman 1236
777555 - Calculus_1 academic 1386
The Literary Lounge
777556 - Looking_for_Alaska academic 500
CREATED MARKET PRICES
The Literary Lounge
777556 - Looking_for_Alaska academic 525
9
3
The Book Cellar
3
Object-oriented_code 0 2300
Discrete_Mathematics 0 1800
Crime_and_punishment 1 950
Word Wizardry Book
2
Anna_Karenina 1 1200
Calculus_1 0 1320
The Literary Lounge
1
Looking_for_Alaska 0 500
TESTING METHOD best()
The Book Cellar
777551 - Object-oriented_code academic 2300
777552 - Discrete_Mathematics academic 1800
777553 - Crime_and_punishment roman 950
*/

#include <iostream>
#include <cstring>
using namespace std;

enum Type{academic, roman};
class Book
{
private:
    char title[30];
    int id;
    static int TOTAL;
    const static int ID_init;
    Type type;
    float price;
public:
    Book(){}
    Book(const char *title,int type, float price)
    {
        strcpy(this->title,title);
        TOTAL++;
        id=ID_init+TOTAL;
        this->type=(Type)type;
        this->price=price;
    }
    friend ostream &operator<<(ostream &out,Book &b)
    {
        out<<b.id<<" - "<<b.title<<" ";
        if(b.type==academic)
            out<<"academic ";
        else
            out<<"roman ";
        out<<b.price<<endl;
        return out;
    }
    Book& operator+=(float amount)
    {
        price+=amount;
        return *this;
    }
    bool isSame(const Book &b)
    {
        return id==b.id;
    }
    Type getType()
    {
        return type;
    }
    float getPrice()
    {
        return price;
    }
};

int Book::TOTAL=0;
const int Book::ID_init=777550;

class BookStore
{
private:
    char name[20];
    Book *books;
    int numOfBooks;
public:
    BookStore(const char *name="")
    {
        strcpy(this->name,name);
        books= nullptr;
        numOfBooks=0;
    }
    BookStore(const BookStore &b)
    {
        strcpy(this->name,b.name);
        numOfBooks=b.numOfBooks;
        books=new Book[numOfBooks];
        for(int i=0;i<numOfBooks;i++)
        {
            books[i]=b.books[i];
        }
    }
    BookStore& operator=(const BookStore &b)
    {
        if (this != &b)
        {
            delete[] books;
            strcpy(this->name, b.name);
            numOfBooks = b.numOfBooks;
            books = new Book[numOfBooks];
            for (int i = 0; i < numOfBooks; i++)
            {
                books[i] = b.books[i];
            }
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out,const BookStore &b)
    {
        out<<b.name<<endl;
        for(int i=0;i<b.numOfBooks;i++)
        {
            out<<b.books[i];
        }
        return out;
    }
    bool operator>(const BookStore &b)
    {
        return numOfBooks>b.numOfBooks;
    }
    BookStore &operator+=(const Book &a)
    {
        for(int i=0;i<numOfBooks;i++)
        {
            if(books[i].isSame(a))
            {
                return *this;
            }
        }
        Book *tmp=new Book[numOfBooks+1];
        for(int i=0;i<numOfBooks;i++)
        {
            tmp[i]=books[i];
        }
        tmp[numOfBooks++]=a;
        delete [] books;
        books=tmp;
        return *this;
    }
    void createMarketPrice()
    {
        for(int i=0;i<numOfBooks;i++)
        {
            if(books[i].getType() == academic)
            {
                float fee=books[i].getPrice()*0.05;
                books[i]+=fee;
            }
            else
            {   float fee=books[i].getPrice()*0.03;
                books[i]+=fee;
            }
        }
    }
    ~BookStore(){
        delete [] books;
    }
};
BookStore best(BookStore *books, int n)
{
    BookStore b=books[0];
    for(int i=1;i<n;i++)
    {
        if(books[i]>b)
        {
            b=books[i];
        }
    }
    return b;
}

int main() {
    int testCase;
    cin>>testCase;
    if(testCase==0)
    {
        cout<<"TESTING BOOK CONSTRUCTOR"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==1)
    {
        cout<<"TESTING BOOK OPERATOR <<"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        cout<<book1;
        cout<<book2;
        cout<<book3;
        cout<<"TEST PASSED"<<endl;
    } else if(testCase==2)
    {
        cout<<"TESTING BOOK OPERATOR +="<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        cout<<book1;
        cout<<book2;
        cout<<book3;
        book1+=200;
        book2+=300;
        book3+=150;
        cout<<"===== INCREASE ====="<<endl;
        cout<<book1;
        cout<<book2;
        cout<<book3;
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==3)
    {
        cout<<"TESTING BOOKSTORE CONSTRUCTOR"<<endl;
        BookStore bookStore1("The Book Cellar");
        cout<<bookStore1;
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==4)
    {
        cout<<"TESTING BOOKSTORE OPERATOR += and <<"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        BookStore bookStore1("The Book Cellar");
        bookStore1+=book1;
        bookStore1+=book2;
        bookStore1+=book3;
        cout<<bookStore1;
        cout<<"TEST PASSED"<<endl;
    }
    else if(testCase==5)
    {
        cout<<"TESTING BOOKSTORE OPERATOR += and <<"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        BookStore bookStore1("The Book Cellar");
        bookStore1+=book1;
        bookStore1+=book2;
        bookStore1+=book3;
        cout<<bookStore1;
        bookStore1+=book1;
        cout<<"TEST PASSED"<<endl;
    }
    else if(testCase==6)
    {
        cout<<"TESTING BOOKSTORE COPY-CONSTRUCTOR and OPERATOR ="<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        Book book4("Anna Karenina",1,1200);
        Book book5("Calculus 1",0,1320);
        BookStore bookStore1("The Book Cellar");
        bookStore1+=book1;
        bookStore1+=book2;
        bookStore1+=book3;
        BookStore bookStore2(bookStore1);
        BookStore bookStore4;
        {
            BookStore bookStore3("Word Wizardry Books");
            bookStore3+=book4;
            bookStore3+=book5;
            bookStore4=bookStore3;
        }
        cout<<bookStore2;
        cout<<bookStore4;
        cout<<"TEST PASSED"<<endl;
        
    }else if(testCase==7)
    {
        cout<<"TESTING BOOKSTORE OPERATOR > "<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        Book book4("Anna Karenina",1,1200);
        Book book5("Calculus 1",0,1320);
        BookStore bookStore1("The Book Cellar");
        bookStore1+=book1;
        bookStore1+=book2;
        bookStore1+=book3;
        BookStore bookStore3("Word Wizardry Books");
        bookStore3+=book4;
        bookStore3+=book5;
        if(bookStore1>bookStore3)
        {
            cout<<"TEST PASSED"<<endl;
        }
        else
        {
            cout<<"TEST FAILED"<<endl;
        }
    }else if(testCase==8)
    {
        cout<<"TESTING METHOD createMarketPrice()"<<endl;
        char name[30],name1[30];
        int type, numofBookStores, numberOfBooks;
        float price;
        cin>>numofBookStores;
        cin.ignore();
        BookStore bookStores[10];
        for(int i=0;i<numofBookStores;i++)
        {
            cin.getline(name,20);
            bookStores[i]=BookStore(name);
            cin>>numberOfBooks;
            cin.ignore();
            Book books[10];
            for(int j=0;j<numberOfBooks;j++)
            {
                cin >> name1 >> type >> price;
                cin.ignore();
                books[j]=Book(name1,type,price);
                bookStores[i]+=books[j];
            }
        }
        for(int i=0;i<numofBookStores;i++)
        {
            cout<<bookStores[i];
            cout<<"CREATED MARKET PRICES"<<endl;
            bookStores[i].createMarketPrice();
            cout<<bookStores[i];
        }

    }else if(testCase==9)
    {
        cout<<"TESTING METHOD best()"<<endl;
        char name[30],name1[30];
        int type, numofBookStores, numberOfBooks;
        float price;
        cin>>numofBookStores;
        cin.ignore();
        BookStore bookStores[10];
        for(int i=0;i<numofBookStores;i++)
        {
            cin.getline(name,20);
            bookStores[i]=BookStore(name);
            cin>>numberOfBooks;
            cin.ignore();
            Book books[10];
            for(int j=0;j<numberOfBooks;j++)
            {
                cin >> name1 >> type >> price;
                cin.ignore();
                books[j]=Book(name1,type,price);
                bookStores[i]+=books[j];
            }
        }
        cout<<best(bookStores,numofBookStores);
    }
    return 0;
}