/*
Да се дефинира класа Speaker, која репрезентира предавач на конференција. За класата Speaker да се чуваат следниве информации:

Име на предавачот (стринг)

Наслов на предавањето (стринг)

Времетраење на предавањето во минути (цел број)

За Speaker класата да се имплементираат:

Потребните конструктори, потребните set и get методи (5 поени)

Оператор за печатење << во формат [ime] - [naslov_na_predavanje], [vremetraenje] (5 поени)

 Потоа, да се дефинира класа Conference во која ќе се чуваат информации за:

Код на конференцијата (стринг)

Датум на одржување на конференцијата (YYYY-MM-DD - стринг)

Листа од предавачи (вектор од објекти од класата Speaker)

Максималното дозволено траење е исто за сите конференции и е одредено од организаторот на конференциите, а иницијално изнесува 360 минути (6 часа -  се смета како збир на сите предавања на конференцијата).

За класата да се имплементираат:

Потребните конструктори, деструктор, set и get функции-членови (5 поени)

Оператор за печатење << во формат [kod] - [datum], [broj_na_registrirani_predavaci] (5 поени)

Оператор за споредба > кој споредува две конференции според бројот на предавачи (5 поени)

Оператор == за споредба на две конференции според датумот на одржување (5 поени)

Оператор += за додавање на нов предавач на конференцијата (5 поени). Предавач може да се додаде само ако вкупното времетраење на сите предавања од конференцијата не го надминува максималното траење на конференцијата. Доколку се обидеме да додадеме предавач со предавање кое ќе го надмине овој лимит, да се фрли исклучок од типот InvalidOperation со порака "Conference duration exceeded" и да се овозможи механизам за справување со овој исклучок во main. (10 поени)

Функција-член longestPresentation() - којa ќе го испечати предавањето со најдолго времетраење. (5 поени)
--

Define a class `Speaker` that represents a speaker at a conference. For the `Speaker` class, store the following information:

Speaker's name (string)
Title of the presentation (string)
Duration of the presentation in minutes (integer)
For the `Speaker` class, implement:

The necessary constructors, set and get methods (5 points)
Overload the << operator for printing in the format [name] - [title_of_presentation], [duration] (5 points)
Next, define a class `Conference` which will store information about:

Conference code (string)
Conference date (YYYY-MM-DD - string)
List of speakers (vector of `Speaker` objects)
The maximum allowed duration is the same for all conferences and is determined by the conference organizer, initially set to 360 minutes (6 hours - considered as the sum of all presentations at the conference).

For the `Conference` class, implement:

The necessary constructors, destructor, set and get member functions (5 points)
Overload the << operator for printing in the format [code] - [date], [number_of_registered_speakers] (5 points)
Overload the > operator which compares two conferences based on the number of speakers (5 points)
Overload the == operator for comparing two conferences based on the conference date (5 points)
Overload the += operator for adding a new speaker to the conference (5 points). A speaker can only be added if the total duration of all presentations at the conference does not exceed the maximum conference duration. If an attempt is made to add a speaker with a presentation that exceeds this limit, throw an exception of type `InvalidOperation` with the message "Conference duration exceeded" and provide a mechanism for handling this exception in `main`. (10 points)
Member function `longestPresentation()` - which will print the presentation with the longest duration. (5 points)
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class InvalidOperation
{
public:
    static void message()
    {
        cout << "Conference duration exceeded" << endl;
    }
};

class Speaker
{
    string presentor, lectureTitle;
    int length;

    void CopyS(const Speaker &other)
    {
        this->presentor = other.presentor;
        this->lectureTitle = other.lectureTitle;
        this->length = other.length;
    }

public:
    Speaker() {}
    // Speaker speaker1("John Doe", "Introduction to C++", 60);
    Speaker(string presentor, string lectureTitle, int length)
    {
        this->presentor = presentor;
        this->lectureTitle = lectureTitle;
        this->length = length;
    }

    Speaker(const Speaker &other)
    {
        CopyS(other);
    }

    Speaker &operator=(const Speaker &other)
    {
        if (this == &other)
            return *this;
        CopyS(other);
        return *this;
    }

    ~Speaker() {}

    int getLength()
    {
        return length;
    }

    friend ostream &operator<<(ostream &res, Speaker &s)
    {
        res << s.presentor << " - " << s.lectureTitle << ", " << s.length;
        return res;
    }
};

class Conference
{
    string conferenceCode, conferenceDate;
    vector<Speaker> speakers;
    static int maxDuration;

    void CopyConf(Conference &other)
    {
        this->conferenceCode = other.conferenceCode;
        this->conferenceDate = other.conferenceDate;
        for (int i = 0; i < other.speakers.size(); i++)
            this->speakers.push_back(other.speakers[i]);
    }

public:
    Conference() {}

    Conference(string conferenceCode, string conferenceDate)
    {
        this->conferenceCode = conferenceCode;
        this->conferenceDate = conferenceDate;
        // for(int i = 0; i < speakers.size(); i++)
        //     this->speakers.push_back(speakers[i]);
    }

    Conference(Conference &other)
    {
        CopyConf(other);
    }

    Conference &operator+=(Speaker &newSpeaker)
    {
        try
        {
            int totalHours = newSpeaker.getLength();
            for (int i = 0; i < speakers.size(); i++)
            {
                totalHours += speakers[i].getLength();
                if (totalHours > maxDuration)
                    throw InvalidOperation();
            }

            if (totalHours > maxDuration)
                throw InvalidOperation();

            speakers.push_back(newSpeaker);
            return *this;
        }
        catch (InvalidOperation &err)
        {
            err.message();
        }

        return *this;
    }

    ~Conference() {}

    static void setMaxDuration(int newMax)
    {
        maxDuration = newMax;
    }

    void longestPresentation()
    {
        int idx = -1;

        for (int i = 0; i < speakers.size(); i++)
        {
            if (idx == -1 || speakers[idx].getLength() < speakers[i].getLength())
            {
                idx = i;
            }
        }

        cout << "Longest Presentation: " << speakers[idx] << endl;
    }

    bool operator>(Conference &other)
    {
        return this->speakers.size() > other.speakers.size();
    }

    bool operator==(Conference &other)
    {
        return (this->conferenceDate == other.conferenceDate);
    }

    friend ostream &operator<<(ostream &res, Conference &conf)
    {
        res << conf.conferenceCode << " - " << conf.conferenceDate << ", " << conf.speakers.size();
        return res;
    }
};

int Conference::maxDuration = 360;

// Your code here
int main()
{
    int testCase;
    cin >> testCase;

    if (testCase == 0)
    {
        cout << "Speaker constructor" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);
        cout << "TEST PASSED" << endl;
    }
    else if (testCase == 1)
    {
        cout << "Speaker copy-constructor and operator=" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);

        Speaker c1 = speaker2;
        Speaker c3;
        c3 = speaker2;
        cout << c3 << endl;
        cout << "TEST PASSED" << endl;
    }
    else if (testCase == 2)
    {
        cout << "Speaker operator print" << endl;
        Speaker speaker1("Aleksandar Stojmenski", "Introduction to C++", 60);
        Speaker speaker2("Stefan Andonov", "Object-Oriented Programming", 120);
        Speaker speaker3("Boban Joksimoski", "Computer Animation", 180);
        cout << speaker1 << endl;
        cout << speaker2 << endl;
        cout << speaker3 << endl;
        cout << "TEST PASSED" << endl;
    }
    else if (testCase == 3)
    {
        cout << "Conference class" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);

        Conference conference("CONF001", "2023-07-01");
        conference += speaker1;
        conference += speaker2;
        conference += speaker3;

        cout << conference << endl;
    }
    else if (testCase == 4)
    {
        cout << "Conference constructors" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);

        Conference c("CONF001", "2023-07-01");
        c += speaker1;
        c += speaker2;
        Conference c1, c2 = c;
        c1 = c;
        c2 += speaker3;
        cout << c1 << endl;
        cout << c2 << endl;
    }
    else if (testCase == 5)
    {
        cout << "Conference operator> constructors" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);

        Conference c("CONF001", "2023-07-01");
        c += speaker1;
        c += speaker2;
        Conference c1, c2 = c;
        c2 += speaker3;
        if (c2 > c)
        {
            cout << "PASSED" << endl;
        }
    }
    else if (testCase == 6)
    {
        cout << "longestPresentation and comparison" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);
        Conference conference("CONF001", "2023-07-01");

        conference += speaker1;
        conference += speaker2;
        conference += speaker3;

        cout << "Conference: " << conference << endl;

        conference.longestPresentation();

        // Test case for comparison operators
        Conference conference2("CONF002", "2023-07-01");
        conference2 += speaker1;
        conference2 += speaker2;

        if (conference > conference2)
        {
            cout << "CONF001 has more speakers than CONF002." << endl;
        }
        else
        {
            cout << "CONF001 has fewer speakers than CONF002." << endl;
        }

        // Test case for exceeding duration limit
        Speaker speaker4("Sarah Adams", "Advanced C++ Programming", 240);
    }
    else if (testCase == 7)
    {
        cout << "Exception handling" << endl;
        cout << "longestPresentation and comparison" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);
        Conference conference("CONF001", "2023-07-01");
        conference += speaker1;
        conference += speaker2;
        conference += speaker3;
        Conference conference2("CONF002", "2023-07-01");
        conference2 += speaker1;
        conference2 += speaker2;
        if (conference > conference2)
        {
            cout << "CONF001 has more speakers than CONF002." << endl;
        }
        else
        {
            cout << "CONF001 has fewer speakers than CONF002." << endl;
        }
        Speaker speaker4("Sarah Adams", "Advanced C++ Programming", 240);

        conference += speaker4;
    }
    else if (testCase == 8)
    {
        Conference conference4("CONF004", "2023-07-01");
        Conference conference5("CONF005", "2023-07-01");

        Speaker speaker9("Alex Turner", "Network Security", 120);
        Speaker speaker10("Olivia Parker", "Artificial Intelligence", 180);

        conference4 += speaker9;
        conference5 += speaker10;

        cout << "Conference 4: " << conference4 << endl;
        cout << "Conference 5: " << conference5 << endl;

        if (conference4 == conference5)
        {
            cout << "Conference 4 and Conference 5 have the same date." << endl;
        }
        else
        {
            cout << "Conference 4 and Conference 5 have different dates." << endl;
        }
    }
    else if (testCase == 9)
    {
        Conference conference3("CONF003", "2023-07-01");

        Conference::setMaxDuration(1000);
        Speaker speaker5("Michael Brown", "Web Development", 180);
        Speaker speaker6("Emily Davis", "Machine Learning", 240);
        Speaker speaker7("Robert Wilson", "Software Engineering", 120);

        conference3 += speaker5;
        conference3 += speaker6;
        conference3 += speaker7;

        cout << "Conference 3: " << conference3 << endl;

        Speaker speaker8("Jessica Lee", "Database Management", 180);

        conference3 += speaker8;
        cout << conference3;
    }
    return 0;
}