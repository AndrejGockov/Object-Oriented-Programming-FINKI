/*
Во рамки на дадената класа TextTransformer имплементирајте ги следните методи:

static string& periodsToQuestionMarks(string& s) - која ги заменува сите точки во стрингот со прашалници. 
static string& fixCommonPunctuationErrors(string& s) - која пред секое појавување на зборовите "but", "however" и "although" додава запирка. Обрнете внимание запирката да биде одвоена од зборот кој следува со празно место.
static int sumNumbersOccurringInString(string& s) - која ги издвојува сите појавувања на броеви во стрингот и ги собира. На пример: стрингот "12 10" има сума 22. 
Within the given class TextTransformer, implement the following methods:

static string& periodsToQuestionMarks(string& s) - which replaces all periods in the string with question marks. 
static string& fixCommonPunctuationErrors(string& s) - which adds a comma before each occurrence of the words "but", "however", and "although". Please note that the comma should be separated from the following word by a space.
static int sumNumbersOccurringInString(string& s) - which extracts all occurrences of numbers in the string and adds them up. Example: the string "12 10" has a sum of 22. 
For example:

Input	Result
What is the capital of France. It's Paris!
Who wrote the novel Moby Dick.
What year did World War II end.
How many planets are in our solar system.
What is the tallest mountain in the world.
Who is the author of the Harry Potter series.
What is the largest mammal in the world.
What is the chemical symbol for gold.
Who was the first person to step on the moon.
What is the main ingredient in guacamole.
END
What is the capital of France? It's Paris! SUM: 0
Who wrote the novel Moby Dick? SUM: 0
What year did World War II end? SUM: 0
How many planets are in our solar system? SUM: 0
What is the tallest mountain in the world? SUM: 0
Who is the author of the Harry Potter series? SUM: 0
What is the largest mammal in the world? SUM: 0
What is the chemical symbol for gold? SUM: 0
Who was the first person to step on the moon? SUM: 0
What is the main ingredient in guacamole? SUM: 0
END SUM: 0
Did you enjoy the concert however find the sound quality lacking
Are you going to the beach but bringing a jacket just in case it gets chilly
Did she finish her project on time although she had many obstacles along the way
Have you tried the new restaurant downtown but found the service slow
Do you like reading mystery novels however prefer fantasy books more
Were they able to fix the problem although it took longer than expected
Have you seen the latest movie but thought the plot was too predictable
Is he attending the meeting however feeling unprepared
Did you visit the museum but miss the special exhibit
Were you able to catch the bus although it was running late
END
Did you enjoy the concert, however find the sound quality lacking SUM: 0
Are you going to the beach, but bringing a jacket just in case it gets chilly SUM: 0
Did she finish her project on time, although she had many obstacles along the way SUM: 0
Have you tried the new restaurant downtown, but found the service slow SUM: 0
Do you like reading mystery novels, however prefer fantasy books more SUM: 0
Were they able to fix the problem, although it took longer than expected SUM: 0
Have you seen the latest movie, but thought the plot was too predictable SUM: 0
Is he attending the meeting, however feeling unprepared SUM: 0
Did you visit the museum, but miss the special exhibit SUM: 0
Were you able to catch the bus, although it was running late SUM: 0
END SUM: 0
15 27 12
3 8 11 6
45 2 19 10
7 23 15
10 6 14 3
30 4 18
9 33 22 7
18 5 29
12 28 36 21
20 17 13 9
END
15 27 12 SUM: 54
3 8 11 6 SUM: 28
45 2 19 10 SUM: 76
7 23 15 SUM: 45
10 6 14 3 SUM: 33
30 4 18 SUM: 52
9 33 22 7 SUM: 71
18 5 29 SUM: 52
12 28 36 21 SUM: 97
20 17 13 9 SUM: 59
END SUM: 0
*/

#include <iostream>
#include <cstring>
using namespace std;

class TextTransformer {
    static string& periodsToQuestionMarks(string& s) {
        //TODO: Заменете ги сите точки во стрингот со прашалници. Вратете го трансформираниот стринг.
        //TODO: Replace all periods in the string with question marks. Return the transformed string.
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '.')
                s[i] = '?';
        }
        return s;
    }
    static string& fixCommonPunctuationErrors(string& s) {
        //TODO: Пред секое појавување на зборовите 'however', 'but', 'although' додадете запирка проследена со празно место.
        //TODO: Add a comma followed by a space before each occurrence of the words 'however', 'but' and 'although'.
        string newS = "";
        string currWord = "";
        for(int i = 0; i < s.size(); i++){
            if(currWord == "however" || currWord == "although" || currWord == "but"){
                newS.erase(newS.size() - 1,1);
                newS += ", " + currWord + " ";
                currWord = "";
            }else if(s[i] == ' '){
                newS += currWord + s[i];
                currWord = "";
            }else{
                currWord+=s[i];
            }
        }
        if(currWord != "")
            newS += currWord;
        s = newS;
        return s;
    }
    static int sumNumbersOccurringInString(string& s) {
        //TODO: Издвојте ги сите појавувања на броеви во стрингот и соберете ги. Hint: може да ја користите ф-јата stoi()
        //TODO: Find all numbers in the string and sum them. Hint: you can use the stoi() function
        int sum = 0;
        string digit = "";
        
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                digit += s[i];
            }
            
            if(!isdigit(s[i]) && digit != ""){
                sum += stoi(digit);
                digit = "";
            }
        }
        if(digit != "")
            sum+=stoi(digit);
        return sum;
    }

    //НЕ ГО МЕНУВАЈТЕ КОДОТ ПОДОЛУ!
    //DON'T CHANGE ANY OF THE CODE BELOW!

public:
    static string& transformString(string& s) {
        periodsToQuestionMarks(s);
        fixCommonPunctuationErrors(s);
        string numbers = to_string(sumNumbersOccurringInString(s));
        return s.append(" SUM: ").append(numbers);
    }
};

int main() {
    string s;
    do {
        getline(cin, s);
        cout<<TextTransformer::transformString(s)<<endl;
    }
    while(s.find("END") == string::npos);
}