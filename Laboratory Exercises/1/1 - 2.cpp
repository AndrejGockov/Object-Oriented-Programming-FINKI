/*
Да се креира структура Engine во која што ќе се чуваат податоци за коњска сила / horsepower (int) и вртежен момент / torque (int).


Потоа, да се креира структура Car во која што ќе  се чуваат податоци името на производителот (char array) , која година е произведена колата (int) и кој мотор / engine (Engine) која што го користи/


На почетокот се внесува број N што озналува колку коли ќе се читаат од влез.


Да се направи функцијата:


void printCars(...)


која што ќе ги земе двете коли кои имаат најмала коњска сила, и од нив две, ќе ја испечати колата што има поголем вртежен момент.

___________________________________

Create an Engine structure that will store horsepower (int) and torque (int) data.

Then, create a structure Car in which the data of the manufacturer's name (char array), which year the car was manufactured (int) and which engine (Engine) that uses it/ will be stored.

At the beginning, a number N is entered that indicates how many cars will be read from the input.

Then, make the function:

void cars to print (...)

which will take as argument the two cars that have the lowest horsepower, and of those two, it will print the car that has the torque printed.


For example:

Input	Result
3
Opel
1999
577 
516
Audi
2000
591
590
Citroen
2020
220
321
Manufacturer: Opel
Horsepower: 577
Torque: 516
*/

#include <iostream>
#include <cstring>
using namespace std;

struct Engine{
    int horsePower, torque;
};

struct Car{
    char carName[20];
    int year;
};

void printCars(int n, Car *car, Engine *engine){
    int smallestHorsePower = engine[0].horsePower, index = 0;
    int indexTwo = 0;
    for(int i = 0; i < n; i++){
        if(smallestHorsePower > engine[i].horsePower){
            smallestHorsePower = engine[i].horsePower;
            indexTwo = index;
            index = i;
        }
    }
    
    cout<<"Manufacturer: "<< car[indexTwo].carName<<endl;
    cout<<"Horsepower: "<< engine[indexTwo].horsePower<<endl;
    cout<<"Torque: "<< engine[indexTwo].torque;
}

int main(){
    int n;
    cin >> n;
    Car car[n];
    Engine engine[n];
    
    for(int i = 0; i < n; i++){
        cin >> car[i].carName >> car[i].year;
        cin >> engine[i].horsePower >> engine[i].torque;
    }
    
    printCars(n, car, engine);
}