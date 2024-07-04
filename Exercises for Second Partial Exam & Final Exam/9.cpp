/*
Да се имплементира класа Trud во која се чуваат информации за: (5 поени)

вид на труд (еден знак и тоа C за конференциски труд, J за труд во списание)
година на издавање (цел број).
Да се имплементира класа Student во која се чува: (5 поени)

името на студентот (низа од најмногу 30 карактери)
индекс (цел број)
година на упис (цел број)
листа на оцени од положени предмети (низа од цели броеви)
број на положени предмети (цел број)
За оваа класа да се имплементираат следните методи:

функција rang() што пресметува просек од положените испити на студентот (5 поени)
оператор << за печатење на студентот во формат: (5 поени)

Индекс Име Година на упис ранг

Да се имплементира класа PhDStudent во која покрај основните информации за студентот дополнително се чува: (5 поени)

листа од објавени трудови (динамички резервирана низа од објекти од класата Trud)
бројот на трудови (цел број)
Во оваа класа да се препокрие соодветно функцијата rang() така што на просекот од положените испити ќе се додаде и збирот од поените од објавените трудови на PhD студентот. Во зависност од видот на трудот, секој универзитет има посебен начин на бодување на трудовите. Начинот на бодување е ист за сите PhD студенти. Иницијално да се смета дека конференциски труд се бодува со 1 поен, а труд во списание со 3 поени. Универзитетот има можност да ги менува вредностите на бодовите. (5 поени + 5 поени)

За оваа класа да се обезбеди:

оператор += за додавање нов објект од класата Trud во листата (5 поени). Ако се направи обид да се внесе труд што е издаден порано од годината на упис на студентот да се фрли исклучок (објект од класата Exception). Справувањето со исклучокот треба да се реализира во главната функција main каде што е потребно, но и во конструктор ако е потребно. Ако бил генериран исклучок треба да се отпечати соодветна порака за грешка "Ne moze da se vnese dadeniot trud", а новиот труд нема да се внесе во листата на трудови од студентот. (10 поени)
Напомена: Сите променливи на класите се чуваат како приватни.

Да се обезбедат сите потребни функции за правилно функционирање на програмата. (5 поени)

For example:

Input	Result
2
3
1
PhDStudent_1
111222
2012
5
10 10 10 9 10
1
j
2015
1
PhDStudent_2
123456
2003
5
10 9 10 8 10
3
c
2003
j
2003
j
2005
0
Student
12234
2010
3
10 10 10
123456
C
2004
===== Testiranje na operatorot += ======

Lista na site studenti:
111222 PhDStudent_1 2012 12.8
123456 PhDStudent_2 2003 16.4
12234 Student 2010 10

Lista na site studenti:
111222 PhDStudent_1 2012 12.8
123456 PhDStudent_2 2003 17.4
12234 Student 2010 10
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Exception
{
public:
    static void message()
    {
        cout << "Ne moze da se vnese dadeniot trud" << endl;
    }
};

class Trud
{
    char type;
    int year;

public:
    // Constructors
    Trud() {}

    Trud(char type, int year)
    {
        this->type = type;
        this->year = year;
    }

    ~Trud() {}

    // Functions
    void Copy(Trud &other)
    {
        this->type = other.type;
        this->year = other.year;
    }

    char getType()
    {
        return type;
    }

    int getYear()
    {
        return year;
    }

    // Operators
    Trud &operator=(Trud &other)
    {
        if (this == &other)
            return *this;
        Copy(other);
        return *this;
    }

    friend istream &operator>>(istream &in, Trud &t)
    {
        in >> t.type >> t.year;
        return in;
    }
};

class Student
{
protected:
    char name[50];
    int index, godinaUpis;
    int *grades;
    int passedSubjects;

public:
    // Constructors
    Student() {}

    Student(char name[50], int index, int godinaUpis, int *grades, int passedSubjects)
    {
        strcpy(this->name, name);
        this->index = index;
        this->godinaUpis = godinaUpis;
        this->grades = new int[passedSubjects];
        this->passedSubjects = passedSubjects;

        for (int i = 0; i < passedSubjects; i++)
        {
            this->grades[i] = grades[i];
        }
    }

    ~Student()
    {
        delete[] grades;
    }

    // Functions
    void Copy(Student &other)
    {
        strcpy(this->name, other.name);
        this->index = other.index;
        this->godinaUpis = other.godinaUpis;
        this->grades = new int[other.passedSubjects];
        this->passedSubjects = other.passedSubjects;

        for (int i = 0; i < other.passedSubjects; i++)
        {
            this->grades[i] = other.grades[i];
        }
    }

    int getIndex()
    {
        return index;
    }

    virtual double rang()
    {
        double rang = 0;
        for (int i = 0; i < this->passedSubjects; i++)
        {
            rang += this->grades[i];
        }
        return (rang / this->passedSubjects);
    }

    // Operators
    Student &operator=(Student &other)
    {
        if (this == &other)
            return *this;
        Copy(other);
        return *this;
    }

    friend ostream &operator<<(ostream &res, Student &st)
    {
        res << st.index << " " << st.name << " " << st.godinaUpis << " " << st.rang() << endl;
        return res;
    }
};

class PhDStudent : public Student
{
    Trud *Trudovi;
    int trudoviNum;

    static int c, j;

public:
    // Constructors
    PhDStudent() : Student() {}

    PhDStudent(char name[50], int index, int godinaUpis, int *grades, int passedSubjects, Trud *Trudovi, int trudoviNum)
        : Student(name, index, godinaUpis, grades, passedSubjects)
    {
        this->trudoviNum = trudoviNum;
        this->Trudovi = new Trud[trudoviNum];
        for (int i = 0; i < trudoviNum; i++)
        {
            try
            {
                Trudovi[i].getYear() < godinaUpis ? throw Exception() : this->Trudovi[i] = Trudovi[i];
            }
            catch (Exception &err)
            {
                err.message();
            }
        }
    }

    ~PhDStudent()
    {
        delete[] Trudovi;
    }

    // Functions

    static void setC(int newC)
    {
        c = newC;
    }

    static void setJ(int newJ)
    {
        j = newJ;
    }

    double rang()
    {
        double rang = Student::rang();

        for (int i = 0; i < trudoviNum; i++)
        {
            if (tolower(Trudovi[i].getType()) == 'c')
                rang += c;
            else if (tolower(Trudovi[i].getType()) == 'j')
                rang += j;
        }

        return rang;
    }

    // Operators
    PhDStudent &operator+=(Trud &newTrud)
    {
        if (newTrud.getYear() < this->godinaUpis)
            throw Exception();

        Trud *tmp = new Trud[trudoviNum + 1];

        for (int i = 0; i < trudoviNum; i++)
        {
            tmp[i] = this->Trudovi[i];
        }

        tmp[trudoviNum++] = newTrud;
        delete[] Trudovi;
        Trudovi = new Trud[trudoviNum];

        for (int i = 0; i < trudoviNum; i++)
        {
            this->Trudovi[i] = tmp[i];
        }
        delete[] tmp;
        return *this;
    }
};

int PhDStudent::c = 1;
int PhDStudent::j = 3;

int main()
{
    int testCase;
    cin >> testCase;

    int god, indeks, n, god_tr, m, n_tr;
    int izbor; // 0 za Student, 1 za PhDStudent
    char ime[30];
    int oceni[50];
    char tip;
    Trud trud[50];

    if (testCase == 1)
    {
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> ime;
        cin >> indeks;
        cin >> god;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> oceni[j];
        Student s(ime, indeks, god, oceni, n);
        cout << s;

        cin >> ime;
        cin >> indeks;
        cin >> god;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> oceni[j];
        cin >> n_tr;
        for (int j = 0; j < n_tr; j++)
        {
            cin >> tip;
            cin >> god_tr;
            Trud t(tip, god_tr);
            trud[j] = t;
        }
        PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
        cout << phd;
    }
    if (testCase == 2)
    {
        cout << "===== Testiranje na operatorot += ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i < m; i++)
        {
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0)
            {
                niza[i] = new Student(ime, indeks, god, oceni, n);
            }
            else
            {
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++)
                {
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje nov trud za PhD student spored indeks
        Trud t;
        cin >> indeks;
        cin >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot +=
        bool found = false;

        for (int i = 0; i < m; i++)
        {
            if (niza[i]->getIndex() == indeks && dynamic_cast<PhDStudent *>(niza[i]))
            {
                found = true;
                *dynamic_cast<PhDStudent *>(niza[i]) += t;
            }
        }

        if (!found)
        {
            cout << "Ne postoi PhD student so indeks " << indeks << endl;
        }

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 3)
    {
        cout << "===== Testiranje na operatorot += ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i < m; i++)
        {
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0)
            {
                niza[i] = new Student(ime, indeks, god, oceni, n);
            }
            else
            {
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++)
                {
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje nov trud za PhD student spored indeks
        Trud t;
        cin >> indeks;
        cin >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot += od Testcase 2
        bool found = false;

        for (int i = 0; i < m; i++)
        {
            if (niza[i]->getIndex() == indeks && dynamic_cast<PhDStudent *>(niza[i]))
            {
                found = true;
                *dynamic_cast<PhDStudent *>(niza[i]) += t;
            }
        }

        if (!found)
        {
            cout << "Ne postoi PhD student so indeks " << indeks << endl;
        }

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 4)
    {
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin >> ime;
        cin >> indeks;
        cin >> god;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> oceni[j];
        cin >> n_tr;
        for (int j = 0; j < n_tr; j++)
        {
            cin >> tip;
            cin >> god_tr;
            Trud t(tip, god_tr);
            trud[j] = t;
        }
        PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
        cout << phd;
    }
    if (testCase == 5)
    {
        cout << "===== Testiranje na isklucoci ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i < m; i++)
        {
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0)
            {
                niza[i] = new Student(ime, indeks, god, oceni, n);
            }
            else
            {
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++)
                {
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje nov trud za PhD student spored indeks
        Trud t;
        cin >> indeks;
        cin >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot += i spravete se so isklucokot
        try
        {
            for (int i = 0; i < m; i++)
            {
                if (niza[i]->getIndex() == indeks && dynamic_cast<PhDStudent *>(niza[i]))
                {
                    *dynamic_cast<PhDStudent *>(niza[i]) += t;
                }
            }
        }
        catch (Exception &err)
        {
            err.message();
        }

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 6)
    {
        cout << "===== Testiranje na static clenovi ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i < m; i++)
        {
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0)
            {
                niza[i] = new Student(ime, indeks, god, oceni, n);
            }
            else
            {
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++)
                {
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        int conf, journal;
        cin >> conf;
        cin >> journal;

        // postavete gi soodvetnite vrednosti za statickite promenlivi
        PhDStudent::setC(conf);
        PhDStudent::setJ(journal);

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }

    return 0;
}