/*
Да се дефинира класата Pesna во која се чуваат информации за (5 поени):

име на песна (динамички алоцирано поле од знаци)
времетраење на песната во минути
тип на песна кој може да биде: поп, рап или рок (енумерација tip)
Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата. (10 поени)

Дополнително за оваа класа да се дефинира методот:

pecati() - функција во која ќе се печатат одделени со цртичка(-): името на песната во наводници и времетраењето на песната со постфикс min. (5 поени)
Да се креира класата CD во која се чуваат информации за (5 поени):

низа од песни снимени на CD-то (Поле од најмногу 10 објекти од класата Pesna )
број на песни снимени на CD-то
максимално времетраење на песните на CD-то (во минути)
Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата. (5 поени)

Дополнително за оваа класа да се дефинираат методите:

dodadiPesna (Pesna p) - со кој се додава песната p на CDто, но само ако има доволно преостанато место (земајќи го предвид максималното времетраење на песните на CDто и времетраењата на песните на CD-то) и ако има помалку од 10 песни на CD-то. (10 поени)
pecatiPesniPoTip(tip t) – со кој се печатат информациите за сите песни од тип t (поп, рап или рок). (10 поени)
Комплетна функционалност (5 поени).

For example:

Input:
3
4
Happy 5 0
Layla 8 2
Stan 4 1
Revolution 7 2

Result:
===== Testiranje na metodot dodadiPesna() od klasata CD ======
"Happy"-5min
"Layla"-8min
"Stan"-4min
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class CD;

enum tip{
    pop, rap, rock
};

class Pesna{
    private:
        char *imePesna;
        int dolzina;
        tip tipPesna;
    public:
        Pesna(){}
        
        Pesna(char *ime, int length, tip type){
            this->imePesna = new char[strlen(ime) + 1];
            strcpy(this->imePesna, ime);
            this->dolzina = length;
            this->tipPesna = type;
        }
        
        ~Pesna(){
            // delete []imePesna;
        }
        
        Pesna &operator=(const Pesna &p){
            if(this != &p){
                // delete []imePesna;
                this->imePesna = new char[strlen(p.imePesna) + 1];
                strcpy(this->imePesna, p.imePesna);
                this->dolzina = p.dolzina;
                this->tipPesna = p.tipPesna;
            }
            return *this;
        }
        
        tip getTip(){
            return tipPesna;
        }
        
        void pecati(){
            cout<<"\""<<imePesna<<"\"-"<<dolzina<<"min"<<endl;
        }
        
        friend class CD;
};

class CD{
    private:
        int maxLength;
        Pesna pesni[10];
        int brojPesni = 0;
    public:
        CD(){}
        CD(int n){
            this->maxLength = n;
            brojPesni = 0;
        }
        ~CD(){}
        
        void dodadiPesna(const Pesna &p){
            int totalVreme = 0;
            for (int i = 0; i < brojPesni; i++) {
                totalVreme += pesni[i].dolzina;
            }
            
            if(brojPesni < 10 && (totalVreme + p.dolzina) < maxLength){
                pesni[brojPesni] = p;
                // pesni[brojPesni].pecati();
                brojPesni++;
            }
        }
        
        void const pecatiPesniPoTip(tip type){
            for(int i = 0; i < brojPesni; i++){
                if(type == pesni[i].getTip()){
                    this->pesni[i].pecati();
                }
            }
        }
        
        Pesna getPesna(int i){
            return pesni[i];
        }
        
        int getBroj(){
            return brojPesni;
        }
};

int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;
	
	int n, minuti, kojtip;
	char ime[50];
	
	if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
		p.pecati();
    } 
    else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<n; i++)
				(omileno.getPesna(i)).pecati();
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<omileno.getBroj(); i++)
				(omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);
        	
    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);
        	
    }
    
return 0;
}