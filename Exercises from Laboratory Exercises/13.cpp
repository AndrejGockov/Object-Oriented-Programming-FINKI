/*
Дефинирајте класа ShoppingList која ќе чува два вектори од стрингови (еден вектор за артиклите на шопинг листата и еден вектор за артиклите кои не е дозволено да се додадат на листата).

За класата, дефинирајте:

Конструктор со еден аргумент (ограничените артикли).
Операторот += за додавање артикл (стринг) на шопинг листата.
Артиклот се додава само ако не се наоѓа во векторот на ограничените артикли.
Операторот -= за бришење артикл (стринг) од шопинг листата.
Операторот << за печатење на артиклите од шопинг листата, одделени со запирка и простор.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Define a class ShoppingList which will store two vectors of strings (one vector for the items on the shopping list and one vector for the items that are not allowed to be added to the list).

For the class, define:

A constructor with one argument (the restricted items).
The operator += for adding an item (string) to the shopping list.
The item is added if and only if it is not found in the vector of restricted items.
The operator -= for deleting an item (string) from the shopping list.
The operator << for printing the items of the shopping list, separated by a comma and a space.
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class ShoppingList
{
    vector<string> shoppingArticle;
    vector<string> restrictedItems;

public:
    ShoppingList() {}

    ShoppingList(vector<string> restrictedItems)
    {
        for (int i = 0; i < restrictedItems.size(); i++)
        {
            this->restrictedItems.push_back(restrictedItems[i]);
        }
    }

    ~ShoppingList() {}

    // Operators
    ShoppingList &operator+=(string newItem)
    {
        try
        {
            for (int i = 0; i < this->restrictedItems.size(); i++)
            {
                if (this->restrictedItems[i] == newItem)
                    throw 0;
            }

            this->shoppingArticle.push_back(newItem);
        }
        catch (int j)
        {
        }
    }

    ShoppingList &operator-=(string deleteItem)
    {
        for (int i = 0; i < this->shoppingArticle.size(); i++)
        {
            if (this->shoppingArticle[i] == deleteItem)
                this->shoppingArticle.erase(next(this->shoppingArticle.begin(), i));
        }
    }

    friend ostream &operator<<(ostream &res, ShoppingList &list)
    {
        for (int i = 0; i < list.shoppingArticle.size(); i++)
        {
            res << list.shoppingArticle[i];
            if (i + 1 != list.shoppingArticle.size())
                res << ", ";
        }
        return res;
    }
};

int main()
{
    vector<string> restrictedItems;
    string restrictedItem;
    while (cin >> restrictedItem)
    {
        if (restrictedItem == "done")
        {
            break;
        }
        restrictedItems.push_back(restrictedItem);
    }
    ShoppingList list(restrictedItems);
    string item;
    while (cin >> item)
    {
        if (item == "exit")
        {
            break;
        }
        list += item;
    }
    cout << list << endl;
    cin >> item;
    list -= item;
    cout << list << endl;

    return 0;
}
