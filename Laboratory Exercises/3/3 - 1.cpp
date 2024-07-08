/*
Во рамките на една видео игра се чуваат податоци за кориснички профили (UserProfile) и нивните достигнувања во играта (Achievement). Вие треба да ги дефинирате класите и функциите за коректна имплементација на системот. Не го менувајте дадениот код.


За таа цел, дефинирајте класа Achievement со приватни податочни членки:

name - име на достигнувањето (низа од знаци);
description - опис на достигнувањето (низа од знаци);
totalUserAchievements - вкупен број на достигнувања на сите кориснички профили (static int).
Дополнете ја класата со default конструктор, конструктор со аргументи и copy конструктор како и следните функции:

print - функција која ги печати името и описот на достигнувањето во нов ред;
incrementTotalUserAchievements - функција која ја зголемува вредноста на totalUserAchievements за 1.
Потребно е да работите без get/set методи.


Понатаму, дефинирајте класа UserProfile со приватни податочни членки:

name - име на профилот (низа од знаци);
achievements - низа од добиени достигнувања на корисникот за дадената игра (максимална големина е 50);
n - број на добиени достигнувања на корисникот за дадената игра (иницијално поставен на 0).
Дополнете ја класата со default конструктор и конструктор со аргумент name.
Напишете ги функциите:

print - функција која го печати името на корисникот и неговите добиени достигнувања во играта во формат даден во тест примерите.
void addAchievement(const Achievement& achievement) - функција која во низата од достигнувања achievements го додава достигнувањето achievement и ја зголемува вредноста на totalUserAchievements.
На крај, да се напише функција void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m) која директно пристапува до приватните членки на класите Achievement и UserProfile, и за секое достигнување во играта на екран ќе ги испечати името и описот на достигнувањето, како и процентот на корисници кои го добиле тоа достигнување. На крај да се испечати просечниот број на добиени достигнувања со формулата totalUserAchievements * 100.0 / (n * m). Форматот на печатењето е даден во тест примерите.

---------------------------------------


For each video game, data about user profiles (UserProfile) and their achievements in the game (Achievement) are stored. You need to define the classes and functions for the correct implementation of the system. Do not modify the given code.

For this purpose, define the Achievement class with private data members:

name - name of the achievement (char array); 
description - description of the achievement (char array); 
totalUserAchievements - total number of achievements across all user profiles (static int). 
Supplement the class with a default constructor, a constructor with arguments, and a copy constructor as well as the following functions:

print - a function that prints the name and description of the achievement on a new line; 
incrementTotalUserAchievements - a function that increments the value of totalUserAchievements by 1. 
You are required to work without get/set methods.

Furthermore, define the UserProfile class with private data members:

name - name of the profile (char array); 
achievements - an array of achievements obtained by the user for the given game (maximum size is 50); 
n - number of achievements obtained by the user for the given game (initially set to 0). 
Supplement the class with a default constructor and a constructor with an argument name. Write the functions:

print - a function that prints the name of the user and their obtained achievements in the game in the format given in the test examples. 
void addAchievement(const Achievement& achievement) - a function that adds the achievement achievement to the array of achievements achievements and increments the value of totalUserAchievements. 
Finally, write a function void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m) which directly accesses the private members of the Achievement and UserProfile classes, and for each achievement in the game, it will print on the screen the name and description of the achievement, as well as the percentage of users who have obtained that achievement. At the end, print the average number of obtained achievements with the formula totalUserAchievements * 100.0 / (n * m). The printing format is given in the test examples.



For example:

Input	Result
Testing Achievement methods.
1
ALL USERS:
Anonymous31
2
ALL ACHIEVEMENTS:
Secret Achievement 1
"Description is hidden for this achievement."
Final boss
"Reach the final stage."
2
LIST OF NUMBERS where user [num1] has achievement [num2]:
1 1
1 2
Secret Achievement 1
"Description is hidden for this achievement."
Final boss
"Reach the final stage."
Testing UserProfile methods.
2
ALL USERS:
Anonymous31
UltimateGamer
2
ALL ACHIEVEMENTS:
Secret Achievement 1
"Description is hidden for this achievement."
Final boss
"Reach the final stage."
3
LIST OF NUMBERS where user [num1] has achievement [num2]:
1 1
1 2
2 2
User: Anonymous31
Achievements:
Secret Achievement 1
"Description is hidden for this achievement."
Final boss
"Reach the final stage."
User: UltimateGamer
Achievements:
Final boss
"Reach the final stage."
Testing showAchievementsProgress function.
2
ALL USERS:
Anonymous31
UltimateGamer
2
ALL ACHIEVEMENTS:
Secret Achievement 1
"Description is hidden for this achievement."
Final boss
"Reach the final stage."
3
LIST OF NUMBERS where user [num1] has achievement [num2]:
1 1
1 2
2 2
Secret Achievement 1
"Description is hidden for this achievement."
---Percentage of users who have this achievement: 50%
Final boss
"Reach the final stage."
---Percentage of users who have this achievement: 100%
------Average completion rate of the game: 75%
*/

//
// Created by PeceG.
//
#include <iostream>
#include <cstring>
using namespace std;
class UserProfile;


class Achievement {
private:
    char name[100];
    char description[100];
    static int totalUserAchievements;

public:
    Achievement() = default;
    Achievement(const char* name, const char* description) {
        strcpy(this->name, name);
        strcpy(this->description, description);
    }
    Achievement(const Achievement& a) {
        strcpy(this->name, a.name);
        strcpy(this->description, a.description);
    }

    void print() const {
        cout << name << endl << description << endl;
    }

    static void incrementTotalUserAchievements() {
        ++totalUserAchievements;
    }

    friend void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m);
};
int Achievement::totalUserAchievements = 0;


class UserProfile {
private:
    char name[100];
    Achievement achievements[50];
    int n;

public:
    UserProfile() {
        this->n = 0;
    }
    UserProfile(const char* name) {
        strcpy(this->name, name);
        this->n = 0;
    }

    void addAchievement(const Achievement& achievement) {
        achievements[n++] = achievement;
        Achievement::incrementTotalUserAchievements();
    }

    void print() {
        cout << "User: " << name << endl;
        cout << "Achievements: " << endl;
        for (int i = 0; i < n; ++i)
            achievements[i].print();
    }

    friend void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m);
};


void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m) {
    for (int i = 0; i < m; ++i) {  // for each achievement
        int numberOfUsersThatHaveAchievement = 0;
        for (int j = 0; j < n; ++j) {  // for each user
            bool has_achievement = false;
            for (int k = 0; k < profiles[j].n; ++k) { // try to match any of user achievements with outermost achievement
                if (strcmp(achievements[i].name, profiles[j].achievements[k].name) == 0) {
                    has_achievement = true;
                    break;
                }
            }
            numberOfUsersThatHaveAchievement += (has_achievement ? 1 : 0);
        }
        achievements[i].print();
        cout << "---Percentage of users who have this achievement: " << numberOfUsersThatHaveAchievement * 100.0 / n << "%" << endl;
    }
    cout << "------Average completion rate of the game: " << Achievement::totalUserAchievements * 100.0 / (n * m) << "%" << endl;
}


// Don't modify
int main() {
    char testcase[100];
    cin.getline(testcase, 100);

    int n;
    cin >> n;
    cin.ignore();

    char ignore[100];
    cin.getline(ignore, 100);
    UserProfile users[100];
    for (int i = 0; i < n; ++i) {
        char name[100];
        cin >> name;
        users[i] = UserProfile(name);
    }

    int m;
    cin >> m;
    cin.ignore();

    cin.getline(ignore, 100);
    Achievement achievements[100];
    for (int i = 0; i < m; ++i) {
        char name[100], description[100];
        cin.getline(name, 100);
        cin.getline(description, 100);
        achievements[i] = Achievement(name, description);
    }

    int k;
    cin >> k;
    cin.ignore();

    cin.getline(ignore, 100);
    for (int i = 0; i < k; ++i) {
        int numUser, numAchievement;
        cin >> numUser >> numAchievement;
        numUser -= 1;
        numAchievement -= 1;
        users[numUser].addAchievement(achievements[numAchievement]);
    }

    if (testcase[8] == 'A') {  // Testing Achievement methods.
         for (int i = 0; i < m; ++i) {
             achievements[i].print();
         }
         Achievement::incrementTotalUserAchievements();
    } else if (testcase[8] == 'U') {  // Testing UserProfile methods.
        for (int i = 0; i < n; ++i) {
            users[i].print();
        }
    } else {  // Testing showAchievementsProgress function.
        showAchievementsProgress(users, n, achievements, m);
    }

    return 0;
}