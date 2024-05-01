/*
Да се креира структура Воз во која се чуваат податоци за релацијата по која се движи возот (низа од најмногу 50 знаци), предвиден бројот на километри што треба да се поминат (реален број), како и бројот на патници во возот (цел број).

Потоа да се креирa структура ZeleznickaStanica во која се чуваат податоци за градот во кој се наоѓа (низа од 20 знаци), низа од возови што поаѓаат од станицата (најмногу 30) и бројот на возови (цел број).

Треба да се направи функција со потпис

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad)
во која се печати релацијата и бројот на километри на возот што поминува најкратка релација (најмалку километри), а поаѓа од железничката станица од градот што се проследува како влезен аргумент. Ако има повеќе возови со ист најмал број на километри, да се испечати релацијата на последниот таков.

Забелешка: Задачата да се реши во програмскиот јазик C++

For example:

Input:
1
Dresden
2

Result:
Dresden-Berlin 192 200
Dresden-Lajpcig 115 90
Dresden
Najkratka relacija: Dresden-Lajpcig (115 km)
*/

#include<iostream>
#include <cstring>
using namespace std;

struct Voz{
    char relacija[50];
    float kilometri;
    int brPatnici;
};

struct ZeleznickaStanica{
    char grad[20];
    Voz vozovi[30];
    int brVozovi;
};

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad){
    char ime[50];
    float najkratka;
    bool entered = false;
    
    for(int i = 0; i < n; i++){
        if(strcmp(zs[i].grad, grad) != 0){
            continue;
        }
        
        for(int j = 0; j < zs[i].brVozovi; j++){
            if(!entered){
                strcpy(ime, zs[i].vozovi[j].relacija);
                najkratka = zs[i].vozovi[j].kilometri;
                entered = true;
            }
            
            if(zs[i].vozovi[j].kilometri > najkratka)
                continue;
            
            strcpy(ime, zs[i].vozovi[j].relacija);
            najkratka = zs[i].vozovi[j].kilometri;
        }
    }
    
    cout << "Najkratka relacija: " << ime << " (" << najkratka << " km)"<<endl;
}

int main(){
    int n;
	cin>>n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];
    for (int i=0;i<n;i++){
        //se citaat infomracii za n zelezlnichkite stanici i se zacuvuvaat vo poleto zStanica
        cin >> zStanica[i].grad >> zStanica[i].brVozovi;
        
        for(int j = 0; j < zStanica[i].brVozovi; j++){
            cin >> zStanica[i].vozovi[j].relacija >> zStanica[i].vozovi[j].kilometri >>  zStanica[i].vozovi[j].brPatnici;
        }
    }
    
    char grad[25];
    cin>>grad;

	najkratkaRelacija(zStanica,n,grad);
	return 0;
}