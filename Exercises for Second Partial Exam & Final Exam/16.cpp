/*
Туристичка агенција нуди различни понуди за транспорт на патници. За секоја понуда се чуваат податоци за дестинацијата (низа од знаци), основна цена (цел број) и податок за растојанието до дестинацијата изразено во km (цел број).

Од класата Transport да се изведат класите AvtomobilTransport и KombeTransport за моделирање на понудите за транспорт кои нудат транспорт со автомобил или комбе, соодветно. За секоја понуда за транспорт со автомобил се чува податок за тоа дали во понудата има платен шофер (булова променлива), а за транспорт со комбе бројот на луѓе кои може да се превезат во комбето (цел број). (5 поени)

За секој објект од двете изведени класи треба да бидат на располагање следниве методи:

конструктор со аргументи што одговараат на податочните членови и set и get методи за податочните членови (5 поени)
метод cenaTransport, за пресметување на цената на понудата на следниот начин:
За транспорт со автомобил - основната цена се зголемува за 20% ако има платен шофер
За транспорт со комбе - основната цена ќе се намали зависно од бројот на патници во комбето. За секој патник во комбето цената се намалува за 200 (10 поени)
преоптоварен оператор < за споредба на две понуди за транспорт на патник според растојанието до дестинацијата. (5 поени)
Да се имплементира функција pecatiPoloshiPonudi што на влез прима низа од понуди за транспорт на патник, бројот на елементите од низата и една понуда T. Функцијата ја печати дестинацијата, растојанието до дестинацијата и цената за понудите од низата кои се поскапи од понудата T сортирани во растечки редослед по растојанието до дестинацијата (погледни го повикот на функцијата) (10 поени)

Комплетна функционалност на кодот (5 поени)

For example:

Input	Result
3
1 Belgrad 3200 900 1
1 Bitola 2500 400 0
2 Sofija 5000 1040 2
Bitola 400 2500
Belgrad 900 3840
Sofija 1040 4600
*/

// вашиот код треба да биде тука
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Transport
{
protected:
    char *destination;
    int basePrice, distance;

    void CopyTransport(const Transport &other)
    {
        this->destination = new char[strlen(other.destination) + 1];
        strcpy(this->destination, other.destination);
        this->basePrice = other.basePrice;
        this->distance = other.distance;
    }

public:
    Transport() {}

    Transport(char *destination, int basePrice, int distance)
    {
        this->destination = new char[strlen(destination) + 1];
        strcpy(this->destination, destination);
        this->basePrice = basePrice;
        this->distance = distance;
    }

    Transport(const Transport &other)
    {
        CopyTransport(other);
    }

    ~Transport()
    {
        delete[] destination;
    }

    char *getDestination()
    {
        return destination;
    }

    int getDistance()
    {
        return distance;
    }

    virtual float cenaTransport()
    {
        return basePrice;
    }

    bool operator<(const Transport &other)
    {
        return (distance > other.distance);
    }

    Transport &operator=(const Transport &other)
    {
        if (this == &other)
            return *this;

        delete[] destination;
        CopyTransport(other);
        return *this;
    }
};

class AvtomobilTransport : public Transport
{
    bool platenSofer;

    void CopyAvtomobil(AvtomobilTransport &other)
    {
        this->platenSofer = platenSofer;
    }

public:
    AvtomobilTransport() : Transport() {}

    AvtomobilTransport(char *destination, int basePrice, int distance, bool platenSofer)
        : Transport(destination, basePrice, distance)
    {
        this->platenSofer = platenSofer;
    }

    AvtomobilTransport(const AvtomobilTransport &other) : Transport(other)
    {
        this->platenSofer = other.platenSofer;
    }

    ~AvtomobilTransport() {}

    AvtomobilTransport &operator=(AvtomobilTransport &other)
    {
        if (this == &other)
            return *this;
        Transport::operator=(other);
        CopyAvtomobil(other);
        return *this;
    }

    float cenaTransport()
    {
        float total = basePrice;
        if (platenSofer)
            total += (total * 0.2);
        return total;
    }
};

class KombeTransport : public Transport
{
    int numClients;

    void CopyKombe(KombeTransport &other)
    {
        this->numClients = numClients;
    }

public:
    KombeTransport() : Transport() {}

    KombeTransport(char *destination, int basePrice, int distance, int numClients)
        : Transport(destination, basePrice, distance)
    {
        this->numClients = numClients;
    }

    KombeTransport(const KombeTransport &other) : Transport(other)
    {
        this->numClients = other.numClients;
    }

    ~KombeTransport() {}

    KombeTransport &operator=(KombeTransport &other)
    {
        if (this == &other)
            return *this;
        Transport::operator=(other);
        CopyKombe(other);
        return *this;
    }

    float cenaTransport()
    {
        return (basePrice - (numClients * 200));
    }
};

void pecatiPoloshiPonudi(Transport **ponudi, int n, AvtomobilTransport nov)
{
    Transport **sortedT = new Transport *[n];
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (ponudi[i]->cenaTransport() > nov.cenaTransport())
        {
            sortedT[k++] = ponudi[i];
        }
    }

    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 0; j < k - i - 1; j++)
        {
            if (sortedT[j]->getDistance() > sortedT[j + 1]->getDistance())
            {
                Transport *tmp = sortedT[j];
                sortedT[j] = sortedT[j + 1];
                sortedT[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < k; i++)
        cout << sortedT[i]->getDestination() << " " << sortedT[i]->getDistance() << " " << sortedT[i]->cenaTransport() << endl;
}

int main()
{

    char destinacija[20];
    int tip, cena, rastojanie, lugje;
    bool shofer;
    int n;
    cin >> n;
    Transport **ponudi;
    ponudi = new Transport *[n];

    for (int i = 0; i < n; i++)
    {

        cin >> tip >> destinacija >> cena >> rastojanie;
        if (tip == 1)
        {
            cin >> shofer;
            ponudi[i] = new AvtomobilTransport(destinacija, cena, rastojanie, shofer);
        }
        else
        {
            cin >> lugje;
            ponudi[i] = new KombeTransport(destinacija, cena, rastojanie, lugje);
        }
    }

    AvtomobilTransport nov("Ohrid", 2000, 600, false);
    pecatiPoloshiPonudi(ponudi, n, nov);

    for (int i = 0; i < n; i++)
        delete ponudi[i];
    delete[] ponudi;
    return 0;
}
