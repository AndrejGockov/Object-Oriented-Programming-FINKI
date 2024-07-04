/*
Да се дефинира класа TennisPlayer за чување на податоци за тенисери.

Во класата треба да се чуваат приватните податочни членови:
name - име на тенисерот (низа од знаци);
surname - презиме на тенисерот (низа од знаци);
rank - ранг на тенисерот (цел број, помал број се однесува на повисок ранг);
matchesPlayed - вкупен број на изиграни натпревари во кариерата на тенисерот (int);
matchesWon- вкупен број на победени натпревари во кариерата на тенисерот (int).
Дополнително да се дефинира default констурктор (констурктор без аргументи) и деструктор, како и соодветни гетери и сетери.

Во класата треба да биде имплементирана функција findPercentageWins која го наоѓа процентот на победени натпревари од вкупните изиграни натпревари за играчот.

Надвор од класата треба да се имплементира функциjaтa printHighestRankedPlayerBelow50PercentWins која го печати највисокиот рангиран тенисер чиј процент на победени натпревари (од вкупните) е помал од 50%.
Ако таков играч не постои, да се испечати пораката `No such tennis player.`
Не го менувајте дадениот код. Потребно е само да се прошири дадениот код.
Define the class TennisPlayer to store data for tennis players.

The class should store the following private data members:
name - the name of the tennis player (array of chars);
surname - the surname of the tennis player (array of chars);
rank - the rank of the tennis player (integer, smaller number corresponds to a higher rank);
matchesPlayed - the total number of matches played in the tennis player's career (int);
matchesWon- the total number of matches won in the tennis player's career (int).
Additionally, define a default constructor (constructor without arguments) and a destructor, as well as appropriate getters and setters.
Inside the class implement the function findPercentageWins that calculates the percentage of matches won out of the total matches played for the player.

Outside of the class, implement the function printHighestRankedPlayerBelow50PercentWins which prints the highest-ranked tennis player whose percentage of matches won (out of the total) is less than 50%. If such a player does not exist, print the message "No such tennis player."
Do not modify the code. Only extend the functionalities of the given code.
For example:

Input	Result
-1 10
Novak Djokovic 1 1310 1095
Carlos Alcaraz 2 780 640
Jannik Sinner 3 306 123
Daniil Medvedev 4 531 405
Andrey Rublev 5 344 310
Alexander Zverev 6 940 569
Holger Rune 7 1038 445
Hubert Hurkacz 8 974 883
Casper Ruud 9 345 104
Alex deMinaur 10 541 401
Jannik Sinner
-1 3
Daniil Medvedev 4 531 405
Andrey Rublev 5 344 310
Alexander Zverev 6 940 569
No such tennis player.
0
Testing default constructor and getters/setters
---
Full name: John Doe
Rank and won matches out of total: 55 50/100
1
Testing findPercentageWins function
---
Passed.
*/

#include <iostream>
#include <cstring>
using namespace std;
void test(int k);

class TennisPlayer{
        char name[100], surname[100];
        int rank, matchesPlayed, matchesWon;
    public:
        // Constructors
        TennisPlayer(){}
        
        TennisPlayer(char name[100], char surname[100], int rank, int matchesPlayed, int matchesWon){
            strcpy(this->name, name);
            strcpy(this->surname, surname);
            this->rank = rank;
            this->matchesPlayed = matchesPlayed;
            this->matchesWon = matchesWon;
        }
        
        ~TennisPlayer(){}
        
        // Functions
        float findPercentageWins (){
            return ((float)matchesWon / (float)matchesPlayed) * 100.0; 
        }
        
        // Getters & Setters
        void setName(char name[20]){
            strcpy(this->name, name);
        }
        void setSurname(char surname[20]){
            strcpy(this->surname, surname);
        }
        
        void setRank(int rank){
            this->rank = rank;
        }
        
        void setMatchesPlayed(int matchesPlayed){
            this->matchesPlayed = matchesPlayed;
        }
        
        void setMatchesWon(int matchesWon){
            this->matchesWon = matchesWon;
        }
        
        char *getName(){
            return name;
        }
        
        char *getSurname(){
            return surname;
        }
        
        int getRank(){
            return rank;
        }
        
        int getMatchesPlayed(){
            return matchesPlayed;
        }
        
        int getMatchesWon(){
            return matchesWon;
        }
};

// TODO: Define input arguments and implement function logic
void printHighestRankedPlayerBelow50PercentWins(TennisPlayer *players, int n) {
    int indx = -1;
    float highest = 10000;
    for(int i = 0; i < n; i++){
        if((indx == -1 || highest > players[i].getRank()) && players[i].findPercentageWins() < 50){
            indx = i;
            highest = players[i].getRank();
        }
    }
    
    if(indx == -1)
        cout<<"No such tennis player."<<endl;
    else
        cout << players[indx].getName() << " " << players[indx].getSurname() << endl;
}


int main() {
    int testCase;
    cin >> testCase;

    if (testCase == 0 || testCase == 1) {
        test(testCase);
        return 0;
    }

    int n;
    cin >> n;
    
    // TODO: Read input data for all tennis players
    TennisPlayer players[n];
    
    for(int i = 0; i < n; i++){
        char name[100], surname[100];
        int rank, matchesPlayed, matchesWon;
        cin >> name >> surname >> rank >> matchesPlayed >> matchesWon;
        players[i] = TennisPlayer(name, surname, rank, matchesPlayed, matchesWon);
    }
    
    // TODO: Pass correct input arguments
    printHighestRankedPlayerBelow50PercentWins(players ,n);
    
    return 0;
}

void test(int k) {
    if (k == 0) {
        cout << "Testing default constructor and getters/setters" << endl;
        cout << "---" << endl;
        TennisPlayer player = TennisPlayer();
        player.setName(new char[5] {'J', 'o', 'h', 'n', '\0'});
        player.setSurname(new char[5] {'D', 'o', 'e', '\0'});
        player.setRank(55);
        player.setMatchesPlayed(100);
        player.setMatchesWon(50);
        cout << "Full name: " << player.getName() << " " << player.getSurname() << endl;
        cout << "Rank and won matches out of total: " << player.getRank() << " " << player.getMatchesWon() << "/"
            << player.getMatchesPlayed() << endl;
    }
    else if (k == 1) {
        cout << "Testing findPercentageWins function" << endl;
        cout << "---" << endl;
        TennisPlayer player = TennisPlayer();
        player.setName(new char[5] {'J', 'o', 'h', 'n', '\0'});
        player.setSurname(new char[5] {'D', 'o', 'e', '\0'});
        player.setRank(55);
        player.setMatchesPlayed(100);
        player.setMatchesWon(50);
        if (player.findPercentageWins() != 50) {
            cout << "Test case failed." << endl;
            cout << "Expected: " << 0.5 << "; Got: " << player.findPercentageWins() << endl;
            return;
        }
        player.setMatchesWon(90);
        if (player.findPercentageWins() != 90) {
            cout << "Test case failed." << endl;
            cout << "Expected: " << 0.9 << "; Got: " << player.findPercentageWins() << endl;
            return;
        }
        cout << "Passed." << endl;
    }
}
