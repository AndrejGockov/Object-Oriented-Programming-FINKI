/*
Да се дефинира класа Temperatures во која се чуваат податоци за просечните температури (вектор од реални броеви) за даден месец (цел број) и година (цел број).

Да се дефинира конструктор со аргументи. Доколку бројот на предадени температури е помал од 28, да се дополнат останатите температури со 0 додека бројот на температури да стане 28, а потоа да се испечати Filled <month>/<year> with 0's. (Користете ја `insert` функцијата од класата `vector`)

Дефинирајте сопствени функции кои ќе ја најдат највисоката температура во месецот, како и наоѓање на денот кога се достигнала таа температура.

Дополнително преоптоварете ги следните оператори:

<< - оператор за печатење во форма Max temp of <maximum_temperature> on <day>/<month>/<year> каде maximum_temperature и day треба да ги најдете со ваши функции;
== - оператор за еднаквост кој споредува два објекти од тип Temperatures. Два објекти се еднакви ако имаат ист месец и година;
> - оператор за споредба каде еден објект од тип Temperatures е поголем од друг објект акко соодветната максимална температура е поголема.
Define a class Temperatures that stores data about average temperatures (vector of floats) for a given month (integer) and year (integer).

Define a constructor with arguments. If the number of given temperatures is less than 28, fill the remaining temperatures with 0 until the number of temperatures reaches 28, and then print Filled <month>/<year> with 0's. (Use the `insert` function from the class `vector`)

Define custom functions to find the highest temperature in the month, as well as finding the day when the highest temperature was reached.

Additionally, overload the following operators:

<< - operator for printing in the form Max temp of <maximum_temperature> on <day>/<month>/<year> where maximum_temperature and day should be found using your functions;
== - equality operator that compares two objects of type Temperatures. Two objects are equal if they have the same month and year;
> - comparison operator where one object of type Temperatures is greater than another object if the corresponding maximum temperature is higher.

For example:

Input	Result
1
Testing constructor and operator <<
---------------
Filled 5/2024 with 0's
Max temp of 28.1 on 27/4/2024
Max temp of 29.02 on 15/5/2024
Test passed!
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Temperatures
{
    vector<float> temperatures;
    int givenMonth, year;

public:
    Temperatures() {}

    Temperatures(int givenMonth, int year, vector<float> temperatures)
    {
        this->year = year;
        this->givenMonth = givenMonth;
        for (int i = 0; i < temperatures.size(); i++)
            this->temperatures.push_back(temperatures[i]);

        if (temperatures.size() < 28)
        {
            for (int i = this->temperatures.size(); i < 28; i++)
                this->temperatures.push_back(0);
            cout << "Filled " << this->givenMonth << "/" << this->year << " with 0's" << endl;
        }
    }

    ~Temperatures() {}

    vector<float> getTemperatures()
    {
        return temperatures;
    }

    float maxTemperature()
    {
        float ans = temperatures[0];
        for (int i = 0; i < temperatures.size(); i++)
            if (ans < temperatures[i])
                ans = temperatures[i];
        return ans;
    }

    int hottestDay()
    {
        int indx = -1;
        for (int i = 0; i < temperatures.size(); i++)
        {
            if (indx == -1 || temperatures[indx] < temperatures[i])
            {
                indx = i;
            }
        }
        if (indx == -1)
            indx = 0;
        return indx;
    }

    bool operator>(Temperatures &other)
    {
        return (this->maxTemperature() > other.maxTemperature());
    }

    bool operator==(Temperatures &other)
    {
        return (this->year == other.year && this->givenMonth == other.givenMonth);
    }

    friend ostream &operator<<(ostream &res, Temperatures &temp)
    {
        res << "Max temp of " << temp.maxTemperature() << " on " << temp.hottestDay() << "/" << temp.givenMonth << "/" << temp.year << endl;
        return res;
    }
};

// don't modify
int main()
{
    vector<float> t1s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
                         27, 28.1};
    vector<float> t2s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 29.02, 17, 18, 19, 20, 21, 22, 23, 24};
    vector<float> t3s = {23.17, 21.72, 27.09, 24.17, 15.39, 19.22, 26.02, 15.66, 19.6, 23.0, 14.79, 27.02, 24.44, 25.73,
                         27.58, 18.86, 23.54, 27.42, 20.56, 19.7, 14.44, 26.2, 18.39, 22.86, 15.92, 14.01, 15.89, 22.7,
                         27.14, 24.75};
    vector<float> t4s = {21.12, 20.46, 23.99, 26.62, 18.14, 13.92, 24.39, 26.46, 12.81, 24.97, 18.7, 15.38, 16.0, 26.1,
                         20.78, 11.57, 25.62, 21.77, 26.27, 28.43, 15.8, 18.22, 27.92, 19.86, 17.86, 16.91, 25.38,
                         23.22, 27.53, 11.49};

    int testcase;
    cin >> testcase;

    switch (testcase)
    {
    case 1:
    {
        cout << "Testing constructor and operator <<" << endl;
        cout << "---------------" << endl;
        Temperatures t1(4, 2024, t1s);
        Temperatures t2(5, 2024, t2s);
        cout << t1 << t2;
        if (t2.getTemperatures().size() == 28)
        {
            cout << "Test passed!" << endl;
        }
        else
        {
            cout << "Test failed. Number of appended 0's is incorrect." << endl;
        }
        break;
    }
    case 2:
    {
        cout << "Testing operators == and >" << endl;
        cout << "---------------" << endl;
        Temperatures t1(4, 2024, t1s);
        Temperatures t2(5, 2024, t3s);
        Temperatures t3(3, 2024, t4s);
        Temperatures t4(5, 2024, t1s);

        cout << (t1 == t2) << " " << (t1 == t3) << " " << (t2 == t4) << " " << (t3 == t4) << endl;
        cout << (t1 > t2) << " " << (t1 > t3) << " " << (t2 > t3) << " " << (t3 > t2) << endl;
        break;
    }
    case 3:
    {
        cout << "Testing max temperature functions" << endl;
        cout << "---------------" << endl;
        Temperatures t1(4, 2024, t1s);
        Temperatures t2(5, 2024, t3s);
        Temperatures t3(3, 2024, t4s);
        Temperatures t4(5, 2023, t1s);
        cout << t1 << t2 << t3 << t4;
        break;
    }
    }

    return 0;
}
