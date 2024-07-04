/*
Да се дефинира функциски темплејт filter кој ќе прими три аргументи:

динамички алоцирана низа од елемент
бројот на елементи во динамички алоцираната низа
елемент
Функцискиот темплејт треба да врати вектор од сите елементи од динамичката низа (првиот аргумент) кои се помали од елементот предаден како трет аргумент на функцијата.

--

Define a function template `filter` that takes three arguments:

a dynamically allocated array of elements
the number of elements in the dynamically allocated array
 an element
The function template should return a vector of all elements from the dynamic array (the first argument) that are smaller than the element passed as the third argument to the function.

For example:

Input	Result
1
5
10 20 30 40 50
35
10 20 30
2
4
apple banana cherry date
cherry
apple banana
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// TODO your code here
template <typename T>

vector<T> filter(T *arr, int n, T threshold)
{
    vector<T> ans;
    for (int i = 0; i < n; i++)
        if (arr[i] < threshold)
            ans.push_back(arr[i]);
    return ans;
}

int main()
{
    int testCase;
    cin >> testCase;

    if (testCase == 1)
    {
        // Test case 1: Filter integers
        int intSize;
        cin >> intSize;
        int *intArray = new int[intSize];
        for (int i = 0; i < intSize; i++)
        {
            cin >> intArray[i];
        }
        int intThreshold;
        cin >> intThreshold;
        vector<int> intResult = filter(intArray, intSize, intThreshold);
        for (int val : intResult)
        {
            cout << val << " ";
        }
        cout << endl;

        // Clean up dynamically allocated memory
        delete[] intArray;
    }
    else if (testCase == 2)
    {
        // Test case 2: Filter strings
        int strSize;
        cin >> strSize;
        string *strArray = new string[strSize];
        for (int i = 0; i < strSize; i++)
        {
            cin >> strArray[i];
        }
        string strThreshold;
        cin >> strThreshold;
        vector<string> strResult = filter(strArray, strSize, strThreshold);
        for (string val : strResult)
        {
            cout << val << " ";
        }
        cout << endl;

        // Clean up dynamically allocated memory
        delete[] strArray;
    }

    return 0;
}
