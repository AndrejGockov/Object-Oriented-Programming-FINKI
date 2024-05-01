/*
(40 поени)

Да се креира класа Patnik во која се чуваат податоци за патниците на еден воз и тоа: име (низа од максимум 100 знаци), класа на вагон во која се вози (цел број 1 или 2) и велосипед (булова променлива).

За оваа класа да се преоптоварат:

Оператор << - за печатење на информациите за патникот во формат:
Име на патник

Бројот на класата (1 или 2)

Дали има велосипед?

Потоа да се креира клaса Voz во која се чува: крајна дестинација (низа од максимум 100 знаци), динамички алоцирана низа од објекти од класата Patnik, како и број на елементи во низата (цел број), број на дозволени велосипеди (цел број).

За класата да се обезбедат:

Оператор += – за додавање нов патник во воз. Патник со велосипед ќе може да се качи во воз само ако возот го дозволува тоа.
Оператор << - за печатење на крајната дестинација до која вози и листата на патници
Функција со потпис: patniciNemaMesto(). Со оваа функција се пресметува вкупниот број на патници (од 1-ва класа и 2-ра класа) за кои нема место да влезат во возот со велосипед. Притоа треба да се внимава дека во пресметувањето на вкупниот број патници со велосипеди кои ќе влезат во возот прво треба да се земат предвид патниците од 1-ва класа, а потоа се дозволува да влегуваат патниците од 2-ра класа се додека не се достигне максималниот број на дозволени велосипеди во возот. На крај се печати бројот на патници со велосипеди кои остануваат (не влегуваат во возот) од 1-ва класа, а потоа од 2-ра класа.
For example:

Input:
Amsterdam
0
5
Ana 
1 
1
Kate
2
0
Ace
2
0
Borce
2
1
Mimi
2
0
Amsterdam
Kate
2
0

Ace
2
0

Mimi
2
0

Result:
Brojot na patnici od 1-va klasa koi ostanale bez mesto e: 0
Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: 0
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Patnik{
    private:
        char ime[100];
        int vagon;
        bool bycicle;
    public:
        Patnik(){}
        
        Patnik(char ime[100], int vagon, bool bycicle){
            strcpy(this->ime, ime);
            this->vagon = vagon;
            this->bycicle = bycicle;
        }
        
        Patnik(const Patnik &other){
            strcpy(this->ime, other.ime);
            this->vagon = other.vagon;
            this->bycicle = other.bycicle;
        }
        
        Patnik &operator=(const Patnik &other){
            strcpy(this->ime, other.ime);
            this->vagon = other.vagon;
            this->bycicle = other.bycicle;
            return *this;
        }
    
        friend ostream &operator<<(ostream &res, Patnik &p){
            res << p.ime <<endl;
            res << p.vagon << endl;
            res << p.bycicle << endl;
            return res;
        }
        
        bool getBycicle(){
            return bycicle;
        }
        
        int getClass(){
            return vagon;
        }
};

class Voz{
    private:
        char destination[100];
        int maxV;
        Patnik *patnici;
        int totalPatnici;
    public:
        Voz(char destination[], int maxV){
            strcpy(this->destination, destination);
            this->maxV = maxV;
            totalPatnici = 0;
        }
        
        Voz &operator+=(Patnik &p){
            Patnik *tmp = new Patnik[totalPatnici + 1];
            for(int i = 0; i < totalPatnici; i++){
                tmp[i] = patnici[i];
            } 
            
            if(p.getBycicle() && maxV <= 0){
                delete []tmp;
                return *this;
            }
            
            tmp[totalPatnici] = p;
            if(totalPatnici)
                delete []patnici;
            
            patnici = tmp;
            totalPatnici++;
            return *this;
        }
        
        friend ostream &operator<<(ostream &res, Voz &voz){
            if(voz.totalPatnici > 0){
                // res << voz.destination << endl;
                for(int i = 0; i < voz.totalPatnici; i++){
                    res << voz.patnici[i] << endl;
                }
            }else{
                res << voz.destination;
            }
            return res;
        }
        
        void patniciNemaMesto(){
            int classOne = 0, classTwo = 0, velosipedi = 0;
            for(int i = 0; i < totalPatnici; i++){
                if(patnici[i].getClass() == 1  && patnici[i].getBycicle()){
                    velosipedi++;
                    if(velosipedi > maxV)
                        classOne++;
                }
            }
            
            for(int i = 0; i < totalPatnici; i++){
                if(patnici[i].getClass() == 2  && patnici[i].getBycicle()){
                    velosipedi++;       
                    if(velosipedi > maxV)
                        classTwo++;
                }
            }
            
            cout << "Brojot na patnici od 1-va klasa koi ostanale bez mesto e: " << classOne << endl;
            cout << "Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: " << classTwo << endl;
        }
};

int main()
{
	Patnik p;
	char ime[100], destinacija[100];
	int n;
	bool velosiped;
	int klasa;
	int maxv;
	cin >> destinacija >> maxv;
	cin >> n;
	Voz v(destinacija, maxv);
	cout<<v<<endl;
	for (int i = 0; i < n; i++){
		cin >> ime >> klasa >> velosiped;
		Patnik p(ime, klasa, velosiped);
// 		cout<<p<<endl;
		v += p;
	}
	cout << v;
	v.patniciNemaMesto();

	return 0;
}