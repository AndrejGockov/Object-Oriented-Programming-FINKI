/*
Да се дефинира класа MountainTrail за која се чуваат следните податоци:

name - име на патеката, низа од карактери
length - должина на патеката во километри, цел број
slope - наклон на патеката изразен во проценти, double
За класата да се дефинира default конструктор, конструктор со аргументи и copy конструктор.

За класата да се дефинира метод double difficulty() кој ја пресметува тежината на патеката по следната формула: должина * наклон / 100. Да се дефинира и метод void display() кој ги печати податоците за патеката во следниот формат: [име] [должина] [наклон].

Потоа да се дефинира класа Mountain за која се чува:
name - име на планината, низа од карактери
trails - низа од 5 патеки кои се наоѓаат на планината
peak_elevation - надморска височина на врвот, цел број
num_mountains - бр. на планини за кои водиме сметка во програмата (вредноста на ова поле треба да биде иста во сите објекти, треба да има и get метод)
За класата да се дефинира  default конструктор, конструктор со аргументи, како и деструктор. Потребно е секој од овие методи да го ажурира вкупниот број на планини.

Во класата да се дефинира метод display() кој ќе печати податоци за планината во следниот формат: [име]: [н.в. на врвот]m

Надвор од класата да се дефинира метод void sortMountainsByPeakElevation(Mountain mountains[], int n) кој прима низа од планини и ги печати во опаѓачки редослед според надморската висина на нивниот врв. Овој метод мора да пристапува директно до приватното поле за надморска висина.

Да не се менува main функцијата.

------------------------------------------------
Define a class MountainTrail for which the following data are stored:

name - name of the trail,  string array
length - length of the trail in kilometers, integer
slope - slope of the trail expressed in percentages, double
For the class, define a default constructor, a constructor with arguments, and a copy constructor.

Additionally, define a method double difficulty() that calculates the difficulty of the trail using the following formula: length * slope / 100 and a void display() method which prints the data for the trail in the following format: [name] [length] [slope].

Then, define a class Mountain for which the following data is stored:
name - name of the mountain,  string array
trails - array of 5 trails located on the mountain
peak_elevation - elevation of the peak, integer
num_mountains - number of mountains tracked in the program (the value of this field should be the same in all objects, it should also have a get method)
For the class, define a default constructor, a constructor with arguments, a destructor (each of these methods needs to update the total number of mountains), and a display() method that prints data for the mountain in the following format: [name]: [peak elevation]m

Outside the class, define a method void sortMountainsByPeakElevation(Mountain mountains[], int n) that takes an array of mountains and prints them in descending order according to the elevation of their peak. This method must access the private field for peak elevation directly.

Do not change the main function.
Answer:(penalty regime: 0 %)
*/

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class MountainTrail{
    char name[100];
    int length;
    double slope;
    
    void Copy(const MountainTrail &other){
        strcpy(this->name, other.name);
        this->length = other.length;
        this->slope = other.slope;
    }
    public:
        MountainTrail(){}
        
        MountainTrail(char name[100], int length, double slope){
            strcpy(this->name, name);
            this->length = length;
            this->slope = slope;
        }
        
        MountainTrail(const MountainTrail &other){
            Copy(other);
        }
        
        ~MountainTrail(){}
        
        virtual double difficulty(){
            return slope * length / 100;
        }
        
        void display(){
            cout<<name<<" "<<length<<" "<<slope<<endl;
        }
};

class Mountain{
        char name[100];
        MountainTrail trails[5];
        int peakElevation;
        static int num_mountains;
        
        void Copy(const Mountain &other){
            strcpy(this->name, other.name);
            for(int i = 0; i < 5; i++)
                this->trails[i] = other.trails[i];
            this->peakElevation = other.peakElevation;
        }
    public:
        Mountain(){}
        
        Mountain(char name[100], MountainTrail trails[5], int peakElevation){
            strcpy(this->name, name);
            for(int i = 0; i < 5; i++){
                this->trails[i] = trails[i];
            }
            num_mountains = 5;
            this->peakElevation = peakElevation;
        }
        
        Mountain(const Mountain &other){
            Copy(other);
        }
        
        ~Mountain(){}
        
        int getPeakElevation(){
            return peakElevation;
        }
        
        static int getNumMountains(){
            return num_mountains;
        }
        
        void display(){
            cout<<name<<": "<<peakElevation<<"m"<<endl;
        }
};

void sortMountainsByPeakElevation(Mountain *mountains, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(mountains[j].getPeakElevation() < mountains[j + 1].getPeakElevation()){
                swap(mountains[j], mountains[j + 1]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        mountains[i].display();
    }
}

/*
 *  DO NOT CHANGE ANY OF THE FOLLOWING CODE
 */
int Mountain::num_mountains = 0;

int main() {

    int test_case_n;

    char trail_name[100];
    int trail_length;
    double trail_slope;

    char mountain_name[100];
    int mountain_peak_elevation;

    cin>>test_case_n;
    if (test_case_n == 0) {
        cout << "Testing MountainTrail c-tors, display function:"<<endl;
        cin >> trail_name >> trail_length >> trail_slope;
        MountainTrail mt = MountainTrail(trail_name, trail_length, trail_slope);
        MountainTrail mt2 = MountainTrail(mt);
        mt.display();
        mt2.display();
    } 
    else if (test_case_n == 1) {
        cout << "Testing MountainTrail difficulty function:"<<endl;
        for (int i = 0; i < 5; ++i) {
            cin >> trail_name >> trail_length >> trail_slope;
            MountainTrail mt = MountainTrail(trail_name, trail_length, trail_slope);
            cout<<mt.difficulty()<<endl;
        }
    } 
    else if (test_case_n == 2) {
        cout << "Testing Mountain c-tor, display function:"<<endl;
        MountainTrail trails[5];

        cin>>mountain_name>>mountain_peak_elevation;

        for (int i = 0; i < 5; ++i) {
            cin >> trail_name >> trail_length >> trail_slope;
            trails[i] = MountainTrail(trail_name, trail_length, trail_slope);
        }

        Mountain mountain = Mountain(mountain_name, trails, mountain_peak_elevation);
        mountain.display();
    } 
    else if (test_case_n == 3) {
        cout << "Testing static field in Mountain:" <<endl;
        MountainTrail trails[5];

        cin>>mountain_name>>mountain_peak_elevation;

        for (int i = 0; i < 5; ++i) {
            cin >> trail_name >> trail_length >> trail_slope;
            trails[i] = MountainTrail(trail_name, trail_length, trail_slope);
        }

        for (int i = 0; i < 10; ++i) {
            Mountain mountain = Mountain(mountain_name, trails, mountain_peak_elevation);
        }

        Mountain m1 = Mountain(mountain_name, trails, mountain_peak_elevation);
        Mountain m2 = Mountain(mountain_name, trails, mountain_peak_elevation);
        Mountain m3 = Mountain(mountain_name, trails, mountain_peak_elevation);
        Mountain m4 = Mountain(mountain_name, trails, mountain_peak_elevation);
        Mountain m5 = Mountain(mountain_name, trails, mountain_peak_elevation);

        if(Mountain::getNumMountains() == 5) {
            cout<<"OK";
        } else {
            cout<<"Missing mountain count increment/decrement";
        }
    } 
    else if (test_case_n == 4) {
        int M;
        cin>>M;
        cout<<"Testing order function:"<<endl;

        Mountain mountains[M];

        for (int i = 0; i < M; ++i) {
            cin>>mountain_name>>mountain_peak_elevation;
            MountainTrail trails[5];

            for (int j = 0; j < 5; ++j) {
                cin >> trail_name >> trail_length >> trail_slope;
                trails[j] = MountainTrail(trail_name, trail_length, trail_slope);
            }

            mountains[i] = Mountain(mountain_name, trails, mountain_peak_elevation);
        }

        sortMountainsByPeakElevation(mountains, M);
    }
}