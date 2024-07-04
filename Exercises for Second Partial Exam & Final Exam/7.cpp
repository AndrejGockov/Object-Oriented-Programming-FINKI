/*
Дадена е дел од дефиницијата на класата Karticka. За секоја картичка се чуваат информации за трансакциска сметка (низа од 15 знаци) , пин код (цел број) и дали има повеќе пин кодови (булова променлива).

За секој картичка може да се пресмета тежината за пробивање на картичката. Тежината на пробивање е бројот на цифрите на пин кодот.

Специјалните картички покрај еден задолжителен имаат уште неколку пин кодови . За овие корисници да се моделира соодветна класа SpecijalnaKaricka во која покрај дополнителните пин кодови (динамичко алоцирана низа од цели броеви) се чува и бројот на пин кодовите (цел број). Со дополнителните пин кодови се менува и тежината на пробивање на картичката и таа се зголемува за бројот на дополнителни пин кодови.

Максималниот број на дополнителни пин кодови кој може да има било која картичка е P. P има фиксна вредност 4 за сите картички и оваа вредност не може да се промени.

Во класите Karticka и SpecijalnaKarticka треба да се имплементираат потребните конструктори, функции за поставување и преземање и деструктор. (5 поени)

За сите објекти од класите треба да се обезбедат следните функции:

преоптоварен оператор << во кој се печатат информации за картичката во формат: smetka: tezina (5 поени)
tezinaProbivanje() – ја пресметува тежината за пробивање на картичката (5 поени)
Во класата SpecijalnaKarticka дефинирај ја функцијата:

преоптоварен оператор += за додавање на нов пин код (5 поени)
Ако се направи обид да се внесат повеќе од дозволениот број на пин кодови во безбедносниот код да се фрли исклучок (објект од класата OutOfBoundException). Фатете го исклучокот во главната функција каде што е потребно. Откако ќе го фатите отпечатете соодветна порака за грешка (Brojot na pin kodovi ne moze da go nadmine dozvolenoto) и справете се со исклучокот така да додадениот пин код не се зема предвид (10 поени)

Дадена е дел од дефиницијата на класата Banka во која се чуваат информаци за името на банката (низа од 30 знаци) и за картичките издадени од банката (низа од 20 покажувачи кон класата Karticka) како и бројот на такви картички.

Велиме дека картичката издадена од банката може да се пробие ако тежината за пробивање е најмногуLIMIT. Вредноста LIMIT е членка на класата Banka, има почетна вредност 7 и истата може да се промени со функцијата setLimit(). За сите банки оваа вредност е иста. (5 поени)

Во класата Banka имплементирај ги функциите:

функција pecatiKarticki() во која се печатат сите картички кои можат да се пробијат, секој во посебен ред. Претходно во првиот ред се печати: Vo bankata XXXXX moze da se probijat kartickite: (5 поени).

функција dodadiDopolnitelenPin(char * smetka, int novPin) во која на картичката со дадена трансакциона сметка се додава нов дополнителен пин код. Ако тоа не е можно функцијата не прави ништо (15 поени).

Комплетна функционалност (5 поени)

For example:

Input	Result
2
ab1232432 345 0
bh4555432 876 1
4
ab1232432 2
ab1112432 100
ab1232432 56
ab1211111 88
Vo bankata Komercijalna moze da se probijat kartickite:
ab1232432: 3
bh4555432: 3
*/
#include <iostream>
#include <string.h>
using namespace std;

class Karticka
{
protected:
    char smetka[16];
    int pin;
    bool povekjePin;

public:
    Karticka(char *smetka, int pin)
    {
        strcpy(this->smetka, smetka);
        this->pin = pin;
        this->povekjePin = false;
    }
    virtual ~Karticka() {}
    Karticka(const Karticka &u)
    {
        strcpy(this->smetka, u.smetka);
        this->pin = u.pin;
        this->povekjePin = u.povekjePin;
    }
    bool getDopolnitelenPin() { return povekjePin; }
    char *getSmetka() { return smetka; }

    virtual int tezinaProbivanje()
    {
        int broj = 0;
        int pompin = pin;
        while (pompin != 0)
        {
            broj++;
            pompin /= 10;
        }
        return broj;
    }
    friend ostream &operator<<(ostream &o, Karticka &u)
    {
        o << u.smetka << ": " << u.tezinaProbivanje() << endl;
        return o;
    }
};
class IndexOutOfBoundException
{
public:
    void print()
    {
        cout << "Brojot na pin kodovi ne moze da go nadmine dozvolenoto" << endl;
    }
};
class SpecijalnaKarticka : public Karticka
{
private:
    int broj;
    int *poeni;

public:
    const static int M = 4;
    ~SpecijalnaKarticka()
    {
        delete[] poeni;
    }
    SpecijalnaKarticka(char *ime, int finalenIspit) : Karticka(ime, finalenIspit)
    {
        this->povekjePin = true;
        broj = 0;
        poeni = new int[M];
    }
    SpecijalnaKarticka(const SpecijalnaKarticka &u) : Karticka(u)
    {
        broj = u.broj;
        poeni = new int[M];
        for (int i = 0; i < broj; i++)
            poeni[i] = u.poeni[i];
    }

    int tezinaProbivanje()
    {

        return broj + Karticka::tezinaProbivanje();
    }
    friend void operator+=(SpecijalnaKarticka &u, int novi)
    {
        if (u.broj == u.M)
            throw IndexOutOfBoundException();
        u.poeni[u.broj++] = novi;
    }
};
class Banka
{
private:
    char naziv[30];
    Karticka *karticki[20];
    int broj;
    int static P;

public:
    Banka(char *naziv, Karticka **karticki, int broj)
    {
        strcpy(this->naziv, naziv);
        for (int i = 0; i < broj; i++)
        {
            // ako kartickata ima dopolnitelni pin kodovi
            // cout<<karticki[i]->getDopolnitelenPin()<<endl;
            if (karticki[i]->getDopolnitelenPin())
            {
                this->karticki[i] = new SpecijalnaKarticka(*dynamic_cast<SpecijalnaKarticka *>(karticki[i]));
            }
            else
                this->karticki[i] = new Karticka(*karticki[i]);
        }
        this->broj = broj;
    }
    ~Banka()
    {
        for (int i = 0; i < broj; i++)
            delete karticki[i];
    }

    // da se dopolni
    static void setLIMIT(int novoP)
    {
        P = novoP;
    }
    void pecatiKarticki()
    {
        cout << "Vo bankata " << naziv << " moze da se probijat kartickite:" << endl;
        for (int i = 0; i < broj; i++)
            if (karticki[i]->tezinaProbivanje() <= P)
                cout << (*karticki[i]);
    }
    void dodadiDopolnitelenPin(char *ime, int poeniA)
    {
        for (int i = 0; i < broj; i++)
            if (strcmp(karticki[i]->getSmetka(), ime) == 0)
            {
                SpecijalnaKarticka *nov = dynamic_cast<SpecijalnaKarticka *>(karticki[i]);
                if (nov != 0)
                {
                    // cout<<"a"<<endl;
                    (*nov) += poeniA;
                }
            }
    }
};
int Banka::P = 7;
int main()
{

    Karticka **niza;
    int n, m, pin;
    char smetka[16];
    bool daliDopolnitelniPin;
    cin >> n;
    niza = new Karticka *[n];
    for (int i = 0; i < n; i++)
    {
        cin >> smetka;
        cin >> pin;
        cin >> daliDopolnitelniPin;
        if (!daliDopolnitelniPin)
            niza[i] = new Karticka(smetka, pin);
        else
            niza[i] = new SpecijalnaKarticka(smetka, pin);
        // cout<<"main: "<<niza[i]->getDopolnitelenPin()<<endl;
    }

    Banka komercijalna("Komercijalna", niza, n);
    for (int i = 0; i < n; i++)
        delete niza[i];
    delete[] niza;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> smetka >> pin;
        try
        {
            komercijalna.dodadiDopolnitelenPin(smetka, pin);
        }
        catch (IndexOutOfBoundException i)
        {
            i.print();
        }
    }

    Banka::setLIMIT(5);

    komercijalna.pecatiKarticki();
}
