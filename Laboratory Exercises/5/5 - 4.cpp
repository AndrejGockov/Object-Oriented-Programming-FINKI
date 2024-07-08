/*
Да се дефинира класа Brunch во која ќе се чуваат информации за oброк:

ID (целобројна вредност)
Име (текстуална низа од 30 карактери)
Цена (реална вредност) 
Тип (енумерација - APPETIZER, MAINCOURSE, DESSERT)
За класата да се имплементираат:

Потребните конструктори, деструктор, set и get методи (5 поени)
Оператор за печатење << во формат [име] [цена] [тип] (5 поени)
Оператор == за споредување на два оброка според ID (5 поени)
Оператор -= за намалување на цената на оброкот за одреден процент (реален број) предаден како аргумент (5 поени)
Да се дефинира класа Restaurant во која ќе се чуваат информации за ресторан:

Име (текстуална низа од 40 карактери)
Оброци (динамичка алоцирана низа објекти од класата Brunch)
Број на оброци (број на елементи во низата од оброци, иницијално е 0)
Попуст за лојални корисници (статичка целобројна вредност која може да се менува)
За класата да се имплементираат:

Потребните конструктори, деструктор, set и get методи (5 поени)
Оператор += за додавање нов оброк доколку не постои во низата (10 поени)
Оператор > кој споредува два ресторани според бројот на оброци. (5 поени)
Оператор за печатење << во формат [име] оброци: сите оброци поединечно и попуст за лојални корисници ( формат во тест примерите)  (5 поени)
Метода decrease() којашто прима два аргументи, тип оброк и  процент на намалување и ги намалува цените на сите оброци од соодветниот тип за соодвениот процент (10 поени)
Да се дефинира глобален метод biggestMenu() - кој прима низа од објекти од класатa Restaurant и број на ресторани, а го враќа оној ресторан кој има најголем број на оброци што ги нуди. Доколку повеќе ресторани имаат ист максимален број на оброци, се враќа прво најдениот (5 поени).



For example:

Input	Result
1
TESTING BRUNCH OPERATOR <<
Salad 200 0
Salmon 400 1
Cheesecake 300 2
TEST PASSED
4
TESTING RESTAURANT OPERATOR += and <<
Little Italy brunches:
Salad 200 0
Salmon 400 1
Cheesecake 300 2
15.5
TEST PASSED
*/
#include <iostream>
#include <cstring>

using namespace std;

enum Type {
    APPETIZER,
    MAINCOURSE,
    DESSERT
};

class Brunch {
private:
    char name[30];
    int id;
    float cost;
    Type type;

public:
    Brunch() {}

    Brunch(const char *name, int id, float cost, Type type) {
        strcpy(this->name, name);
        this->id = id;
        this->cost = cost;
        this->type = type;
    }

    ~Brunch() {}

    friend ostream &operator<<(ostream &o, Brunch &b) {
        return o << b.name << " " << b.cost << " " << b.type << endl;
    }

    bool operator==(const Brunch &b) {
        return (id == b.id);
    }

    Brunch &operator-=(float percent) {
        cost -= cost * (percent / 100);
        return *this;
    }

    Type getType() {
        return type;
    }
};

class Restaurant {
private:
    char name[40];
    Brunch *brunches;
    int numBrunches;
    static float LOYAL_DISCOUNT;

    void copy(const Restaurant &r) {
        strcpy(name, r.name);
        numBrunches = r.numBrunches;
        brunches = new Brunch[numBrunches];
        for (int i = 0; i < numBrunches; i++) {
            brunches[i] = r.brunches[i];
        }
    }

public:
    Restaurant(const char *name = "") {
        strcpy(this->name, name);
        this->numBrunches = 0;
        this->brunches = new Brunch[numBrunches];
    }

    Restaurant(const Restaurant &r) {
        copy(r);
    }

    Restaurant &operator=(const Restaurant &r) {
        if (this != &r) {
            delete[] brunches;
            copy(r);
        }
        return *this;
    }

    ~Restaurant() { delete[] brunches; }

    bool containsBrunch(const Brunch &b) {
        for (int i = 0; i < numBrunches; i++) {
            if (brunches[i] == b)
                return true;
        }
        return false;
    }

    Restaurant &operator+=(const Brunch &b) {
        if (!containsBrunch(b)) {
            Brunch *tmp = new Brunch[numBrunches + 1];
            for (int i = 0; i < numBrunches; i++) {
                tmp[i] = brunches[i];
            }
            delete[] brunches;
            brunches = tmp;
            brunches[numBrunches++] = b;
        }
        return *this;
    }


    void decrease(Type type, float percent) {
        for (int i = 0; i < numBrunches; i++) {
            if (brunches[i].getType() == type) {
                brunches[i] -= percent;
            }
        }
    }

    friend ostream &operator<<(ostream &o, Restaurant &r) {
        o << r.name << " brunches:" << endl;
        for (int i = 0; i < r.numBrunches; i++) {
            o << r.brunches[i];
        }
        o << r.LOYAL_DISCOUNT << endl;
        return o;
    }

    bool operator>(Restaurant &r) {
        return numBrunches > r.numBrunches;
    }

    static void setLOYAL_DISCOUNT(float discount) {
        LOYAL_DISCOUNT = discount;
    }
};

float Restaurant::LOYAL_DISCOUNT = 10.0;

Restaurant biggestMenu(Restaurant *r, int n) {
    Restaurant b = r[0];
    for (int i = 1; i < n; i++) {
        if (r[i] > b) {
            b = r[i];
        }
    }
    return b;
}


int main() {
    int test_case;
    cin >> test_case;
    switch (test_case) {
        case 0: {
            cout << "TESTING BRUNCH CONSTRUCTOR" << endl;

            Brunch appetizer("Salad", 1, 200, Type::APPETIZER);
            Brunch mainCourse("Salmon", 2, 400, Type::MAINCOURSE);
            Brunch dessert("Cheesecake", 3, 300, Type::DESSERT);

            cout << "TEST PASSED" << endl;
            break;
        }
        case 1: {
            cout << "TESTING BRUNCH OPERATOR <<" << endl;

            Brunch appetizer("Salad", 1, 200, Type::APPETIZER);
            Brunch mainCourse("Salmon", 2, 400, Type::MAINCOURSE);
            Brunch dessert("Cheesecake", 3, 300, Type::DESSERT);

            cout << appetizer;
            cout << mainCourse;
            cout << dessert;

            cout << "TEST PASSED" << endl;
            break;
        }
        case 2: {
            cout << "TESTING BRUNCH OPERATOR -=" << endl;

            Brunch appetizer("Salad", 1, 200, Type::APPETIZER);
            Brunch mainCourse("Salmon", 2, 400, Type::MAINCOURSE);
            Brunch dessert("Cheesecake", 3, 300, Type::DESSERT);

            cout << appetizer;
            cout << mainCourse;
            cout << dessert;

            appetizer -= 10;
            mainCourse -= 20.2;
            mainCourse -= 25;

            cout << appetizer;
            cout << mainCourse;
            cout << dessert;

            cout << "TEST PASSED" << endl;
            break;
        }
        case 3: {
            cout << "TESTING RESTAURANT CONSTRUCTOR and <<" << endl;

            Restaurant restaurant("Little Italy");
            cout << restaurant;

            cout << "TEST PASSED" << endl;
            break;
        }
        case 4: {
            cout << "TESTING RESTAURANT OPERATOR += and <<" << endl;

            Brunch appetizer("Salad", 1, 200, Type::APPETIZER);
            Brunch mainCourse("Salmon", 2, 400, Type::MAINCOURSE);
            Brunch dessert("Cheesecake", 3, 300, Type::DESSERT);

            Restaurant restaurant("Little Italy");
            restaurant += appetizer;
            restaurant += mainCourse;
            restaurant += dessert;

            Restaurant::setLOYAL_DISCOUNT(15.5);
            cout << restaurant;

            cout << "TEST PASSED" << endl;
            break;
        }
        case 5: {
            cout << "TESTING RESTAURANT OPERATOR += and <<" << endl;

            Brunch appetizer("Salad", 1, 200, Type::APPETIZER);
            Brunch mainCourse("Salmon", 2, 400, Type::MAINCOURSE);
            Brunch dessert("Cheesecake", 3, 300, Type::DESSERT);

            Restaurant restaurant("Little Italy");
            restaurant += appetizer;
            restaurant += mainCourse;
            restaurant += dessert;
            restaurant += dessert;

            Restaurant::setLOYAL_DISCOUNT(20);
            cout << restaurant;

            cout << "TEST PASSED" << endl;
            break;

        }
        case 6: {
            cout << "TESTING RESTAURANT COPY-CONSTRUCTOR and OPERATOR =" << endl;

            Brunch appetizer("Salad", 1, 200, Type::APPETIZER);
            Brunch mainCourse("Salmon", 2, 400, Type::MAINCOURSE);
            Brunch dessert("Cheesecake", 3, 300, Type::DESSERT);
            Brunch appetizer1("Caprese", 4, 150, Type::APPETIZER);
            Brunch dessert1("Mousse", 5, 350, Type::DESSERT);

            Restaurant restaurant("Little Italy");
            restaurant += appetizer;
            restaurant += mainCourse;
            restaurant += dessert;

            Restaurant restaurant2(restaurant);
            Restaurant restaurant4;
            {
                Restaurant restaurant3("Galaxy");
                restaurant3 += appetizer1;
                restaurant3 += dessert1;
                restaurant4 = restaurant3;
            }

            cout << restaurant2;
            cout << restaurant4;

            cout << "TEST PASSED" << endl;
            break;
        }
        case 7: {
            cout << "TESTING RESTAURANT OPERATOR > " << endl;

            Brunch appetizer("Salad", 1, 200, Type::APPETIZER);
            Brunch appetizer1("Caprese", 1, 150, Type::APPETIZER);
            Brunch mainCourse("Salmon", 2, 400, Type::MAINCOURSE);
            Brunch mainCourse1("Seafood", 2, 500, Type::MAINCOURSE);
            Brunch dessert("Cheesecake", 3, 300, Type::DESSERT);
            Brunch dessert1("Mousse", 4, 300, Type::DESSERT);


            Restaurant restaurant1("Little Italy");
            restaurant1 += appetizer;
            restaurant1 += mainCourse;
            restaurant1 += dessert;


            Restaurant restaurant2("Ember");
            restaurant2 += appetizer1;
            restaurant2 += mainCourse1;
            restaurant2 += dessert;
            restaurant2 += dessert1;


            if (restaurant2 > restaurant1) {
                cout << "TEST PASSED" << endl;
            }

            break;
        }
        case 8: {
            cout << "TESTING METHOD decrease" << endl;

            char rName[40];
            cin.ignore();
            cin.getline(rName, 40);
            Restaurant restaurant(rName);

            int n;
            cin >> n;

            char name[30];
            int id;
            float cost;
            int type;

            for (int i=0; i<n; i++) {
                cin.ignore();
                cin.getline(name,30);
                cin >> id;
                cin >> cost;
                cin >> type;

                Brunch brunch(name, id, cost, (Type)type);
                restaurant+=brunch;
                restaurant+=brunch;
            }

            float perc;
            cin >> perc;
            cin >> type;

            cout << restaurant;
            restaurant.decrease((Type)type, perc);
            cout << restaurant;

            cout << "TEST PASSED" << endl;
            break;
        }
        case 9: {
            cout << "TESTING METHOD biggestMenuRestaurant" << endl;

            int n;
            cin >> n;
            Restaurant restaurants[n];

            char rName[40];

            for (int i=0; i<n; i++) {
                cin.ignore();
                cin.getline(rName, 40);
                Restaurant restaurant(rName);

                int m;
                cin >> m;

                char name[30];
                int id;
                float cost;
                int type;

                for (int j=0; j<m; j++) {
                    cin.ignore();
                    cin.getline(name,30);
                    cin >> id;
                    cin >> cost;
                    cin >> type;

                    Brunch brunch(name, id, cost, (Type)type);
                    restaurant+=brunch;
                }

                restaurants[i]=restaurant;

            }

            Restaurant biggestMenuRestaurant = biggestMenu(restaurants, 2);
            cout << biggestMenuRestaurant;
            
            cout << "TEST PASSED" << endl;

            break;
        }
    }

    return 0;
}