/*
Да се дефинира класа Ucesnik за учесник во маратон за кој ќе се чуваат информации за:

име (динамички алоцирана низа од знаци)
пол (bool)
возраст (цел број) (5 поени).
За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор. (10 поени)

Дополнително за оваа класа да се преоптоварат:

оператор за споредување > (споредува двајца учесници според возраста) (5 поени)
операторот за проследување на излезен тек << кој ќе ги печати името, полот (машки/женски) и возраста, секој во посебен ред. (5 поени)
Да се дефинира класа Maraton за кој се чуваат:

локација (низа од максимум 100 знаци)
низа од Ucesnik објекти (динмички алоцирана низа од објекти од класата Ucesnik)
број на учесници (цел број) (5 поени).
За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор. (10 поени) Исто така да се имплементираат следните методи:

оператор += за додавање нов Ucesnik на маратонот Maraton. (10 поени)
prosecnoVozrast() вреќа просечена возраст на учесниците на маратонот (5 поени)
pecatiPomladi(Ucesnik &u) ги печати сите учесници помлади од учесникот проследен како аргумент на методот. (5 поени)
For example:

Input:
5
Skopje
Elena 0 23
Mitko 1 41
Iskra 0 31
Jovan 1 28
Zoran 1 40

Result:
Elena
zhenski
23
Iskra
zhenski
31
Jovan
mashki
28
32.6
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Ucesnik{
    private:
        char ime[100];
        bool maski;
        int vozrast;
    public:
        Ucesnik(){}
        
        Ucesnik(char Ime[100], bool Maski, int Voz){
            strcpy(ime, Ime);
            maski = Maski;
            vozrast = Voz;
        }
        
        Ucesnik(const Ucesnik &u){
            strcpy(this->ime, u.ime);
            this->maski = u.maski;
            this->vozrast = u.vozrast;
        }
        
        ~Ucesnik(){}
        
        friend ostream &operator<<(ostream &res, const Ucesnik &u){
            res << u.ime<<endl;
            if(u.maski)
                res << "mashki"<<endl;
            else
                res << "zhenski" <<endl;
            res << u.vozrast<<endl;
            return res;
        }
        
        int getVozrast() const{
            return vozrast;
        }
};

class Maraton{
    private:
        char lokacija[100];
        int ucesniciCounter;
        Ucesnik **ucesnici;
    public:
        Maraton(char Lok[100]){
            strcpy(lokacija, Lok);
            ucesniciCounter = 0;
            ucesnici = new Ucesnik*[100];
        }
        ~Maraton(){
            delete []ucesnici;
        }
        
        void operator+=(const Ucesnik &ucesnik){
            ucesnici[ucesniciCounter] = new Ucesnik(ucesnik);
            ucesniciCounter++;
        }
        
        void pecatiPomladi(const Ucesnik &u){
            int age = u.getVozrast();
            for(int i = 0; i < ucesniciCounter; i++){
                if(ucesnici[i]->getVozrast() < age){
                    cout<< *ucesnici[i];
                }
            }
        }
        
        float prosecnoVozrast() const{
            float avg = 0;
            for(int i = 0; i < ucesniciCounter; i++){
                avg += (float)ucesnici[i]->getVozrast();
            }
            avg /= ucesniciCounter;
            return avg;
        }
};

// vashiot kod ovde

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
    	u[i] = new Ucesnik(ime,  maski, vozrast);
        m += *u[i];
    }
	m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
	return 0;
}