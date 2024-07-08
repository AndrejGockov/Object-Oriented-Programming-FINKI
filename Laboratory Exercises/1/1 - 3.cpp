/*
Да се напише програма во која од стандарден влез се внесува бројот N (бројот на фудбалски тимови) и информациите за N-те фудбалски тимови.

Една структура за Фудбалски тим (FootballTeam) треба да ги чува следните информации:
- Името на тимот (низа од карактери)
- Низа од играчи (претставени преку структурата FootballPlayer, при што еден тим секогаш ќе има 11 играчи)

Во структурата Фудбалски играч (FootballPlayer) треба да се чуваат следните информации:
- Името на играчот (низа од карактери)
- Број на дресот (int)
- Број на дадени голови (int)

Ограничување: 0 < N < 100

Ваша задача е да направите функција void bestTeam(FootballTeam * teams, int n) која ќе го печати тимот со најмногу дадени голови (во случај да има повеќе тима со ист број на голови треба да се печати првиот што е внесен). Внесувањето на податоците да се направи во main-от, при што редоследот на влезните податоци ќе е следниот:

N
team_name_1
player_name_1 number_1 goals_1
...
player_name_11 number_11 goals_11
team_name_2
player_name_1 number_1 goals_1
...
player_name_11 number_11 goals_11

...

team_name_n
player_name_1 number_1 goals_1
...
player_name_11 number_11 goals_11

_______________________________

Write a program in which the number N (the number of football teams) and the information about the N football teams are entered from standard input.

A structure for FootballTeam should store the following information:

- Team name (character string)

- Array of players (represented via the FootballPlayer structure, where a team will always have 11 players)

The following information should be stored in the FootballPlayer structure:

- Player name (character string)

- Jersey number (int)

- Number of goals scored (int)

Limit: 0 < N < 100

Your task is to make a function void bestTeam(FootballTeam * teams, int n) that will print the team with the most given goals (in case there are more teams with the same number of goals, the first entered should be printed). Entering the data should be done in the main, while the order of the input data will be as follows:

N

team_name_1

player_name_1 number_1 goals_1

...

player_name_11 number_11 goals_11

team_name_2

player_name_1 number_1 goals_1

...

player_name_11 number_11 goals_11

...

team_name_n

player_name_1 number_1 goals_1

...

player_name_11 number_11 goals_11

For example:

Input	Result
2
Arsenal
Baro 14 1
Lubomir 16 4
Lubomir 1 3
Paul 35 8
Jakov 22 8
Jovan 7 3
Kristijan 18 4
Nikola 14 8
Mile 24 9
Vlatko 27 8
Ivan 43 0
PSG
Paul 49 11
Sasho 33 7
Ivo 35 4
Maksim 28 7
Bojan 25 2
Goran 32 8
Andrej 13 3
Mile 30 6
Jakov 31 1
Jovan 35 6
Ivan 37 4
Najdobar tim e: PSG
*/
#include <iostream>
#include <cstring>
using namespace std;

struct FootballTeam{
    char teamName[50];
    
    // Entering teamName
    void inputTeam(){
        cin >> teamName;
    }
};

struct FootballPlayer{
    char playerName[11][50];
    int brDress[11], dadeniGolovi[11];
    
    // Entering  playerName, brDress & dadeniGolovi
    void inputPlayer(){
        for(int i = 0; i < 11; i++){
            cin >> playerName[i];
            cin >> brDress[i] >> dadeniGolovi[i];
        }
    }
};

void printBestTeam(int n, FootballTeam *footballTeam, FootballPlayer *footballPlayer){
    // Sums up every team's total goals
    // Compares with the highest teams goals, if higher it updates mostGoals and index
    // index - points to the team with the most goals
    int mostGoals = 0, index = 0;
    for(int i = 0; i < n; i++){
        int currentTeamGoals = 0;
        for(int j = 0; j < 11; j++)
            currentTeamGoals += footballPlayer[i].dadeniGolovi[j];
        
        if(currentTeamGoals > mostGoals){
            mostGoals = currentTeamGoals;
            index = i;
        }
    }
    
    cout<<"Najdobar tim e: "<<footballTeam[index].teamName;
}

int main(){
    int n;
    cin >> n;
    FootballTeam footballTeam[n];
    FootballPlayer footballPlayer[n];
    
    // Entering Team and Player Fields
    for(int i = 0; i < n; i++){
        footballTeam[i].inputTeam();
        footballPlayer[i].inputPlayer();
    }
    
    printBestTeam(n, footballTeam, footballPlayer);
    
    return 0;
}