/*
Да се дефинира класа Movie во која ќе се чуваат информации за филм:

ID (целобројна вредност)

Име (текстуална низа од 30 карактери)

Жанр (енумерација - HORROR, COMEDY, DOCUMENTARY)

Цена (реална вредност) 

За класата да се имплементираат:

Потребните конструктори, деструктор, set и get методи (5 поени)

Оператор за печатење << во формат [име] [жанр] [цена на билет] (5 поени)

Оператор == за споредување на два филма според ID (5 поени)

Оператор += за зголемување на цената на билетот за одреден процент (реален број) предаден како аргумент (5 поени)

Да се дефинира класа Cinema во која ќе се чуваат информации за кино:

Име (текстуална низа од 40 карактери)

Филмови (динамичка алоцирана низа објекти од класата Movie)

Број на филмови (број на елементи во низата од филмови, иницијално е 0)

Попуст за лојални корисници (целобројна вредност која може да се менува на ниво на сите кина)

За класата да се имплементираат:

Потребните конструктори, деструктор, set и get методи (5 поени)

Оператор += за додавање нов филм доколку не постои во низата (10 поени)

Оператор < кој споредува двe кина според бројот на филмови. (5 поени)

Метода increase() којашто прима два аргументи,  жанр и процент на зголемување и ги зголемува цените на сите филмови од соодветниот жанр за соодвениот процент (10 поени)

Оператор за печатење << во формат [име] филмови: сите филмови поединечно и попуст за лојални корисници. ( формат во тест примерите)(5 поени)


Да се дефинира глобален метод smallestChoice() - кој прима низа од објекти од класатa Cinema и број на кина, а го враќа она кино кое има најмал број на филмови што ги нуди. Доколку повеќе кина имаат ист минимален број на филмови, се враќа првонајдениот. (5 поени)






For example:

Input	Result
1
TESTING MOVIE OPERATOR <<
Imaginary 0 300
Hangover 1 350
Stormy 2 300
TEST PASSED
4
TESTING CINEMA OPERATOR += and <<
Cineplexx movies:
Imaginary 0 300
Hangover 1 350
Stormy 2 300
20

TEST PASSED
*/

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Cinema;

enum Genre{
    HORROR, COMEDY, DOCUMENTARY
};

class Movie{
    private:
        int id;
        char name[30];
        Genre genre;
        float price;
    public:
        Movie(){}
        
        Movie(int id, const char *name, Genre genre, float price){
            this->id = id;
            strcpy(this->name, name);
            this->genre = genre;
            this->price = price;
        }
        
        ~Movie(){}
        
        Genre getGenre(){
            return genre;
        }
        
        bool operator==(const Movie &other){
            return (id == other.id);
        }
        
        Movie &operator+=(float percent){
            this->price += this->price * (percent / 100);
            return *this;
        }
        
        friend ostream &operator<<(ostream &res,const Movie &movie){
            res << movie.name << " " << movie.genre << " " << movie.price << endl;
            return res;
        }
        
        friend Cinema;
};

class Cinema{
    private:
        char name[20];
        Movie *Movies;
        int movieNum = 0;
        static float LOYAL_DISCOUNT;
        
        void Copy(const Cinema &other){
            strcpy(this->name, other.name);
            this->movieNum = other.movieNum;
            this->Movies = new Movie[this->movieNum];
            
            for(int i = 0; i < this->movieNum; i++){
                Movies[i] = other.Movies[i];
            }
        }
    public:
        Cinema(){}
        
        Cinema(const char *name){
            strcpy(this->name, name);
            this->movieNum = 0;
            this->Movies = new Movie[movieNum];
        }
        
        Cinema(const Cinema &other){
            Copy(other);
        }
        
        ~Cinema(){
            delete []Movies;
        }
        
        friend ostream& operator<<(ostream &res, const Cinema &c){
            res<<c.name;
            return res;
        }
        
        static void setLOYAL_DISCOUNT(float newDisc){
            LOYAL_DISCOUNT = newDisc;
        }
        
        void increase(Genre g, float p){
            for (int i=0;i<movieNum;i++){
                if(Movies[i].getGenre()==g){
                    Movies[i]+=p;
                }
            }
        }
        
        bool operator<(Cinema &other){
            return (this->movieNum < other.movieNum);
        }
        
        Cinema &operator+=(Movie &movie){
            bool exists=false;
            for (int i=0;i<movieNum;i++) {
                if (Movies[i] == movie) {
                    exists = true;
                    break;
                }
            }
            if(!exists){
               Movie *tmp= new Movie[movieNum+1];
                for (int i=0;i<movieNum;i++){
                    tmp[i]= Movies[i];
                }
                delete [] Movies;
                tmp[movieNum++] = movie;
                Movies=tmp;
            }
            return *this;
        }
        
        Cinema &operator=(const Cinema &other){
            if(this!=&other){
                 Copy(other);
            }
            return *this;
        }
        
        friend ostream &operator<<(ostream &res, Cinema &cinema){
            res << cinema.name << " movies: " << endl;
            for(int i = 0; i < cinema.movieNum; i++){
                res << cinema.Movies[i];
            }
            res << LOYAL_DISCOUNT << endl;
            return res;
        }
};

float Cinema::LOYAL_DISCOUNT = 10.0;

Cinema smallestChoice(Cinema *cinema, int n){
    Cinema res = cinema[0];
    for(int i = 0; i < n; i++){
        if(cinema[i] < res){
            res = cinema[i];
        }
    }
    return res;
}

int main(){
    int test_case;
    cin >> test_case;

    switch (test_case) {
        case 0: {
            cout << "TESTING MOVIE CONSTRUCTOR" << endl;

            Movie movie1(0, "Imaginary", Genre::HORROR, 300);
            Movie movie2(1, "Hangover", Genre::COMEDY, 350);
            Movie movie3(2, "Stormy", Genre::DOCUMENTARY, 300);

            cout << "TEST PASSED" << endl;
            break;
        }
        case 1: {
            cout<<"TESTING MOVIE OPERATOR <<"<<endl;

            Movie movie1(0, "Imaginary", Genre::HORROR, 300);
            Movie movie2(1, "Hangover", Genre::COMEDY, 350);
            Movie movie3(2, "Stormy", Genre::DOCUMENTARY, 300);

            cout << movie1;
            cout << movie2;
            cout << movie3;

            cout << "TEST PASSED" << endl;
            break;
        }
        case 2: {
            cout<<"TESTING MOVIE OPERATOR +="<<endl;

            Movie movie1(0, "Imaginary", Genre::HORROR, 300);
            Movie movie2(1, "Hangover", Genre::COMEDY, 350);
            Movie movie3(2, "Stormy", Genre::DOCUMENTARY, 300);

            cout << movie1;
            cout << movie2;
            cout << movie3;

            movie1 += 15;
            movie2 += 25.5;
            movie3 += 37;

            cout << movie1;
            cout << movie2;
            cout << movie3;

            cout << "TEST PASSED" << endl;
            break;
        }
        case 3: {
            cout<<"TESTING CINEMA CONSTRUCTOR and <<"<<endl;

            Cinema cinema("Cineplexx");
            cout << cinema;

            cout << "TEST PASSED" << endl;
            break;
        }
        case 4: {
            cout<<"TESTING CINEMA OPERATOR += and <<"<<endl;

            Movie movie(0, "Imaginary", Genre::HORROR, 300);
            Movie movie1(1, "Hangover", Genre::COMEDY, 350);
            Movie movie2(2, "Stormy", Genre::DOCUMENTARY, 300);

            Cinema cinema("Cineplexx");

            cinema += movie;
            cinema += movie1;
            cinema += movie2;

            Cinema::setLOYAL_DISCOUNT(20);
            cout << cinema << endl;

            cout << "TEST PASSED" << endl;
            break;
        }
        case 5: {
            cout<<"TESTING CINEMA OPERATOR += and <<"<<endl;

            Movie movie(0, "Imaginary", Genre::HORROR, 300);
            Movie movie1(1, "Hangover", Genre::COMEDY, 350);
            Movie movie2(2, "Stormy", Genre::DOCUMENTARY, 300);

            Cinema cinema("Cineplexx");

            cinema += movie;
            cinema += movie1;
            cinema += movie2;
            cinema += movie2;

            Cinema::setLOYAL_DISCOUNT(25);
            cout << cinema << endl;

            cout << "TEST PASSED" << endl;
            break;
        }
        case 6: {
            cout<<"TESTING CINEMA COPY-CONSTRUCTOR and OPERATOR ="<<endl;

            Movie movie(0, "Imaginary", Genre::HORROR, 300);
            Movie movie1(1, "Hangover", Genre::COMEDY, 350);
            Movie movie2(2, "Stormy", Genre::DOCUMENTARY, 300);
            Movie movie3(3, "Omen", Genre::HORROR, 300);
            Movie movie4(4, "Argylle", Genre::COMEDY, 350);

            Cinema cinema1("Cineplexx");

            cinema1 += movie;
            cinema1 += movie1;
            cinema1 += movie2;


            Cinema cinema2(cinema1);
            Cinema cinema4;
            {
                Cinema cinema3("Galaxy");
                cinema3 += movie3;
                cinema3 += movie4;
                cinema4 = cinema3;
            }

            cout << cinema2;
            cout << cinema4;

            cout << "TEST PASSED" << endl;
            break;
        }
        case 7: {
            cout<<"TESTING CINEMA OPERATOR < "<<endl;
            Movie horror(0, "Imaginary", Genre::HORROR, 300);
            Movie comedy(1, "Hangover", Genre::COMEDY, 350);
            Movie documentary(2, "Stormy", Genre::DOCUMENTARY, 300);

            Movie horror1(0, "Omen", Genre::HORROR, 300);
            Movie comedy1(3, "Argylle", Genre::COMEDY, 350);
            Movie documentary1(2, "Christspiracy", Genre::DOCUMENTARY, 300);

            Cinema cinema1("Galaxy");
            cinema1 += horror;
            cinema1 += comedy;
            cinema1 += documentary;

            Cinema cinema2("Encore");
            cinema2 += horror1;
            cinema2 += comedy;
            cinema2 += comedy1;
            cinema2 += documentary1;

            if (cinema1 < cinema2) {
                cout << "TEST PASSED" << endl;
            }
            break;

        }
        case 8: {
            cout<<"TESTING METHOD increase"<<endl;

            char name[40];
            cin.ignore();
            cin.getline(name, 40);

            Cinema cinema(name);

            int n;
            cin >> n;

            int id;
            char title[30];
            int genre;
            float cost;
            float percent;

            for (int i = 0; i < n; i++) {
                cin >> id;
                cin.ignore();
                cin.getline(title, 30);
                cin >> genre;
                cin >> cost;

                Movie movie(id, title, (Genre) genre, cost);
                cinema += movie;
            }

            cin >> percent;
            cin >> genre;
            cout << cinema << endl;
            cinema.increase((Genre)genre, percent);
            cout << cinema << endl;

            cout << "TEST PASSED" << endl;
            break;
        }
        case 9: {
            cout<<"TESTING METHOD smallestChoiceCinema"<<endl;

            int n;
            cin >> n;
            Cinema cinemas[n];
            char name[40];

            for (int i = 0; i < n; i++) {
                cin.ignore();
                cin.getline(name, 40);
                Cinema cinema(name);

                int m;
                cin >> m;

                int id;
                char title[30];
                int genre;
                float cost;

                for (int j = 0; j < m; j++) {
                    cin >> id;
                    cin.ignore();
                    cin.getline(title, 30);
                    cin >> genre;
                    cin >> cost;

                    Movie movie(id, title, (Genre) genre, cost);
                    cinema += movie;
                }

                cinemas[i] = cinema;
            }

            Cinema smallestChoiceCinema = smallestChoice(cinemas, n);
            cout << smallestChoiceCinema << endl;

            cout << "TEST PASSED" << endl;

            break;
        }
    }
    return 0;
}