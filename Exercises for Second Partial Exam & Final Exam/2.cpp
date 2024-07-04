/*
Да се дефинира класа Vozac во која се чуваат информации за:

име (низа од максимум 100 знаци)
возраст (цел број)
број на трки (цел број)
дали е ветеран (да/не).
Да се преоптоварат:

операторот << за печатење кој ќе ги печати името, возраст, бројот на трки и дали е ветеран (се печати VETERAN)
операторот == за споредување на два возачи според заработувачката по трка.
Од оваа класа да се изведат две нови класи Avtomobilist и Motociklist.

За автомобилистот дополнително се чува:

цена на автомобилот (децимален број).
За мотоциклистот дополнително се чува:

моќност на мотор (цел број).
Заработувачката по трка на возачите се пресметува како:

за автомобилостот заработувачката по трка е $\frac{CENA_{AVTOMOBIL}}{5}$
за мотоциклистот заработувачката по трка е $MOKJNOST_NA_MOTOR * 20$
Секој автомобилист плаќа данок на заработка. Да се напишат соодветни методи за пресметување данок:

за автомобилисти: ако бројот на трки е поголем од 10 стапката на данок е 15% од заработката, инаку 10% од заработката.
за мотоциклисти: ако е ветеран стапката на данок е 25% од заработката, инаку 20% од заработката.
Да се напше надворешна функција soIstaZarabotuvachka која како аргументи прима низа од покажувачи од класата Vocac, нивниот број, како и покажувач кон ојбект од возач и враќа како резултат бројот на возачи кои имаат иста заработувачка по трка со проследениот возач.

For example:

Input	Result
5
1
Hamilton 30 95 0 55000
Vetel 26 88 1 800
Barrichello 38 198 0 810
Rossi 32 130 1 800
Lorenzo 24 45 0 900
VozacX 38 198 1 800
=== DANOK ===
Hamilton
30
95
1650
Vetel
26
88
VETERAN
4000
Barrichello
38
198
3240
Rossi
32
130
VETERAN
4000
Lorenzo
24
45
3600
=== VOZAC X ===
VozacX
38
198
VETERAN
=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===
2
*/

// vashiot kod ovde
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Vozac
{
protected:
    char name[100];
    int age, trackNum;
    bool veteran;

public:
    Vozac() {}

    Vozac(char name[100], int age, int trackNum, bool veteran)
    {
        strcpy(this->name, name);
        this->age = age;
        this->trackNum = trackNum;
        this->veteran = veteran;
    }

    ~Vozac() {}

    virtual float zarabotuvacka() = 0;

    virtual float danok() = 0;

    bool operator==(Vozac &other)
    {
        if (this->trackNum == other.trackNum)
            return true;

        return false;
    }

    friend ostream &operator<<(ostream &res, Vozac &vozac)
    {
        res << vozac.name << endl
            << vozac.age << endl
            << vozac.trackNum << endl;
        if (vozac.veteran)
            res << "VETERAN" << endl;
        return res;
    }
};

class Avtomobilist : public Vozac
{
    float price;

public:
    Avtomobilist() : Vozac() {}

    Avtomobilist(char name[100], int age, int trackNum, bool veteran, float price)
        : Vozac(name, age, trackNum, veteran)
    {
        this->price = price;
    }

    ~Avtomobilist() {}

    float zarabotuvacka()
    {
        return (this->price / 5.0);
    }

    float danok()
    {
        if (trackNum > 10)
            return (zarabotuvacka() * 0.15);
        return (zarabotuvacka() * 0.1);
    }

    Avtomobilist &operator=(Avtomobilist &other)
    {
        if (this == &other)
        {
            return *this;
        }
        Vozac::operator=(other);
        this->price = price;
        return *this;
    }
};

class Motociklist : public Vozac
{
    int power;

public:
    Motociklist() : Vozac() {}

    Motociklist(char name[100], int age, int trackNum, bool veteran, int power)
        : Vozac(name, age, trackNum, veteran)
    {
        this->power = power;
    }

    ~Motociklist() {}

    float zarabotuvacka()
    {
        return this->power * 20;
    }

    float danok()
    {
        if (veteran)
            return zarabotuvacka() * 0.25;

        return zarabotuvacka() * 0.2;
    }

    Motociklist &operator=(Motociklist &other)
    {
        if (this == &other)
        {
            return *this;
        }
        Vozac::operator=(other);
        this->power = power;
        return *this;
    }
};

int soIstaZarabotuvachka(Vozac **vozaci, int n, Vozac *vozacComp)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (vozaci[i]->zarabotuvacka() == vozacComp->zarabotuvacka())
            res++;
    }

    return res;
}

int main()
{
    int n, x;
    cin >> n >> x;
    Vozac **v = new Vozac *[n];
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
    for (int i = 0; i < n; ++i)
    {
        cin >> ime >> vozrast >> trki >> vet;
        if (i < x)
        {
            float cena_avto;
            cin >> cena_avto;
            v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
        }
        else
        {
            int mokjnost;
            cin >> mokjnost;
            v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
        }
    }
    cout << "=== DANOK ===" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << *v[i];
        cout << v[i]->danok() << endl;
    }
    cin >> ime >> vozrast >> trki >> vet;
    int mokjnost;
    cin >> mokjnost;
    Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
    cout << "=== VOZAC X ===" << endl;
    cout << *vx;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << soIstaZarabotuvachka(v, n, vx);
    for (int i = 0; i < n; ++i)
    {
        delete v[i];
    }
    delete[] v;
    delete vx;
    return 0;
}