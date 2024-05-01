/*
Фирмата FINKI Cloud има потреба од решение за управување со image датотеките од различните оперативни системи кои ги користат при сетирање на нови сервери. За таа цел потребно е да се дефинираат следниве класи:

OperativenSistem
Во класата OperativenSistem треба да се чуваат следниве податоци:

име на оперативниот систем (динамички алоцирана низа од знаци)
верзија (float)
тип (енумерација со можни вредности LINUX, UNIX, WINDOWS)
големина (во GB) (float)
Дополнително, во рамките на класата потребно е да се дефинира:

конструктори со и без параметри
copy constructor
destructor
преоптоварување на операторот =
метод за печатење на информациите - void pecati() (видете го излезот од тест примерите за структурата)
метод за проверка на еднаквост помеѓу два оперативни системи (два оперативни системи се еднакви ако имаат исто име, верзија, тип и големина) - bool ednakviSe(const OperativenSistem &os)
метод за споредба на верзии помеѓу два оперативни система - int sporediVerzija(const OperativenSistem &os), кој ќе враќа 0 доколку верзиите се исти, -1 доколку верзијата на оперативниот систем од аргументот е поголема и 1 во преостанатиот случај.
метод за проверка дали два оперативни системи се од иста фамилија. Два оперативни системи се од иста фамилија доколку имаат исто име и се од ист тип. bool istaFamilija(const OperativenSistem &sporedba)
Repozitorium
Во класата Repozitorium треба да се чуваат следниве податоци:

име на репозиториумот (низа од 20 знака)
динамички алоцирана низа од OperativenSistem
број на оперативни системи кои моментално се наоѓаат во репозиториумот (int)
Дополнително, во рамките на класата потребно е да се дефинира:

конструктор Repozitorium(const char *ime)
деструктор
метод void pecatiOperativniSistemi() кој ќе ги печати сите оперативни системи кои се дел од репозиториумот
метод void izbrishi(const OperativenSistem &operativenSistem) кој ќе го избрише оперативниот систем проследен како аргумент, доколку тој се наоѓа во репозиториумот. Да се користи методот ednakviSe за споредба на два оперативни система.
метод за додавање на оперативен систем (void dodadi(const OperativenSistem &nov)) кој ќе го има следново однесување:
Доколку веќе постои оперативен систем од иста фамилија (да се користи методот за проверка на фамилија) кој е постар од проследениот оперативен систем, тогаш постоечкиот оперативен систем се заменува со новиот.
Во секој друг случај, проследениот оперативен систем се додава како дополнителен во репозиториумот.
For example:

Input:
FINKICloud
2
Ubuntu
17.04
1
2.25
Ubuntu
16.04
1
1.25
Ubuntu
14.04
1
1.25

Result:
Repozitorium: FINKICloud
Ime: Ubuntu Verzija: 17.04 Tip: 1 Golemina:2.25GB
Ime: Ubuntu Verzija: 16.04 Tip: 1 Golemina:1.25GB
=====Brishenje na operativen sistem=====
Repozitorium: FINKICloud
Ime: Ubuntu Verzija: 17.04 Tip: 1 Golemina:2.25GB
Ime: Ubuntu Verzija: 16.04 Tip: 1 Golemina:1.25GB
*/

#include <iostream>
#include <cstring>
using namespace std;

enum Tip { LINUX, UNIX, WINDOWS };

class OperativenSistem {
    char* ime;
    float verzija;
    Tip tip;
    float golemina;

    void copy_os(const OperativenSistem& other) {
        this->ime = new char[strlen(other.ime) + 1];
        strcpy(this->ime, other.ime);
        this->verzija = other.verzija;
        this->tip = other.tip;
        this->golemina = other.golemina;
    }

public:
    OperativenSistem() {
        this->ime = new char[4];
        strcpy(this->ime, "os");
        this->verzija = 0.1;
        this->tip = LINUX;
        this->golemina = 1.0;
    }

    OperativenSistem(const char* ime, const float verzija, const Tip tip, const float golemina) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->verzija = verzija;
        this->tip = tip;
        this->golemina = golemina;
    }

    OperativenSistem(const OperativenSistem& other) {
        copy_os(other);
    }

    OperativenSistem& operator=(const OperativenSistem& other) {
        if(this == &other) {
            return *this;
        }
        delete [] this->ime;
        copy_os(other);
        return *this;
    }

    void pecati() {
        cout << "Ime: " << ime << " Verzija: " << verzija << " Tip: " << tip << " Golemina:" << golemina << "GB" << "\n";
    }

    bool ednakviSe(const OperativenSistem& os) {
        return !strcmp(ime, os.ime) && verzija == os.verzija && tip == os.tip && golemina == os.golemina;
    }

    int sporediVerzija(const OperativenSistem& os) {
        return verzija == os.verzija ? 0 : verzija < os.verzija ? -1 : 1;
    }

    bool istaFamilija(const OperativenSistem& sporedba) {
        return !strcmp(ime, sporedba.ime) && tip == sporedba.tip;
    }

    ~OperativenSistem() {
        delete [] ime;
    }
};

class Repozitorium {
    char ime[20];
    OperativenSistem* os;
    int os_n;

    void copy_repo(const Repozitorium& other) {
        strcpy(this->ime, other.ime);
        this->os = new OperativenSistem[other.os_n];
        for(int i = 0; i < other.os_n; i++) {
            this->os[i] = other.os[i];
        }
        this->os_n = other.os_n;
    }

public:
    Repozitorium() {
        strcpy(this->ime, "repo");
        os = nullptr;
        os_n = 0;
    }

    Repozitorium(const char* ime) {
        strcpy(this->ime, ime);
        this->os = nullptr;
        os_n = 0;
    }

    Repozitorium(const Repozitorium& other) {
        copy_repo(other);
    }

    Repozitorium& operator=(const Repozitorium& other) {
        if(this == &other) {
            return *this;
        }
        delete [] this->os;
        copy_repo(other);
        return *this;
    }

    void pecatiOperativniSistemi() {
        cout << "Repozitorium: " << ime << "\n";
        for(int i = 0; i < os_n; i++) {
            os[i].pecati();
        }
    }

    void izbrishi(const OperativenSistem& operativenSistem) {
        int idx = -1;
        for(int i = 0; i < os_n; i++) {
            if(os[i].ednakviSe(operativenSistem)) {
                idx = i;
                break;
            }
        }

        if(idx == -1) {
            return;
        }

        for(int i = idx; i < os_n - 1; i++) {
            os[i] = os[i + 1];
        }
        os_n--;
    }

    void dodadi(const OperativenSistem& nov) {
        for(int i = 0; i < os_n; i++) {
            if(os[i].istaFamilija(nov) && os[i].sporediVerzija(nov) == -1) {
                os[i] = nov;
                return;
            }
        }

        OperativenSistem* tmp = new OperativenSistem[os_n + 1];
        for(int i = 0; i < os_n; i++) {
            tmp[i] = os[i];
        }
        tmp[os_n++] = nov;

        delete [] os;
        this->os = new OperativenSistem[os_n];
        for(int i = 0; i < os_n; i++) {
            this->os[i] = tmp[i];
        }
        delete [] tmp;
    }

    ~Repozitorium() {
        delete [] os;
    }
};

int main() {
    char repoName[20];
    cin>>repoName;
    Repozitorium repozitorium=Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin>>brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime;
        cin>>verzija;
        cin>>tip;
        cin>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin>>ime;
    cin>>verzija;
    cin>>tip;
    cin>>golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}