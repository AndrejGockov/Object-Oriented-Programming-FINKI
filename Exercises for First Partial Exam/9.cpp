/*
Во програмскиот јазик C++ да се креира структура Laptop за опишување на спецификациите на даден преносен компјутер. Структурата треба да содржи: (5 поени)

Фирма која го произведува ( низа од 100 знаци)
Големина на монитор во инчи (реален број)
Дали е со touch или не (булова променлива)
Цена (цел број)
Да се креира структура ITStore, што содржи: (5 поени)

Име на продавницата (низа од 100 знаци)
Локација (низа од 100 знаци)
Низа од достапни лаптопи (низа од максимум 100 елементи од структурата Laptop)
Број на елементи во низата (цел број)
Да се креира функција print за печатење на информациите за сите лаптопи во една продавница во формат: (10 поени)

[Ime na prodavnicata] [Lokacija]
[Marka1] [dim_monitor1] [Cena1]
[Marka2] [dim_monitor2] [Cena2]
[Marka3] [dim_monitor3] [Cena3]
...
Да се креира функција najeftina_ponuda, што прима низа од променливи од типот ITStore и го печати името и локацијата на онаа продавница која нуди најевтин преносен компјутер и неговата цена. Најефтин преносен компјутер е оној што има најниска цена и плус опција за touch. Ако има повеќе такви продавници, се печати прво најдената.* (15 поени)*

Да се дополни функцијата main (10 поени).

Од тастатура се внесува бројот на продавници, па потоа за секоја продавница се внесуваат името и локацијата, а потоа бројот на компјутери, па за секој од компјутерите фирма која го произведува, големина на монитор, дали има touch и цена. Потоа се печатат сите внесени продавници и најевтината понуда.

For example:

Input:
2
AMC
Skopje
3
dell
13.1
1
32500
asus
15.0
0
20200
hp
13.1
1
42000
Anhoch
Skopje
1
asus
13.3
1
32000

Result:
AMC Skopje
dell 13.1 32500
asus 15 20200
hp 13.1 42000
Anhoch Skopje
asus 13.3 32000
Najeftina ponuda ima prodavnicata: 
Anhoch Skopje
Najniskata cena iznesuva: 32000
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct Laptop{
    char firma[100];
    float golemina;
    bool hasTouch;
    int price;
};

struct ITStore{
    char prodavnica[100];
    char lokacija[100];
    Laptop laptopi[100];
    int elements;
};

void print(ITStore *store, int n){
    for(int i = 0; i < n; i++){
        cout<< store[i].prodavnica << " " << store[i].lokacija << endl;
        for(int j = 0; j < store[i].elements; j++){
            cout << store[i].laptopi[j].firma << " " << store[i].laptopi[j].golemina << " " << store[i].laptopi[j].price << endl;
        }
    }
}

void najeftina_ponuda(ITStore *s, int n){
    int najeftina;
    char prod[100], lok[100];
    bool entered = false;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < s[i].elements; j++){
            if(!s[i].laptopi[j].hasTouch)
                continue;
                
            if(!entered){
                najeftina = s[i].laptopi[j].price;
                strcpy(prod, s[i].prodavnica);
                strcpy(lok, s[i].lokacija);
                entered = true;
            }
            
            if(najeftina > s[i].laptopi[j].price){
                strcpy(prod, s[i].prodavnica);
                strcpy(lok, s[i].lokacija);
                najeftina = s[i].laptopi[j].price;
            }
        }
    }
    
    cout<<"Najeftina ponuda ima prodavnicata: "<< endl;
    cout<< prod << " " << lok << endl;
    cout<<"Najniskata cena iznesuva: "<<najeftina<<endl;
    
}

int main() {
    ITStore s[100];
    int n;
    scanf("%d",&n); //broj na IT prodavnici
    
    //vnesuvanje na prodavnicite edna po edna, zaedno so raspolozlivite laptopvi vo niv
    for(int i = 0; i < n; i++){
        cin >> s[i].prodavnica >> s[i].lokacija >> s[i].elements;
        for(int j = 0; j < s[i].elements; j++){
            cin >> s[i].laptopi[j].firma >> s[i].laptopi[j].golemina >> s[i].laptopi[j].hasTouch >> s[i].laptopi[j].price;
        }
    }
    
    //pecatenje na site prodavnici
    print(s, n);
    
    //povik na glavnata metoda
    najeftina_ponuda(s, n);

    return 0;
}