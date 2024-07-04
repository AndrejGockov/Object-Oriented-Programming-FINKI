/*
Да се имплементира апстрактна класа FudblaskaEkipa во која се чува: (5 поени)

име на тренерот на екипата (максимум 100 знаци)
бројот на постигнати голови на последните 10 натпревари, последниот натпревар е на позиција 9, предпоследниот на позиција 8, итн (поле од 10 цели броеви)
Од класата FudblaskaEkipa да се изведат класите Klub и Reprezentacija. За секој клуб дополнително се чува податок за името и бројот на титули што ги има освоено, а за репрезентацијата се чуваат податоци за името на државата и вкупен број на меѓународни настапи. За овие класи да се имплементираат следните методи:

соодветен конструктор (5 поени)
оператор << за печатење на стандарден излез во формат [IME_NA_KLUB/DRZHAVA]\n[TRENER]\n[USPEH]\n (5 поени)
преоптоварен оператор+= за додавање на голови од последниот натпревар (внимавајте секогаш се чуваат головите само од последните 10 натпревари) (10 поени)
метод uspeh, за пресметување на успехот на тимот на следниот начин:
За Klub се пресметува како збир од збирот на головите од последните 10 натпревари помножен со 3 и бројот на титули помножен со 1000 (на пр. голови = {2, 0, 1, 3, 2, 0, 1, 4, 2, 3} и број на титули = 3, достигнување = 18 * 3 + 3 * 1000 = 3054)
За Reprezentacija како збир од збирот на головите од последните 10 натпревари помножен со 3 и бројот на меѓународни настапи помножен со 50 (на пр. голови = {2, 0, 1, 3, 2, 0, 1, 4, 2, 3} и број на меѓународни настапи=150, достигнување = 18 * 3 + 150 * 50 = 7554) (10 поени)
преоптоварен оператор > за споредба на две фудбласки екипи од каков било вид (клубови или репрезентации) според успехот (5 поени)
Да се имплементира функција najdobarTrener што на влез прима низа од покажувачи кон FudblaskaEkipa и големина на низата и го печати тимот со најголем успех (10 поени).

For example:

Input	Result
5
0
Zinedin Zidane
2 2 2 3 4 1 5 3 0 3
Real Madrid CF
2
0
Luis Enrique
3 4 5 1 3 0 6 5 4 3
FC Barcelona
6
1
Visente Del Boske
1 1 4 0 2 2 3 1 3 5
Spain
2
1
Antonio Conte
0 0 1 4 2 3 4 1 2 2
Italy
3
0
Claudio Ranieri
3 2 2 3 1 2 2 0 3 4
Leicester City FC
1
3
2
3
2
1
===== SITE EKIPI =====
Real Madrid CF
Zinedin Zidane
2075
FC Barcelona
Luis Enrique
6102
Spain
Visente Del Boske
166
Italy
Antonio Conte
207
Leicester City FC
Claudio Ranieri
1066
===== DODADI GOLOVI =====
dodavam golovi: 3
dodavam golovi: 2
dodavam golovi: 3
dodavam golovi: 2
dodavam golovi: 1
===== SITE EKIPI =====
Real Madrid CF
Zinedin Zidane
2078
FC Barcelona
Luis Enrique
6099
Spain
Visente Del Boske
172
Italy
Antonio Conte
213
Leicester City FC
Claudio Ranieri
1060
===== NAJDOBAR TRENER =====
FC Barcelona
Luis Enrique
6099
*/

#include <iostream>
#include <cstring>
using namespace std;

// vashiot kod ovde
class FudbalskaEkipa
{
protected:
    char coach[100];
    int goals[10];

private:
    void CopyFudEkipa(FudbalskaEkipa &other)
    {
        strcpy(this->coach, other.coach);
        for (int i = 0; i < 10; i++)
            this->goals[i] = other.goals[i];
    }

public:
    FudbalskaEkipa() {}

    FudbalskaEkipa(char *coach, int *goals)
    {
        strcpy(this->coach, coach);
        for (int i = 0; i < 10; i++)
            this->goals[i] = goals[i];
    }

    FudbalskaEkipa(FudbalskaEkipa &other)
    {
        CopyFudEkipa(other);
    }

    FudbalskaEkipa &operator=(FudbalskaEkipa &other)
    {
        if (this == &other)
            return *this;
        CopyFudEkipa(other);
        return *this;
    }

    ~FudbalskaEkipa() {}

    // Functions
    char *getCoach()
    {
        return coach;
    }

    virtual int uspeh() = 0;

    // Operators
    bool operator>(FudbalskaEkipa &other)
    {
        return (this->uspeh() > other.uspeh());
    }

    FudbalskaEkipa &operator+=(int newGoals)
    {
        for (int i = 0; i < 9; i++)
        {
            this->goals[i] = this->goals[i + 1];
        }
        this->goals[9] = newGoals;
        return *this;
    }
};

class Klub : public FudbalskaEkipa
{
    char teamName[100];
    int titleNum;

    void Copy_Klub(Klub &other)
    {
        strcpy(this->teamName, other.teamName);
        this->titleNum = other.titleNum;
    }

public:
    Klub() : FudbalskaEkipa() {}

    Klub(char *coach, int *goals, char teamName[100], int titleNum)
        : FudbalskaEkipa(coach, goals)
    {
        strcpy(this->teamName, teamName);
        this->titleNum = titleNum;
    }

    Klub(Klub &other) : FudbalskaEkipa(other)
    {
        Copy_Klub(other);
    }

    Klub &operator=(Klub &other)
    {
        if (this == &other)
            return *this;

        Copy_Klub(other);
        FudbalskaEkipa::operator=(other);
        return *this;
    }

    ~Klub() {}

    // Functions

    char *getTeamName()
    {
        return teamName;
    }

    int uspeh()
    {
        int total = 0;
        for (int i = 0; i < 10; i++)
            total += goals[i];

        total = (total * 3) + (titleNum * 1000);

        return total;
    }

    // Operators
    bool operator>(Klub &other)
    {
        return (this->uspeh() > other.uspeh());
    }
};

class Reprezentacija : public FudbalskaEkipa
{
    char country[100];
    int civilEventNum;

    void CopyRep(Reprezentacija &other)
    {
        strcpy(this->country, other.country);
        this->civilEventNum = civilEventNum;
    }

public:
    Reprezentacija() : FudbalskaEkipa() {}

    Reprezentacija(char *coach, int *goals, char country[100], int civilEventNum)
        : FudbalskaEkipa(coach, goals)
    {
        strcpy(this->country, country);
        this->civilEventNum = civilEventNum;
    }

    Reprezentacija(Reprezentacija &other) : FudbalskaEkipa(other)
    {
        CopyRep(other);
    }

    Reprezentacija &operator=(Reprezentacija &other)
    {
        if (this == &other)
            return *this;

        CopyRep(other);
        FudbalskaEkipa::operator=(other);
        return *this;
    }

    ~Reprezentacija() {}

    // Functions

    char *getCountry()
    {
        return country;
    }

    int uspeh()
    {
        int total = 0;
        for (int i = 0; i < 10; i++)
            total += goals[i];
        total = (total * 3) + (civilEventNum * 50);
        return total;
    }

    // Operators
    bool operator>(Reprezentacija &other)
    {
        return (this->uspeh() > other.uspeh());
    }
};

ostream &operator<<(ostream &res, FudbalskaEkipa &ekipa)
{
    //  [IME_NA_KLUB/DRZHAVA]\n[TRENER]\n[USPEH]\n
    if (dynamic_cast<Klub *>(&ekipa))
    {
        res << dynamic_cast<Klub *>(&ekipa)->getTeamName() << endl;
    }
    if (dynamic_cast<Reprezentacija *>(&ekipa))
    {
        res << dynamic_cast<Reprezentacija *>(&ekipa)->getCountry() << endl;
    }
    res << ekipa.getCoach() << endl;
    res << ekipa.uspeh() << endl;
    return res;
}

void najdobarTrener(FudbalskaEkipa **ekipi, int n)
{
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (index == -1 || ekipi[index]->uspeh() < ekipi[i]->uspeh())
        {
            index = i;
        }
    }

    if (index == -1)
        return;

    cout << *ekipi[index];
}

int main()
{
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa *[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i)
    {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j)
        {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0)
        {
            ekipi[i] = new Klub(coach, goals, x, tg);
        }
        else if (type == 1)
        {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i)
    {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i)
    {
        delete ekipi[i];
    }
    delete[] ekipi;
    return 0;
}