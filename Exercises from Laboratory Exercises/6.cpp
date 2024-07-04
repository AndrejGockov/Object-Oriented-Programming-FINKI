/*
Да се напише класа Ingredient која ги содржи следните податоци за една состојка:

name - име на состојката, динамички алоцирана низа од карактери;
quantity - количина
calories - колку калории содржи состојката


За класата да се напишат default конструктор, конструктор со аргументи, copy конструктор и десктруктор. 

Метод кој што ќе го враќа бројот на калории на состојката: quantity*calories

Да се преоптовари операторот << за да ги печати објектите од класата во следниот формат: [name] [quantity]

Да се преоптовари операторот = .



Потоа да се дефинира класата Dish, која ги содржи следните податоци:

ingredients - динамички алоцирана низа од Ingredient објекти
dishName - динамички алоцирана низа од цели karakteri
ingredientCount - број на состојки во јадењето 
За класата да се дефинираат конструктор со параметри, copy конструктор, деструктор, како и следните методи:

Метод getTotalCaloreis кој што ќе го враќа бројот на калории на специјалитетот за сите состојки
оператор + кој како резултат дава ново јадење со состојки од двете јадења
оператор += кој во јадењето ќе додава нови состојки
оператор == кој ќе проверува дали две јадења имаат ист број на калории
оператор << за печатење на објектот во следниот формат: 
Dish: Pizza

- Tomato: 200g/ml

- Cheese: 50g/ml

Total Calories: 6500



Да не се менува main функцијата. Се признаваат и решенија без динамичка алокација на меморија.





------------------------------------------------------------------------------------------------------------

Write a class Ingredient that contains the following data for one ingredient:

name - the name of the ingredient, dynamically allocated array of characters;
quantity - quantity;
calories - how many calories the ingredient contains.
For the class, write a default constructor, a constructor with parameters, a copy constructor, and a destructor. Write a method that returns the number of calories for the ingredient: quantity * calories. Overload the << operator to print objects of the class in the following format: [name] [quantity]. Overload the = operator.

Then define the class Dish, which contains the following data:

ingredients - dynamically allocated array of Ingredient objects;
dishName - dynamically allocated array of characters;
ingredientCount - the number of ingredients in the dish.
For the class, define constructors with parameters, a copy constructor, a destructor, as well as the following methods:

A method getTotalCalories that returns the number of calories for the dish, considering all ingredients.
An operator+ that returns a new dish with ingredients from both dishes.
An operator+= that adds new ingredients to the dish.
An operator== that checks if two dishes have the same number of calories.
An operator<< for printing the object in the following format:
Dish: Pizza

- Tomato: 200g/ml

- Cheese: 50g/ml

Total Calories: 6500

Do not modify the main function. Solutions without dynamic memory allocation are also accepted.
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Ingredient{
    char *name;
    int quantity, calories;
    void Copy(const Ingredient &other){
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->quantity = other.quantity;
        this->calories = other.calories;
    }
    public:
        Ingredient(){}
        
        Ingredient(char *name, int quantity, int calories){
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
            this->quantity = quantity;
            this->calories = calories;
        }
        
        Ingredient(const Ingredient &other){
            Copy(other);
        }
        
        Ingredient &operator=(const Ingredient &other){
            if(this == &other)
                return *this;
            Copy(other);
            return *this;
        }
        
        ~Ingredient(){
            delete[]name;
        }
        
        int totalCalories(){
            return quantity * calories;
        }
        
        friend ostream &operator<<(ostream &res, Ingredient &ing){
            res<<ing.name<<": "<<ing.quantity<<"g/ml";
            return res;
        }
};

class Dish{
        Ingredient *ingredients;
        char *dishName;
        int ingredientCount;
    public:
        Dish(){}
        
        Dish(char *dishName){
            this->dishName = new char[strlen(dishName) + 1];
            strcpy(this->dishName, dishName);
            this->ingredientCount = 0;
            ingredients = nullptr;
        }
        
        Dish(char *dishName, Ingredient *ingredients, int ingredientCount){
            this->dishName = new char[strlen(dishName) + 1];
            strcpy(this->dishName, dishName);
            this->ingredientCount = ingredientCount;
            this->ingredients = new Ingredient[ingredientCount];
            
            for(int i = 0; i < ingredientCount; i++)
                this->ingredients[i] = ingredients[i];
        }
        
        ~Dish(){
            delete[]dishName;
            delete[]ingredients;
        }
        
        Dish operator+(const Dish &other) const{
            Dish newDish;
            newDish.setDishName(other.dishName);
            int newIngredientCount = this->ingredientCount + other.ingredientCount;
            newDish.ingredients = new Ingredient[newIngredientCount];
            
            for (int i = 0; i < other.ingredientCount; ++i) {
                newDish.ingredients[i] = other.ingredients[i];
            }
            
            for (int i = 0; i < this->ingredientCount; ++i) {
                newDish.ingredients[this->ingredientCount + i] = this->ingredients[i];
            }

            newDish.ingredientCount = newIngredientCount;
            return newDish;
        }
        
        Dish &operator+=(const Ingredient &other){
            Ingredient *tmp = new Ingredient[ingredientCount + 1];
            for(int i = 0; i < ingredientCount; i++)
                tmp[i] = ingredients[i];
            
            tmp[ingredientCount++] = other;
            delete[]ingredients;
            ingredients = new Ingredient[ingredientCount];
            
            for(int i = 0; i < ingredientCount; i++)
                ingredients[i] = tmp[i];
            delete[]tmp;
            
            return *this;
        }
        
        bool operator==(Dish &other){
            return (this->getTotalCaloreis() == other.getTotalCaloreis());
        }
        
        int getTotalCaloreis(){
            int res = 0;
            for(int i = 0; i < ingredientCount; i++)
                res += ingredients[i].totalCalories();
            return res;
        }
        
        void setDishName(char *newName){
            this->dishName = new char[strlen(newName) + 1];
            strcpy(this->dishName, newName);
        }
        
        friend ostream &operator<<(ostream &res, Dish &d){
            res<<"Dish: "<<d.dishName<<endl;
            for(int i = 0; i < d.ingredientCount; i++)
                res<<"- "<<d.ingredients[i]<<endl;
            res<<"Total Calories: "<<d.getTotalCaloreis()<<endl;
            return res;
        }
};

int main() {

    char name [50];
    cin>>name;
    // Create Ingredients
    Ingredient tomato(name, 200, 20);
    cin>>name;
    Ingredient onion(name, 100, 30);
    cin>>name;
    Ingredient cheese(name, 50, 50);


    cin>>name;
    // Create Dishes
    Dish salad(name);
    salad += tomato;
    salad += onion;

    cin>>name;
    Dish pizza(name);
    pizza += tomato;
    pizza += cheese;

    // Test + operator
    Dish combinedDish = salad + pizza;
    cout<<combinedDish;

    cout<<"---------------------"<<endl;

    // Test = operator
    Ingredient ingredient = tomato;
    cout<<ingredient;
    cout<<endl;

    cout<<"---------------------"<<endl;

    // Test == operator
    if (salad == pizza) {
        cout << "Salad and Pizza have the same calories." << endl;
    } else {
        cout << "Salad and Pizza do not have the same calories." << endl;
    }

    cout<<"---------------------"<<endl;

    //Test << operator
    cout << "Salad:" << endl;
    cout << salad;

    cout << "Pizza:" << endl;
    cout << pizza;

    return 0;
}