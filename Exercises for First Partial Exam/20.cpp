/*
Во програмскиот јазик C++ да се креира структура Pacient и истата треба да содржи: (5 поени)

Име и презиме на пациентот ( низа од макс. 100 знаци)
Дали е здраствено осигуран (1-да, 0-не)
Број на прегледи во текот на последниот месец (цел број)
Да се креира структура MaticenDoktor, која во себе содржи: (5 поени)

Име на докторот (низа од 100 знаци)
Број на пациенти (цел број)
Листа од пациенти (низа од максимум 200 елементи од структурата Pacient)
Цена на преглед (децимален број)
Да се креираат метода najuspesen_doktor, која прима низа од променливи од типот MaticenDoktor и нивниот број; и го печати името, заработената сума и бројот на прегледи на оној доктор кој заработил најголема сума од пациенти кои ги прегледувал приватно (не се здраствено осигурани) (10 поени). Доколку два или повеќе доктори имаат иста сума, тогаш се печати оној доктор кој има направено најголем број на прегледи вкупно во текот на последниот месец. (20 поени)

Функционалност (5 поени).

For example:

Input:
3
Д-р.Јованка_Јовановска
3
300.00
Јованова_Ивана 1 2
Боцевска_Ивана 0 3
Илиевска_Ангела 1 0
Д-р.Петко_Петковски
1
50.00
Ивановска_Цветанка 0 18
Д-р.Трајче_Трајчев
3
300.00
Крстевски_Филип 1 0
Цветановски_Иван 1 10
Ивановска_Цветанка 0 3

Result:
Д-р.Петко_Петковски 900.00 18
*/

#include<iostream>
#include<cstring>
#include<cmath>
#include<stdio.h>
using namespace std;

struct Pacient{
    char ime[100];
    bool zdrastveno;
    int pregledi;
};

struct doktor{
    char ime[100];
    int br_pac;
    float cena;
    Pacient niza[100];
};

void najuspesen_doktor(doktor *md, int n){
    char ime[100];
    float mostEarned = 0;
    int pregledi = -1;
    for(int i = 0; i < n; i++){
        float currentEarned = 0;
        int currPregledi = 0;
        
        for(int j = 0; j < md[i].br_pac; j++){
            if(!md[i].niza[j].zdrastveno){
                currentEarned += (md[i].cena * md[i].niza[j].pregledi);
            }
            
            currPregledi += md[i].niza[j].pregledi;
        }
        
        if(currentEarned >= mostEarned && currPregledi >= pregledi){
            mostEarned = currentEarned;
            strcpy(ime, md[i].ime);
            pregledi = currPregledi;
        }
    }
    
    cout<<ime << " " << mostEarned << ".00 " << pregledi;
}

int main()
{
	int i, j, n, broj;
	doktor md[200];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		//ime na doktor
		scanf("%s", &md[i].ime);
		//broj na pacienti
		scanf("%d", &md[i].br_pac);
		//cena na pregled
		scanf("%f", &md[i].cena);

		for (j = 0; j < md[i].br_pac; j++){
			scanf("%s", &md[i].niza[j].ime);
			scanf("%d", &md[i].niza[j].zdrastveno);
			scanf("%d", &md[i].niza[j].pregledi);
		}
	}
	najuspesen_doktor(md, n);

	return 0;
}
