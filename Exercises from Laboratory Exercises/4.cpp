/*
Да се направи класа County која ќе ги содржи следните променливи:

name, низа од карактери
gdp, цел број
За класата да се направи default конструктор, целосно параметризиран конструктор и get методи за двете променливи.

Да се направи класа State која ќе ги содржи следните променливи:

counties, низа од County објекти
name, низа од карактери
numCounties, цел број
federalTax, децимален број за процент на данок кој е заеднички за сите објекти од оваа класа и може да се пристапи без креирање на инстанца од истата. Иницијално да е поставен на 15.5
redState, булеан вредност за дали државата е републиканска
За класата да се направи default конструктор, целосно параметризиран конструктор и следните функции:

get функции за променливите name, federalTax
set функција за променливата federalTax
increaseFederalTax(int increase) функција за зголемување на федералниот данок (моменталниот процент + додаток)
getFullGDP() функција која ќе го врати вкупниот ГДП на државата пресметан како збир на ГДП на сите окрузи (counties) на државата со одземен процент на федерален данок
print() метод што ќе печати во формат: "State of {име на држава} {во нов ред испечатени имињата на сите окрузи кои припаѓаат на државата}"
Дополнително да се дефинира функција friend void printStatesInGDPOrderByStateType(State states[], int numStates, bool redStates) која ќе ги печати сите држави во зависност дали се републиканска или демократска држава (одредено со променливата redStates дадена како аргумент на функцијата) подредени според големината на ГДП што ја имаат. Оваа функција треба да може директно да пристапува кон приватните членови на State класата

Create a County class that will contain the following variables:

name, a string of characters
gdp, integer
For the class, create a default constructor, a fully parameterized constructor and get methods for both variables.

Create a State class that will contain the following variables:

counties, an array of County objects
name, a string of characters
numCounties, integer
federalTax, a decimal number for the percentage of federal tax that is the same for all objects of this class and can be accessed without creating an instance of it. Initially set as 15.5
redState, boolean value for whether the state is Republican
For the class, make a default constructor, a fully parameterized constructor and the following functions:

get functions for the variables name, federalTax
set function for the federalTax variable
increaseFederalTax(int increase) function to increase the federal tax (current percentage + increase)
getFullGDP() function that will return the total GDP of the state calculated as the sum of the GDP of all counties of the state minus the percentage of federal tax
print() method that will print in the format: "State of {name of the state} {in a new line the names of all counties that belong to the state}"
Additionally define a function friend void printStatesInGDPOrderByStateType(State states[], int numStates, bool redStates) that will print all states depending on whether they are Republican or Democrat (determined by the variable redStates given as an argument to the function) ordered by their GDP size. This function should be able to directly access the private members of the State class.

For example:

Input	Result
1
13.2
---Testing constructors, getters, setters---
New York Federal tax: 13.2 Full GDP: 94.612
2
Wayne
---Testing print method---
State of New York
Richmond
Bronx
New York
Wayne
3
2.1
---Testing increaseFederalTax static method---
15.5
17.6
89.816
4
0
---Testing printStatesInGDPOrderByStateType---
Red states:
Blue states:
Ohio
New York
*/

#include <iostream>
#include <cstring>
using namespace std;

class County{
        char name[50];
        int gdp;
    public:
        County(){}
        
        County(char name[50], int gdp){
            strcpy(this->name, name);
            this->gdp = gdp;
        }
        
        ~County(){}

        char* getName(){
            return name;
        }
        
        int getGdp(){
            return gdp;
        }
};

class State{
        static float federalTax;
        char name[50];
        int numCounties;
        bool redState;
        County *counties;
    public:
        State(){}
        
        State(County *counties, char name[50], int numCounties, bool redState){
            strcpy(this->name, name);
            this->numCounties = numCounties;
            this->redState = redState;
            this->counties = new County[this->numCounties];
            for(int i = 0; i < this->numCounties; i++)
                this->counties[i] = counties[i];
        }
        
        ~State(){}
        
        char *getName(){
            return name;
        }
        
        bool getRedState(){
            return redState;
        }
        
        double getFullGDP(){
            double sum = 0;
            for(int i = 0; i < numCounties; i++)
                sum += counties[i].getGdp();
            sum = sum - (sum / 100 * federalTax);
            return sum;
        }
        
        static void increaseFederalTax(float plus){
            federalTax = federalTax + plus;
        }
        
        static void setFederalTax(float newTax){
            State::federalTax = newTax;
        }
        
        static float getFederalTax(){
            return federalTax;
        }
        
        void print(){
            cout<<"State of "<<name<<endl;
            for(int i = 0; i < numCounties; i++)
                cout<<counties[i].getName()<<endl;
        }
};

void printStatesInGDPOrderByStateType(State *states, int numStates, bool redStates){
    for(int i = 0; i < numStates - 1; i++){
        for(int j = 0; j < numStates - i - 1; j++){
            if(states[j].getFullGDP() < states[j + 1].getFullGDP())
                swap(states[j], states[j + 1]);
        }
    }
    for(int i = 0; i < numStates; i++)
        if(states[i].getRedState() == redStates)
            cout<<states[i].getName()<<endl;
}

//main should remain unchanged!
float State::federalTax = 15.5;

int main() {
    int n;
    cin >> n;
    char name[30] = "Richmond";
    County counties[3];
    counties[0] = County(name, 20);
    strcpy(name, "Bronx");
    counties[1] = County(name, 57);
    strcpy(name, "New York");
    counties[2] = County(name, 32);
    State state(counties, name, 3, false);
    switch(n){
        case 1: {
            cout << "---Testing constructors, getters, setters---" << endl;
            float fed;
            cin >> fed;
            State::setFederalTax(fed);
            if (State::getFederalTax() == 15.5) {
                cout << "State federal tax setter not OK!";
                break;
            }
            cout << counties[2].getName() << " Federal tax: " << State::getFederalTax() << " Full GDP: "
                 << state.getFullGDP();
            break;
        }
        case 2: {
            cout << "---Testing print method---" << endl;
            char name2[50];
            cin >> name2;
            County counties2[4];
            for (int i = 0; i < 3; ++i) {
                counties2[i] = counties[i];
            }
            counties2[3] = County(name2, 27);
            State state2(counties2, name, 4, false);
            state2.print();
            break;
        }
        case 3: {
            cout << "---Testing increaseFederalTax static method---" << endl;
            float increase;
            cin >> increase;
            cout << State::getFederalTax() << endl;
            State::increaseFederalTax(increase);
            cout << State::getFederalTax() << endl;
            cout << state.getFullGDP();
            break;
        }
        default:
            cout << "---Testing printStatesInGDPOrderByStateType---" << endl;
            County counties2[4];
            for (int i = 0; i < 3; ++i) {
                counties2[i] = counties[i];
            }
            strcpy(name, "Wayme");
            counties2[3] = County(name, 27);
            strcpy(name, "Ohio");
            State state2(counties2, name, 4, false);
            int numStates;
            cin >> numStates;
            numStates = numStates + 2;
            State states[numStates];
            states[0] = state;
            states[1] = state2;
            bool redStateSType;
            for (int i = 2; i < numStates; ++i) {
                char stateName[30];
                int numCounties;
                cin >> stateName >> numCounties >> redStateSType;
                County county[numCounties];
                for (int j = 0; j < numCounties; ++j) {
                    char ime[30];
                    int GDP;
                    cin >> ime >> GDP;
                    county[j] = County(ime, GDP);
                }
                states[i] = State(county, stateName, numCounties, redStateSType);
            }
            cout << "Red states: "<<endl;
            printStatesInGDPOrderByStateType(states, numStates, true);
            cout << "Blue states: "<<endl;
            printStatesInGDPOrderByStateType(states, numStates, false);

    }
    return 0;
}
